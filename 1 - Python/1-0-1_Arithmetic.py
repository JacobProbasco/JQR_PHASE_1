#!/usr/bin/python

print("1-0-1 - Arithmetic.\n")

x = 1
y = 2
total = 3
running = 1

# Print Current Values
def print_totals(x, y, total):
    print("x is {0} \ny is {1} \ntotal is {2}\n----\n" .format(x, y, total))

# Print starting Values
print("(Initial Values)")
print_totals(x, y, total)

print("(Multiplication) Total is x * y")

total = x*y

print_totals(x, y, total)

print("(Division) Make x 6 and y 3. Then total = x / y")

x = 6
y = 3
total = x/y

print_totals(x, y, total)

print("(Addition) With existing values, total is x + y")

total = x + y

print_totals(x, y, total)

print("(Subtraction) With existing values, total is x - y")

total = x - y

print_totals(x, y, total)

print("(Modulous) With existing values, total is x % y - the reaminder of x / y")

total = x % y

print_totals(x, y, total)