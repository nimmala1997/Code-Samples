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

file_path = 'path/to/your/file.txt'
file_2_path = 'path/to/your/file_2.txt'
search_string_1 = 'independent_test'
search_string_2 = 'lock'
AddressLine = ""

found_independent = False

with open(file_path, 'r') as file:
    for line in file:
        if search_string_1 in line:
            found_independent = True
            print(line)
            break

    if found_independent:
        for line in file:  # Continue from where the first loop left off
            if search_string_2 in line:
                split_line = line.strip().split()
                print(split_line[1])
                search_string_3 = split_line[1]
                break

with open(file_2_path, 'r') as file_2:
    for file_2_line in file_2:
        if search_string_3 in file_2_line and "LOCK" in file_2_line:
            break

    for file_2_line in file_2:
        if "Mw" in file_2_line:
            AddressLine = file_2_line
            break

start_index = AddressLine.find("(mem)")

after_mem = string[start_index + len("(mem)"):].strip()
split_values = after_mem.split()

if split_values:
    extracted_value = split_values[0]
    print("Extracted value:", extracted_value)

extracted_value = extracted_value[:-2]
extracted_value = extracted_value.lstrip('0')

print("address_value", exextracted_value)

file3_path = 'path/to/your/file3.txt'

with open(file3_path, 'r') as file_3:
    for line in file_3:
        if extracted_value in line and "Buslock=1" in line:
            buslock_line = line
            value = buslock_line.split()[1];
            print("value", value)
            break

    for line in file_3:
        if value in line and "LOCK_REQUEST" in line:
            print(line)