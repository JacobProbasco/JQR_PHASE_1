#!/usr/bin/python

print("1-0-0 - Basic Data Types\n")

integer = 255

float_ex = 12.12
str_ex = "Hello. I am a string."
character = "a"

print("{0} - That was an integer." .format(integer))
print("{0} - That was a float." .format(float_ex))

print("{0} - That was a string." .format(str_ex))
print("{0} - That was a character." .format(character))

hex_int = hex(integer)

print("{0} - Integer as hex." .format(hex_int))

byte_str = bytes(str_ex, 'utf8')

print("{0} - Byte String." .format(byte_str))
print("byte_str is {}", type(byte_str))