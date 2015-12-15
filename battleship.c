#include <stdio.h>
#include <stdlib.h>     // malloc()
#include <string.h>     // memset()
#include <ctype.h>      // toupper()
#include <time.h>       // seed for srand()
#include <stdbool.h>    // Adds typedef for bool

typedef struct ship {
    char name[17];
    char mark_char[1];          // Character that the ship displays when printed.
    unsigned int ship_size[1];  // Amount of markers allocated to the ship.
    struct coord {
        unsigned int horiz[1];               // Location of ship. First num is Column, second is row
        unsigned int verti[1];
    }coord;
    int orient[1];              // -1 - unset; 0 - Horizontal; 1 - Vertical
}ship;

void print_board(char **board, int coll, int rows);
unsigned int rand_point(unsigned int max);
int set_ship (ship *vessel, int board_width, int board_height, char **board);
void clean_exit(int exit_type, char *board);

#define NUM_ARRAY_ELEM(a) (sizeof(a) / sizeof(*a))
        
int main (void){
    
    ship patrol = { "Patrol Boat", 'P', 2, { -1, -1}, {-1}};
    ship sub = { "Submarine", 'S', 2, { -1, -1}, {-1}};
    ship cruise = { "Cruiser", 'C', 3, { -1, -1}, {-1}};
    ship destroyer = { "Destroyer", 'D', 3, { -1, -1}, {-1}};
    ship battle = { "Battleship", 'B', 4, { -1, -1}, {-1}};
    ship aircraft = { "Aircraft Carrier", 'A', 5, { -1, -1}, {-1}};
    ship *ships[6] = { &patrol, &sub, &cruise, &destroyer, &battle, &aircraft };
    
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
        
    // Dynamically set board size in memory
        
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
        
        // Iterate through the list of ships and randomly place the ships in valid locations.
        for (int i = 0; i < 6; i++){
            
            // Assign horizontal or vertical orientation (random)
            *ships[i]->orient = rand() % 2;
            
            // Set the ship to a valid place on the board. If none can be found, return the error.
            if (!set_ship(ships[i], (coll - 1), (rows-1), board)){
                
                clean_exit(1, *board);
                
            } else {
                
            };
            
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

// Provides a random number limited to the maximum passed.
unsigned int rand_point(unsigned int max) {
    int rando;
    
    // Minimum number must be 0 because battleship does not have negatives.
    // unsigned int min = 0;
    
    // Define the range
    const unsigned int range = 1 + max; // - min;
    
    // Divide the maximum random into segments that are smaller than the range
    const unsigned int segments = RAND_MAX / range;
    const unsigned int limit = segments * range;

    do
    {
        rando = rand();
    } while (rando >= limit);
    
    return (rando / segments);
}

// Determine a valid locaiton on the board from random.
int set_ship (ship *vessel, int board_width, int board_height, char **board){
    
    bool location_found = false;
    int orientation = *vessel->orient;
    int vessel_size = *vessel->ship_size;
    int horizontal;
    int vertical;
    
    switch (orientation) {
        // Horizontal Ships
        case 0:
            
            printf("DEBUG - Horizontal: %d\n", orientation);
            
            while (location_found == false){
                // Generate a starting point that would place the ship inside the board.
                horizontal = rand_point(board_width - vessel_size);
                printf("DEBUG - Random Horizontal Starting point is: %d\n", horizontal);
                
                // Generate a row number that is on the board.
                vertical = rand_point(board_height);
                printf("DEBUG - Random Vertical Starting point is: %d\n", vertical);

                // for the size of the ship
                for (int i = 0; i < vessel_size; i++){
                    // incrementally check that location for water. If not, break out for new numbers.
                                // Collumn #        // Row #
                    printf("DEBUG - HoriCheck #%d\n", i);
                    if ( board[horizontal + i][vertical] != '*'){
                        break;
                    }
                    
                    // if we reach the end of the loop, all spaces contain water. location is found.
                    if (i == (vessel_size - 1)){
                        location_found = true;
                    }
                    
                }
            }
            
            break;
            
        // Vertical Ships
        case 1:
            printf("DEBUG - VERTICAL: %d\n", orientation);

            while (location_found == false){
                // Generate a starting point that would place the ship inside the board.
                vertical = rand_point(board_height - vessel_size);
                printf("DEBUG - Random Vertical Starting point is: %d\n", vertical);
                
                // Generate a collumn number that is on the board.
                horizontal = rand_point(board_width);
                printf("DEBUG - Random Horizontal Starting point is: %d\n", horizontal);
                
                // for the size of the ship
                for (int i = 0; i < vessel_size; i++){
                    // incrementally check along vertical axis for water. If not, break out for new numbers.
                               // Collumn #        // Row #
                    printf("DEBUG - VertiCheck #%d\n", i);
                    if (board[horizontal][vertical +i] != '*'){
                        break;
                    }
                    
                    // if we reach the end of the loop, all spaces contain water. location is found.
                    if (i == (vessel_size - 1)){
                        location_found = true;
                    }
                    
                }
            } break;
            
        default:
            printf("DEBUG - ERROR: It is BROKEN!!!");
            return 1;
            break;
    }
    return -1;
}

void clean_exit(int exit_type, char *board){
    switch(exit_type){
        case 0:
            printf("Goodbye!"); break;
        case 1:
            printf("ERROR in Setting Ship. Exiting"); break;
        default:
            printf("Unknown ERROR. Exiting.");
    }
    free(board);
    exit(exit_type);
}