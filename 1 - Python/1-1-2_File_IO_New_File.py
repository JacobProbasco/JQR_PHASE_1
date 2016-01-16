#! /usr/bin/python

print("1-1-1 - File I/O Create New File.\n")

# Create a new file called new_file.txt (w mode creates or replaces the file name provided)
my_file = open('new_file.txt', 'w')

my_file.write("No joke, I am new.")

my_file.close()