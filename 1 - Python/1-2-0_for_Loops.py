#!/usr/bin/python

print("1-2-0 - for-loop demonstration.\n")

x = 0
y = 2

print("For loops are used to repeat a task if a given statement is true.")

# Print Current Values
def print_values(x, y):
    print("y is {0} \nx is {1}" .format(y, x))

# Print starting Values
print("\n(Initial Values)")
print_values(x, y)

print("(Make x the value of (x + y) 20 times:)")

for bob in range(0, 20):
    x += y
    print_values(x, y)

print("--------------------------\nThey can also be used on arrays. For this string array we can use a for-loop to print each character on its own line:")

houdini = "Magic Trick"

print("\nThe current string is:")
print houdini

print("\nEach character on a new line:")
for characters in houdini:
    print characters