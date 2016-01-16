#include <stdio.h>
#include <ctype.h>

// No arg prints to screen
void no_arg(void);
// Command line to screen
void cmnd_print(int argc, char **argv);
// Return value to another function
int your_number(void);
// Pass argument to another function
void give_me_number(int the_number);
// Count down from 20 to 0
void final_countdown(int countdown);
// Exception handling (User input validation)
int handle_input(void);


/////////Program Start////////
int main (int argc, char **argv){
    
    // 2.5.0 - No-Arguments, but prints to screen
    no_arg();
    
    // 2.5.1 - Print arguments to screen if any are given
    if(argc > 1){
        cmnd_print(argc, argv);
    }
    
    // 2.5.1(2) - Returning a value to another function
    give_me_number(your_number());
    
    // 2.5.3 - Recursive function that counts down from 20 to 0
    printf("\n\nIt's the final Countdown!!!\n");
    final_countdown(20);
    
    printf("Liftoff!\n");
    
    // 2.6 - Manage user input
    handle_input();
    
}

/////////Functions////////

// No arg prints to screen
void no_arg(void){
    printf("This text is on the screen.\n\n");
}

// Command line to screen
void cmnd_print(int argc, char **argv){
    if(argc > 1){
        for(int i = 1; i <= argc; i++){
            printf("Argument %d is: %s\n", i, argv[i]);
        }
    }
}

// Return value to another function
int your_number(void){
    return 1;
}
void give_me_number(int the_number){
    printf("The number returned to give_me_number() is %d\n", the_number);
}

// Pass argument to another function
void pass_argument(int the_argument){
    give_me_number(the_argument);
}

// Count down from 20 to 0
void final_countdown(int countdown){
    if (countdown >= 0)
    {
        printf("Countdown: %d\n", countdown);
        final_countdown(--countdown);
    } 
}

// Exception handling (User input validation)
int handle_input(void){
    
    printf("\nType a letter.\n");
    
    while(1){
        char buffer = '\0';
        char letter = '\0';
        
        scanf(" %1c", &buffer);
        
        if(isalpha(buffer))
        {
            letter = buffer;
            
            // check for multiple characters entered
            buffer = getchar();
            
            if(buffer != '\n' && buffer != EOF)
            {
                printf("Enter only a single letter.\n");
                // seek to end of stdin so we don't process multiple characters
                while((buffer = getchar()) != '\n' && buffer != EOF);
                continue;
            }
            else 
            {
                printf("Good job; you typed a letter! It was '%c'.\n", letter);
                return 0;
            }
        }
        else
        {
            printf("ERROR. You must type a letter:\n");
            // seek to end of stdin so we don't process multiple characters if the first is incorrect
            while((buffer = getchar()) != '\n' && buffer != EOF);
        }
    }
    return 0;
}