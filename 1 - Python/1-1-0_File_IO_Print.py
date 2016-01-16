#! /usr/bin/python

print("1-1-0 - File I/O Print to Screen.\n")

# Open file 
# w - write (will overwrite file contents)
# a - Append to end of file
# r - Read the contents
# r+ - read and write contents

my_file = open('tester.txt', 'r')

print(my_file.read())

my_file.close()