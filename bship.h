//
//  bship.h
//  JQR_PHASE_1
//
//  Created by Jacob Probasco on 12/16/15.
//  Copyright © 2015 jacobprobasco. All rights reserved.
//

#ifndef bship_h
#define bship_h

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

#endif /* bship_h */
