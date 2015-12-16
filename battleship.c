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

void make_board(char ***board, int colls, int rows);
unsigned int rand_point(unsigned int max);
int choose_placement (ship **vessel, int board_width, int board_height, char ***board);

void print_board(char **board, int colls, int rows);
void clean_exit(int exit_type, char *board);

int main (int argc, char * argv[]){
    
    ship patrol = { "Patrol Boat", 'P', 2, { -1, -1}, -1};
    ship sub = { "Submarine", 'S', 2, { -1, -1}, -1};
    ship cruise = { "Cruiser", 'C', 3, { -1, -1}, -1};
    ship destroyer = { "Destroyer", 'D', 3, { -1, -1}, -1};
    ship battle = { "Battleship", 'B', 4, { -1, -1}, -1};
    ship aircraft = { "Aircraft Carrier", 'A', 5, { -1, -1}, -1};
    ship *ships[6] = { &patrol, &sub, &cruise, &destroyer, &battle, &aircraft };
    
    printf("Hello Battleship\n");
    // running == "program is running"
    int running = 1;
    int colls, rows;
    char **board;
    
    while (running){
        
        // FIXME: Add recieve number of collsumns and rows from server w/data validaiton
        colls = 15;         // (# of collumns on the board)
        rows = 15;          // (# of rows on the board)
        
        // Set-Up New Game
        make_board(&board, colls, rows);
        choose_placement(ships, (colls - 1), (rows - 1), &board);
        
        //// Begin round; incremented with wins until player or server quits.
        int round = 0;
        while (round >= 0){
            
            print_board(board, colls, rows);

            // Debug Return to keep round from looping.
            return 0;
        }
    }
    
    // FIXME: Add save board file Function
    
    // FIXME: Add HIT or MISS function
    
}

//// FUNCTIONS ////

// Set-Up Game Board

void make_board(char ***board, int colls, int rows){
    
    char **my_board;
    
    srand((unsigned)time(NULL)); // seed srand()
    
    // Dynamically set board size in memory
    /// Allocate collumn space.
    my_board = malloc(colls * sizeof(char *));
    /// Allocate total space to board
    my_board[0] = malloc(colls * rows * sizeof(char));
    
    // Initialize row arrays to ensure memory-usage is contiguous.
    for(int i = 1; i < colls; i++) {
        my_board[i] = my_board[0] + i * rows;
    }
    
    // Set default markers to water.
    memset(*my_board, '*', sizeof(my_board[0][0]) * colls * rows);
    
    *board = my_board;
    free(my_board);
}

// Determine a valid locaiton on the board from random.
int choose_placement (ship **ships, int board_width, int board_height, char ***board){
    
    char **my_board = *board;
    
    // Iterate through the list of ships and randomly place the ships in valid locations.
    for (int i = 0; i < 6; i++){
        
        bool location_found = false;
        
        // Pre-determined values
        ship *vessel = ships[i];

        // Assign left_right or up_down orientation (random)
        vessel->orient = rand() % 2;
        
        // TMP values
        int left_right;
        int up_down;
        
        // Set the ship to a valid place on the board.
        // If none can be found, return the error.
        switch (vessel->orient) {
                // Horizontal Ships
            case 0:
                
                while (location_found == false){
                    
                    // Generate a starting point that would place the ship inside the board.
                    left_right = rand_point(board_width - vessel->size);
                    // Generate a row number that is on the board.
                    up_down = rand_point(board_height);
                    
                    printf("///// DEBUG: %s //////\n///// [LR(0), UD(1)]: |%d|\n///// left_rig starting point: %d\n///// up_dwn start pt: %d\n", vessel->name, vessel->orient, left_right, up_down);
                    
                    // for the size of the ship
                    for (int i = 0; i < vessel->size; i++){
                        
                        // incrementally check that location for water.
                        // Collumn #        // Row #
                        if (my_board[left_right + i][up_down] != '*'){
                            break;  // If not, break back to while loop for new numbers.
                        }
                        
                        // if we reach the end of the loop, all spaces contain water. location is found.
                        if (i == (vessel->size - 1)){
                            location_found = true;
                            
                            for (int h = 0; h < vessel->size; h++){
                                // Place the the ship's char on the board in the place that corresponds to the established location of the ship.
                                my_board[left_right + h][up_down] = vessel->mark_char;
                            }
                            
                            *vessel->start_pt.left_rig = left_right;
                            *vessel->start_pt.up_dwn = up_down;
                            *ships = vessel;
                        }
                    }
                }break;
                
                // up_down Ships
            case 1:
                while (location_found == false){
                    
                    // Generate a starting point that would place the ship inside the board.
                    up_down = rand_point(board_height - vessel->size);
                    // Generate a collumn number that is on the board.
                    left_right = rand_point(board_width);
                    
                    printf("///// DEBUG: %s //////\n///// [LR(0), UD(1)]: |%d|\n///// left_rig starting point: %d\n///// up_dwn start pt: %d\n", vessel->name, vessel->orient, left_right, up_down);
                    
                    // for the size of the ship
                    for (int i = 0; i < vessel->size; i++){
                        // incrementally check along up_down axis for water. If not, break out for new numbers.
                        // Collumn #        // Row #
                        if (my_board[left_right][up_down +i] != '*'){
                            break;
                        }
                        
                        // Once we have found a valid location, set the start_ptinates for that ship and return success
                        if (i == (vessel->size - 1)){
                            
                            for (int v = 0; v < vessel->size; v++){
                                my_board[left_right][up_down + v] = vessel->mark_char;
                            }
                            
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
    
    }
    *board = my_board;
    return -1;
}

// Print board to screen.
void print_board(char **board, int colls, int rows){
    int c, r, f;    // c == collumns; r == Rows; f == frame
    for(c = 0 ; c < colls ; c++)
        printf("+---");
    
    printf("+\n");
    
    // for each item in the first array (collumns)
    for( c = 0; c < colls; c++ ) {
        // for each array within that array (rows)
        for( r = 0; r < rows; r++ ) {
            // Ensure the value is uppercase.
            printf("| %c ", board[c][r]);
        }
        
        printf("|\n");
        
        for( f = 0; f < colls; f++){
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