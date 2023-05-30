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
