#include <stdio.h>
#include <math.h>

void print_values(int my_x, int my_y, long double my_total);

int main (void){
    
    int x = 10;
    int y = 2;
    long double total = 0;
    total = 0;
    printf("Initial:\n");
    print_values(x, y, total);
    
    // Multiplication
    printf("Multiplication (x*y):\n");
    total = (x * y);
    print_values(x, y, total);
    
    // Division
    printf("Division (x/y):\n");
    total = x / y;
    print_values(x, y, total);
    
    // Addition
    printf("Addition (x+y):\n");
    total = x + y;
    print_values(x, y, total);
    
    // Subtraction
    printf("Subtraction (x-y):\n");
    total = x - y;
    print_values(x, y, total);
    
    // Modulous
    printf("Modulous (x%%y):\n");
    total = x % y;
    print_values(x, y, total);
    
    // PEMDAS
    printf("PEMDAS:\n");

    total = powl(((6.0 + 7.0) * 4.0 / 6.0), (long double)2);
    // Alternatively take out powl and total = total * total;
    printf("Total: %Lf \n", total);
    
    return 0;
}

void print_values(int my_x, int my_y, long double my_total){
    printf("X is %d \nY is %d \n Total: %Lf \n", my_x, my_y, my_total);
}