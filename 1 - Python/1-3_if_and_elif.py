#!/usr/bin/python

print("1-4-1 - Command Line print.\n")

x = 1

if x == 0:
    print "x is zero."
else:
    print "x is not zero"
    
# Start on one to prevent divide by zero.
for counter in range(1,21):
    print "FOR {}:" .format(counter)
    if 20 % counter == 0:
        print "{} is a factor of 20" .format(counter)
    elif 20 % counter == 1:
        print "{} is NOT a factor of 20. Remainder is 1" .format(counter)
    elif 20 % counter == 2:
        print "{} is NOT a factor of 20. Remainder is 2" .format(counter)
    else:
        print "{0} is NOT a factor of 20. Remainder is {1}" .format(counter, (20 % counter))

