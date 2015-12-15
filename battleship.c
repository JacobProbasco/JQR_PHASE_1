#include <stdio.h>
#include <stdlib.h>     // malloc()
#include <string.h>     // memset()
#include <ctype.h>      // toupper()


void print_board(char **board, int coll, int rows);

#define NUM_ARRAY_ELEM(a) (sizeof(a) / sizeof(*a))

typedef struct ship {
    char name[17];
    char mark_char[1];      // Character that the ship displays when printed.
    int ship_size[1];       // Amount of markers allocated to the ship.
    int coord[2];           // Location of ship. First num is Column, second is row
    int orient[1];          // 0 - Horizontal; 1 - Vertical
}ship;
        
int main (void){
    
    ship patrol = { "Patrol Boat", 'P', 2, { -1, -1}, {-1}};
    ship sub = { "Submarine", 'S', 2, { -1, -1}, {-1}};
    ship cruise = { "Cruiser", 'C', 3, { -1, -1}, {-1}};
    ship destroyer = { "Destroyer", 'D', 3, { -1, -1}, {-1}};
    ship battle = { "Battleship", 'B', 4, { -1, -1}, {-1}};
    ship aircraft = { "Aircraft Carrier", 'A', 5, { -1, -1}, {-1}};
    ship ships[6] = {patrol, sub, cruise, destroyer, battle, aircraft};
    
    srand((unsigned)time(NULL)); // seed srand()
    
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
        
    // Place ships randomly
        for (int i = 0; i < 7; i++){
            // Determine horizontal or vertical orientation of ship.
            *ships[i].orient = rand() % 2;

            if ( *ships[i].orient == 0){
                printf("DEBUG - %d is Horizontal: %d\n", i, *ships[i].orient);
                
            } else if (*ships[i].orient == 1){
                printf("DEBUG - %d is Vertical: %d\n", i, *ships[i].orient);
                
            } else {
                printf("DEBUG - %d is NOT WORKING: %d\n", i, *ships[i].orient);
            }
            
            
/*
            // Collin is a nice guy; he is also our collumn counter.
            for(int collin = 0; collin < coll; collin++) {
                for( j = 0; j < n; j++) {
                    ships_ptr[i][j] = rand()%2;
                    if( ships_ptr[i][j] == 1) {
                        count++;
                    }
                }
            }
 */
        }
       
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
