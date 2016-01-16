#include <stdio.h>

int main (void){
    
    int my_int = 12345;
    float my_float = 3.1415;
    double my_double = 3.1415926535897932384626433832795;
    char my_string = "I love to opine about pi and pie.";
    char my_char[1] = 'p';
    unsigned long my_long = 2147483647;
    
    printf("My int is: %d", my_int);
    printf("My float is: %f", my_float);
    printf("My double is: %f", my_double);
    printf("My string is: %s", my_string);
    printf("My character is: %c", my_char);
    printf("My (u)long is: %l", my_long);
    
    
    
}