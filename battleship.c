#include <stdio.h>
#include <stdlib.h>     // malloc()
#include <string.h>     // memset()
#include <ctype.h>      // toupper()


void print_board(char **board, int coll, int rows);

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
        
    // dynamically set board size in memory
        
        // Allocate collumn space.
        char **board = malloc(coll * sizeof(char *));
        // Allocate total space to board
        board[0] = malloc(coll * rows * sizeof(char));
        
        // Initialize row arrays to ensure memory-usage is contiguous.
        for(int i = 1; i < coll; i++) {
            board[i] = board[0] + i * rows;
        }
        // Set default markers to water.
        memset(*board, '*', sizeof(board[0][0]) * coll * rows);
       
    // Begin round.
        // round is incremented with wins until player quits program.
        int round = 0;
        while (round >= 0){
            
            print_board(board, coll, rows);
            
            return 0;
            
        }
    
    }
    
// FIXME: Add save board file Function
    
// FIXME: Add ship-Validaiton Function
    
// FIXME: Add HIT or MISS function
    
    
}

//// FUNCTIONS ////

// Print board to screen.
void print_board(char **board, int coll, int rows){
    int c, r, f;    // c == collumns; r == Rows; f == frame
    for(c = 0 ; c < coll ; c++)
        printf("+---");
    
    printf("+\n");
    
    // for each item in the first array (collumns)
    for( c = 0; c < coll; c++ ) {
        // for each array within that array (rows)
        for( r = 0; r < rows; r++ ) {
            // Ensure the value is uppercase.
            printf("| %c ", board[c][r]);
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
}
