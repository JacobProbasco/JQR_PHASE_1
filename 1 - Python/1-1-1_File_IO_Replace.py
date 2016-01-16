#! /usr/bin/python

print("1-1-1 - File I/O Replace File.\n")

# Open file 
# w - write (will overwrite file contents)
# a - Append to end of file
# r - Read the contents
# r+ - read and write contents

# Show inital file contents (read mode)
my_file = open('tester.txt', 'r')
# Print initial file contents
print "Before Write:"
print my_file.read()

# Change mode to write(and read). This replaces the file.
my_file = open('tester.txt', 'w+')
# Replace the File's contents
my_file.write("contents replaced")
my_file.seek(0)

# Go back to first byte in the file
# Print results
print("After Write: {0}" .format(my_file.read()))

my_file.close()