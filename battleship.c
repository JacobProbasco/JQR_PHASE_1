#include <stdio.h>
#include <stdlib.h>     // malloc()
#include <string.h>     // memset()
#include <ctype.h>      // toupper()
#include <time.h>       // seed for srand()
#include <stdbool.h>    // Adds typedef for bool

typedef struct ship {
    char name[17];
    char mark_char;          // Character that the ship displays when printed.
    unsigned int size;  // Amount of markers allocated to the ship.
    struct start_pt {
        unsigned int left_rig[1];               // Location of ship. First num is Column, second is row
        unsigned int up_dwn[1];
    }start_pt;
    int orient;              // -1 - unset; 0 - left_right; 1 - up_down
}ship;

void print_board(char **board, int coll, int rows);
unsigned int rand_point(unsigned int max);
int choose_placement (ship *vessel, int board_width, int board_height, char **board);
void clean_exit(int exit_type, char *board);

#define NUM_ARRAY_ELEM(a) (sizeof(a) / sizeof(*a))
        
int main (void){
    
    ship patrol = { "Patrol Boat", 'P', 2, { -1, -1}, -1};
    ship sub = { "Submarine", 'S', 2, { -1, -1}, -1};
    ship cruise = { "Cruiser", 'C', 3, { -1, -1}, -1};
    ship destroyer = { "Destroyer", 'D', 3, { -1, -1}, -1};
    ship battle = { "Battleship", 'B', 4, { -1, -1}, -1};
    ship aircraft = { "Aircraft Carrier", 'A', 5, { -1, -1}, -1};
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
        
        for (int i = 0; i < 6; i++){
            
            // Iterate through the list of ships and randomly place the ships in valid locations.
            ship *curr_ship = ships[i];

            // Assign left_right or up_down orientation (random)
            ships[i]->orient = rand() % 2;
            
            // Set the ship to a valid place on the board.
            // If none can be found, return the error.
            if (choose_placement(curr_ship, (coll - 1), (rows-1), board)){
                
                printf("///// DEBUG: %s final start_pt:\n///// (%d,%d) /////\n", curr_ship->name, *curr_ship->start_pt.left_rig, *curr_ship->start_pt.up_dwn);
                
                // After valid location found, incrementally place ship's character on the board in the appropriate places. If not, break out for new numbers.
                
                // Horizontal Ships
                if (curr_ship->orient == 0){
                    for (int h = 0; h < curr_ship->size; h++){
                        // Place the the ship's char on the board in the place that corresponds to the established location of the ship.
                        board[*curr_ship->start_pt.left_rig + h][*curr_ship->start_pt.up_dwn] = curr_ship->mark_char;
                    }
                }
                
                // Vertical ships
                if (curr_ship->orient == 1){
                    for (int v = 0; v < curr_ship->size; v++){
                        board[*curr_ship->start_pt.left_rig][*curr_ship->start_pt.up_dwn + v] = curr_ship->mark_char;
                    }
                }
            } else {
                clean_exit(1, *board);
            };
            
        }
       
//// Begin round.
//// round is incremented with wins until player quits program.
        int round = 0;
        while (round >= 0){
            
            print_board(board, coll, rows);

// Debug Return to keep round from looping.
            return 0;
            
        }
    
    }
    
// FIXME: Add save board file Function
    
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
int choose_placement (ship *vessel, int board_width, int board_height, char **board){
    
    bool location_found = false;
    unsigned int orientation = vessel->orient;
    int vessel_size = vessel->size;
    int left_right;
    int up_down;

    switch (orientation) {
            
        // Horizontal Ships
        case 0:
            
            while (location_found == false){
                
                // Generate a starting point that would place the ship inside the board.
                left_right = rand_point(board_width - vessel_size);
                // Generate a row number that is on the board.
                up_down = rand_point(board_height);
                
                printf("///// DEBUG: %s //////\n///// [LR(0), UD(1)]: |%d|\n///// left_rig starting point: %d\n///// up_dwn start pt: %d\n", vessel->name, orientation, left_right, up_down);
                
                // for the size of the ship
                for (int i = 0; i < vessel_size; i++){
                    
                    // incrementally check that location for water.
                                // Collumn #        // Row #
                    if (board[left_right + i][up_down] != '*'){
                        break;  // If not, break back to while loop for new numbers.
                    }
                    
                    // if we reach the end of the loop, all spaces contain water. location is found.
                    if (i == (vessel_size - 1)){
                        location_found = true;
                        *vessel->start_pt.left_rig = left_right;
                        *vessel->start_pt.up_dwn = up_down;
                    }
                }
            }break;
            
        // up_down Ships
        case 1:
            while (location_found == false){
                
                // Generate a starting point that would place the ship inside the board.
                up_down = rand_point(board_height - vessel_size);
                // Generate a collumn number that is on the board.
                left_right = rand_point(board_width);
                
                printf("///// DEBUG: %s //////\n///// [LR(0), UD(1)]: |%d|\n///// left_rig starting point: %d\n///// up_dwn start pt: %d\n", vessel->name, orientation, left_right, up_down);
                
                // for the size of the ship
                for (int i = 0; i < vessel_size; i++){
                    // incrementally check along up_down axis for water. If not, break out for new numbers.
                               // Collumn #        // Row #
                    if (board[left_right][up_down +i] != '*'){
                        break;
                    }
                    
                    // Once we have found a valid location, set the start_ptinates for that ship and return success
                    if (i == (vessel_size - 1)){
                        location_found = true;
                        *vessel->start_pt.left_rig = left_right;
                        *vessel->start_pt.up_dwn = up_down;
                    }
                }
            }break;
            
        default:
            // Technically, the program should loop and never hit this error.
            printf("An unknown error occured.\nA valid location was not found and the placement loop was unexpectedly broken.\n");
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