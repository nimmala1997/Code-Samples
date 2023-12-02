file_path = 'path/to/your/file.txt'
search_string = "lock"
next_search_string = ""

with open(file_path, 'r') as file:
    lines = file.readlines()
    found = False

    for index, line in enumerate(lines):
        if search_string in line:
            found = True
            target_line = index - 2  # Get the line 2 lines before the found string
            if target_line >= 0:
                next_search_string = lines[target_line].strip()
                break
            else:
                print("String '{}' found, but no 2nd line above it.".format(search_string))
    
    if not found:
        print("String '{}' not found in the file.".format(search_string))

if next_search_string:
    split_next_search = next_search_string.split('0x')  # Split the string
    lock_request_flag = False
    if len(split_next_search) > 1:
        extracted_string = split_next_search[1][:6]  # Extract first 6 characters after '0x'
        next_search_string = "next" + extracted_string  # Add "next" to the extracted string
    
        file_path = 'new_path'

        with open(file_path, 'r') as file:
            lines = file.readlines()
            found = False

            for line in lines:
                if next_search_string in line or found or lock_request_flag:
                    found = True
                    print(line)

            if not found:
                print("String '{}' not found in the file.".format(next_search_string))
    else:
        print("Could not extract 6 digits after '0x' from '{}'".format(next_search_string))
else:
    print("Not available.")