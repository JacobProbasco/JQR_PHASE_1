#include <stdio.h>
#include <string.h>     // memset()
#include <ctype.h>      // toupper()

#define NUM_ARRAY_ELEM(a) (sizeof(a) / sizeof(*a))


int main (void){
    
    printf("Hello Battleship\n");
    
    // running == "program is running"
    int running = 1;
    
    while (running){
        // Set-Up New Game
        
// FIXME: Add recieve number of collumns and rows from server
        int coll, rows;
        coll = 10;          // (# of collumns on the board)
        rows = 10;          // (# of rows on the board)
        
        // Define board Size
        char board[coll][rows];
        
        memset(board, '*', sizeof(board));
        
        // Playing is incremented with wins until player quits program.
        
        int playing = 0;
        while (playing >= 0){
            
            int c, r, f;    // c == collumns; r == Rows; f == frame
            for(c = 0 ; c < coll ; c++)
                printf("+---");
            
            printf("+\n");
            
            // for each item in the first array (collumns)
            for( c = 0; c < coll; c++ ) {
                // for each array within that array (rows)
                for( r = 0; r < rows; r++ ) {
                    // Ensure the value is uppercase.
                    board[c][r] = toupper(board[c][r]);
                    printf("| %c ",board[c][r]);
                    /*
                    if (board[c][r] != "*" || "A" || "B" || "C"){
                        printf("| I ");
                    }
                    */
                }
                
                printf("|\n");
                
                for( f = 0; f < coll; f++){
                    printf("+---");
                    
                }
                
                printf("+\n");
                
            }
            return 0;
            
        }
    
    }

// FIXME: Add Board Display Function
    
// FIXME: Add save board file Function
    
// FIXME: Add ship-Validaiton Function
    
// FIXME: Add HIT or MISS function
    
    
}
