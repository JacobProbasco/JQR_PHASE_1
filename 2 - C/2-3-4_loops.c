#include <stdio.h>
#include <ctype.h>

int main (void){
    
    /* For-Loops
    for(given; condition to test; action on given){
        // do this
    }
    */
    
    int counter = 0;
    while(counter){
        printf("This while loop will go on forever unless we do something about it.\n");
        
        for(int i = 0; i <= 10; i++){
            printf("I am the count. %d! AH! AH!\n", i);
            if(i == 10){
                // OK... Lets do something about it.
                counter = 0;
            }
        }
    }
    
    while(1){
        for(int i = 0; i <= 10; i++){
            if(i % 2){
                // Even numbers only please
                continue;
            }else if(i % 3){
                continue;
            }
            else{
                printf("This number is even: %d \n", i);
            }
        }
        // Yeah, one time was enough.
        break;
    }
    
    int do_while = 0;
    
    do{
        printf("This will be printed no matter what do_while equals.\n");
    }while(do_while);   // would loop if do_while were 1.
    
    int switch_it = 3;
    
    switch (switch_it)
    {
        case 1:
            printf("The number was 1");
            break;
        case 2:
            printf("The number was 2");
            break;
        case 3:
            printf("The number was 3");
            break;
        default:
            printf("The number is a number.");
            break;
    }
    
    
    
    
    return 0;
}