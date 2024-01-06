file_read = "log_file"
address = input("Address")
Lock_Req = "Lock_Req"
Lock_Release = "Lock_Release"

filedata = ""
address_found = False
count = 0
Lock_Req_flag = False

with open(file_read, "r") as file:
   for line in file:
       if not address_found and (address in line):
           address_found = True

       if address_found:
           if not Lock_Req_flag and (Lock_Req in line):
               Lock_Req_flag = True

           if Lock_Req_flag:
               print(line)

           if Lock_Release in line:
               count += 1

           if count == 2:
               break
    

    


