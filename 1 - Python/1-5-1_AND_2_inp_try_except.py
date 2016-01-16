#! /usr/bin/python

while True:
    try:
        int_exmp = int(input("Please enter an integer between 1 and 10 (2-9): "))
        # Verify the number is within the required range
        if int_exmp in range(1 , 10):
            print("GOOD. Your number was {}. Another?" .format(int_exmp))
        else:
            print("ERROR: Your number ({}) was not BETWEEN 1 and 10. Try again." .format(int_exmp))

    except (ValueError, NameError):
        print("ERROR: Your input must be an integer.")
        
    # The following is a bad practice, but catches all exceptions. It is better to handle the exceptions individually.
    except:
        print("ERROR: Your input must be an integer (All other errors)")