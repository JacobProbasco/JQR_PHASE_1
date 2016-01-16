#include <stdio.h>
#include <stdlib.h>         // for malloc()

int main (void){
    // Create a pointer that malloc() can use to reference the memory it will allocate on the heep
    int *pointer;
    
    /* 
     Using malloc, reserve space on the heep for the number
     of items needed for our array (5 in this case). 
     Assign the address of that memory to the pointer.
     */

    pointer = (int *) malloc( sizeof(int) * 5 );
    
    // Check our work by populating the array with even numbers. Print that value
    for (int x = 0; x < 6; x++){
        pointer[x] = x * 2;
    }
    
    // Print each value to verify it was correctly assigned.
    // This can be included in the for-loop above, but I took it out to remove its relationship to the assignment itself.
    for (int x = 0; x < 6; x++){
        printf("The int at pointer [%d] is %d\n", x, pointer[x]);
    }
    
    // free-up the space allocated once we are finished using it.
    free(pointer);
    
    return 0;
}