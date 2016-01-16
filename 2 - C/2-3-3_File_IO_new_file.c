#include <stdio.h>

int main (void){
    
    // Create a pointer for the file stream
    FILE *my_file;
    
    // Use fopen to assign my_file the pointer for the first byte in Ctester
    my_file = fopen("new_file.txt", "w+");
    
    if (my_file){     // Check that the file opened correctly
        
        printf("Write to file, truncated via w+.\n");
        
        fprintf(my_file, "This is my new file\n");

        // close the file to free the resource for other processes
        fclose(my_file);        
    }
    else {
        printf("Error reading file");
    }
    
    return 0;
}