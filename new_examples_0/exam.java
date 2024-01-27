public class DNTransactionListener extends TransactionListener {
    // Declare a private static final logger variable for logging
    private static final Logger LOGGER= LoggerFactory.INSTANCE.getLogger(DNTransactionListener.class);
    
    // Declare a private variable to store the performance logger flag
    private String performanceLoggerFlag;

    // Declare a private static variable to track if the clock service has failed
    private static boolean onClockFails = false;
  
    // Create a static method to return the value of onClockFails
    public static boolean isOnClockFails() {
        return onClockFails;
    }

    // Create a static method to set the value of onClockFails
    public static void setOnClockFails (boolean onClockFails) { 
        DNTransactionListener.onClockFails - onClockFails;
    }

    // Annotate the constructor with @Autowired and take in a single parameter with a default value
    @Autowired
    public DNTransactionListener(@Value("${performanceLogger.flag:false}") String flag) {
        this.performanceLoggerFlag flag;
    }
    // Annotate another variable with @Autowired
    @Autowired
    TransactionFilter transactionFilter;

    // Annotate a method with @JmsListener to listen for messages on a specific destination
    @JmsListener(destination = "${guardian4.dn.authtran}", containerFactory = "defaultJmsListenerContainerFactoryDN")


    public void onMessage(Message message) throws JMSException {
        try {
            // Create a PerformanceTimer object
            PerformanceTimer timer = getTimerObject();
            
            // Create a requestId variable with a random UUID value
            String requestId = UUID.randomUUID().toString();
            
            // Set the requestId in the ThreadLocalObjectStorage
            ThreadLocalObjectStorage.setRequestId(requestId);
            
            // Check if the message is a TextMessage
            if (message instanceof TextMessage) {
                TextMessage textMessage = (TextMessage) message;
                LOGGER.debug("DNTransactionListner Received Messages {}");
                
                // Get the raw transaction data from the message
                String rawTransaction = textMessage.getText();
                
                // Call the parseTxnLength method with the raw transaction data
                parseTxnLength(rawTransaction);
                
                // Call the parseTxnData method with the raw transaction data
                TransactionDTO transactionData = parseTxnData(rawTransaction);
                
                // Log performance information
                printPerformanceLogs(requestId, timer, "A DN. Parse Transaction Data");
                
                // Create another PerformanceTimer object
                PerformanceTimer timer2 = getTimerObject();
                
                // Set the IIN number in the transactionData object
                transactionData.setIinNumber(findIINNumberFromPAN(transactionData.getTokenizedPan(), TransactionConstants.NETWORK_TYPE_DN));
                
                // Call the tokenizePan method with the requestId, transactionData, and timer2
                tokenizePan(requestId, transactionData, timer2);
                
                // Create another PerformanceTimer object
                PerformanceTimer timer3 = getTimerObject();
                
                // Call the populateReferenceData method with the transactionData
                populateReferenceData
				// Set the network code in the transactionData object
                transactionData.setNetworkCde(TransactionConstants.NETWORK_TYPE_DN);

				// Log performance information
                printPerformanceLogs(requestId, timer3, "C DN. Populate Reference Data");
            
                // Check if the transaction should be filtered
                if(!transactionFilter.txnFilter(transactionData)){
                // If not, call the processNonProvisionedTransaction method
                processNonProvisionedTransaction(requestId, timer, rawTransaction, transactionData);
                } 
				else {
                // If it should be filtered, log a warning message
                LOGGER.warn("UnSupported Message received from Switch, Message is Not a Text message: ");
            }
            
            // Log performance information
            printPerformanceLogs(requestId, dnTimer, "N DN. DN Transaction Processing");
        } 
        // Catch PlatformSystemException
        catch (PlatformSystemException ex) {
            // Check the exception's status code
            if ((ServiceManagerStatusCode.IIN_RANGE_NOT_FOUND.getGuardianStatusCode()).equals(ex.getStatusCodes().get(0).getKey().getGuardianStatusCode())
            || (ServiceManagerStatusCode.INVALID_ISSUER_ID.getGuardianStatusCode()).equals(ex.getStatusCodes().get(0).getKey().getGuardianStatusCode())
            || (ServiceManagerStatusCode.INVALID_CURRENCY_CODE.getGuardianStatusCode()).equals(ex.getStatusCodes().get(0).getKey().getGuardianStatusCode())) {
                // Log an error message with "Guardian 4.0 Known Error" prepended
                LOGGER.error("Guardian 4.0 Known Error - Transaction Processing DN: {}", ex);
            } else {
                // Log an error message with "Guardian 4.0 Unknown Error" prepended
                LOGGER.error("Guardian 4.0 Unknown Error - Transaction Processing DN: {}", ex);
            }
            // Throw a new JMSException with the exception message
            throw new JMSException(ex.getMessage());
        }
    }
}

// Private method to tokenize a PAN number
private void tokenizePan(String requestId, TransactionDTO transactionData, PerformanceTimer timer2) 
 throws JMSException {
    try {
        // Tokenize the PAN number
        transactionData.setTokenizedPan(tokenize(transactionData.getTokenizedPan(), TransactionConstants.NETWORK_TYPE_DN));
        
        // Log performance information
        printPerformanceLogs(requestId, timer2, "B DN. Tokenize PAN");
    } 
    // Catch PlatformSystemException
    catch (PlatformSystemException e) {
        // Log an error message that the clock service has failed
        LOGGER.error("Guardian 4.0 Known Error Transaction Processing DN: Clock service failed");
        
        // Set the onClockFails variable to true
        setCloakFailure();
        
        // Throw a new JMSException with the exception message
        throw new JMSException(e.getMessage());
    }
    // Catch any other exception
    catch (Exception e) {
        // Log an error message that the clock service// Log an error message that the clock service has failed 
      LOGGER.error("Guardian 4.0 Unknown Error Transaction Processing DN: Clock service failed");
        // Set the onClockFails variable to true
        setCloakFailure();
        
        // Throw a new JMSException with the exception message
        throw new JMSException(e.getMessage());
    }
}

// Private static synchronized method to set the onClockFails variable to true

---
private static synchronized void setCloakFailure() {
    setOnClockFails(true);
}

private void processNonProvisionedTransaction(String requestId, PerformanceTimer timer, String rawTransaction, TransactionDTO transactionData) {
    // Set the transaction processed status to "not processed"
    transactionData.setTransactionProcessed(TransactionConstants.NOT_PROCESSED);
    // Set the received timestamp for the transaction
    transactionData.setReceivedTms(StringUtil.buildTimestampWithMillis());
    // Parse the secure indicator from the raw transaction data
    parseSecureIndicator(rawTransaction, transactionData);
    // Check if the issuer ID is not equal to the one to be ignored
    if(!TransactionConstants.DN_ISSUER_ID_TO_IGNORE.equals (transactionData.getIssuerId())){
        // Create a new PerformanceTimer object
        PerformanceTimer timer4 = getTimerObject();
        // Populate network transaction data
        TransactionDataIndex transactionDataIndex = populateNetworkTransactionData (transactionData);
        // Store the transaction data in the index
        transactionDataIndex = storeTxnDataInIndex(transactionDataIndex);
        // Set the transaction ID in the transactionData object
        transactionData.setId(transactionDataIndex.getId());
        // Log performance information
        printPerformanceLogs (requestId, timer4, "D DN. Store Transaction to Elastic");
        // Log performance information
        timer.logPerformance("DN Transaction storeTxnDataInIndex");
        // Process the transaction
        processTransaction(transactionData, TransactionConstants.NETWORK_TYPE_DN, requestId);
        // Log information that the DNTransactionListner execution is done
        LOGGER.info("DNTransactionListner execution done transactionId: {}", transactionData.getId());
    } else {
        // Log a debug message that the transaction is being skipped
        LOGGER.debug("DNTransactionListner skipped processing as received Issuer Id 10097 {}");
        // Store the ignored transaction
        storeIgnoreTransactions (requestId, transactionData, timer);
    }
}

private void parseSecureIndicator(String rawTransaction, TransactionDTO transactionData) {
    // Find the ecommTranInd field in the raw transaction data
    String ecommTranInd = DNTransactionMessageFields.ECOMM_TRAN_IND.find(rawTransaction);
    // Find the chipCrdRltdDataVal field in the raw transaction data
    String chipCrdRltdDataVal = DNTransactionMessageFields.CHIP_CRD_RLTD_DATA_VAL.find(rawTransaction);
    // Set the ecommTranInd and chipCrdRltdDataVal in the transactionData object
    transactionData.setEcommTranInd (ecommTranInd);
    transactionData.setChipCrdRltdDataVal(chipCrdRltdDataVal);
    // Check if the ecommTranInd is equal to 4 or 5, or if the chipCrdRltdDataVal is equal to "Y"
    if((ecommTranInd.equals(TransactionConstants.ECOMM_TRAN_IND_4) || ecommTranInd.equals(TransactionConstants.ECOMM_TRAN_IND_5))||chipCrdRltdDataVal.equals(TransactionConstants.CHIP_CRD_VALIDTR_Y)){
    //Set the secure indicator in the transactionData object to "Y"
    transactionData.setSecureInd (TransactionConstants.SECURE_IND_Y);
    } 
    else {
    // Set the secure indicator in the transactionData object to "N"
     transactionData.setSecureInd(TransactionConstants.SECURE_IND_N);
    }

}

private void storeIgnoreTransactions (String requestId, TransactionDTO transactionData, PerformanceTimer timer) {
    // Create a new PerformanceTimer object
    PerformanceTimer timer4 = getTimerObject();
    // Populate network transaction ignore data
    TransactionIgnoreIndex transactionIgnoreIndex = populateNetworkTransactionIgnoreData(transactionData);
    // Store the ignored transaction in the index
    storeTxnDataInIgnoreIndex(transactionIgnoreIndex);
    // Log performance information
    if(timer4 != null)
        printPerformanceLogs (requestId, timer4, " D. Store Ignored Transaction to Elastic");
    // Log performance information
    timer.logPerformance ("DN Ignored Transaction storeTxnDataInIgnoreIndex");
    // Log information that the transaction has been stored in the ignore index
    LOGGER.info("ONTransactionListner stored transaction in Ignore index: {}", transactionIgnoreIndex.getId());
}


private PerformanceTimer getTimerObject() {
	// Check if the performance logger flag is set to true
    if (TransactionConstants.TRUE.equals (performanceLoggerFlag))
      // Return a new PerformanceTimer object
      return new PerformanceTimer();
    else
      // Return null
      return null;
}

private void printPerformanceLogs (String requestId, PerformanceTimer timer, String message) {
	// Check if the performance logger flag is set to true and the timer object is not null
    if (TransactionConstants.TRUE.equals (performanceLoggerFlag) && timer != null) {
      // Log performance information
      LOGGER.logPerformance(String.format(TransactionConstants.PERFORMANCE_LOG_STRING, requestId, TransactionConstants.NETWORK_TYPE_DN,"-", message, timer.logPerformance(message)));
    }
}

@Override
public void parseTxnLength (String payload) {
	// Check if the payload length is less than the total size of the DNTransactionMessageFields
    if (payload.length() < DNTransactionMessageFields.totalSize()) {
      // Log an error message
      LOGGER.error("Incoming transaction message is invalid {}");
      // Throw a PlatformSystemException with the INVALID_ON_TRANSACTION_MESSAGE status code
      throw new PlatformSystemException (ServiceManagerStatusCode.INVALID_ON_TRANSACTION_MESSAGE.getMessage(), ServiceManagerStatusCode.INVALID_ON_TRANSACTION_MESSAGE);
    }
}


