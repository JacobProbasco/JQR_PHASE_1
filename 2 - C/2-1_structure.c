#include <stdio.h>

// Global scope variables are
///// available to the entire program;
///// placed outside of all functions(including main);
///// initialized by the system at runtime.

int global_int = 5;

//// 2.1.8 - Forward declarations ////
void two_one_four(int var);         // 2.1.4 - return void.
void two_one_five(int argument);    // 2.1.5 - value by argument
void two_one_six(int *reference);   // 2.1.6 - value by reference

// 2.1.1 - Entry point of my program.

int main (int argc, const char **argv){
    // argc is the count of arguments passed from the command line
    // argv points to the array of those arguments (including the file name)
    
    // local scope - stays inside a function; not accessable to outside functions
    
    int my_int = 1;
    
    // 2.2.1 - Declare an integer pointer
    int *my_ptr;
    int my_array[10];
    
    my_array + sizeof(int);
    my_array[1];
    
    my_array;
    
    // 2.2.3 and 2.2.4 - De-reference pointer; Assign an int-pointer
    my_ptr = &my_int;
    
    printf("My_int has the value of %d at the address of %p \n", *my_ptr, my_ptr);
    
    // 2.2.5 - An array is a contiguous collection of data pieces that are the same type while a pointer is a variable whose value is the memory address of another variable.
    
    // 2.2.6 - Create a dynamically sized array
    return 0;
}

void two_one_five(int argument){
    printf("The given argument is: %d\n", argument);
}

void two_one_six(int *reference){
    printf("The given reference is: %p\n", reference);
}

// 2.1.7 - Header file: can be used for function definitions and macros that are shared b
// 2.1.9 - Static: the var remains initialized while the program runs
//// In a function, this means that value remains persitent between the times it is called.
// 2.1.10- Extern: the var is declared but not defined (memory not allocated for this translation unit).
//// Basically a notice to the compiler that the value it stored elsewhere in a linked executable's translation unit.

// 2.2.0 - A pointer is a variable that holds the memory address to another variable.
