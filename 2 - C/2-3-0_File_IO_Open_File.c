#include <stdio.h>

int main (void){
    
    // Create a pointer for the file stream
    FILE *my_file;
    
    // Use fopen to assign my_file the pointer for the first byte in Ctester
    my_file = fopen("Ctester.txt", "r");
    
    if (my_file){
        
        printf("Print file using fgets(). Other functions can be used.\n");
        
        // arbitrary buffer size for fgets()
        char buffer[100];
        
        fgets(buffer, 255, my_file);
        printf("%s\n", buffer);
        
    }
    else {
        printf("Error reading file");
    }
    
    // close the file to free the resource for other processes
    fclose(my_file);
    
    return 0;
}