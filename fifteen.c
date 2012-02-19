/******************************************************************************
 * fifteen.c
 *
 * Rick W
 * 02/19/2012
 *
 * Usage: fifteen d
 *
 * where the boards dimensions are d x d
 * d must be in [DIM_MIN,DIM_MAX]
 *
 *****************************************************************************/

#include "gamefunctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // instructions
    greet();

    // check arguments
    if(argc != 2) {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // check valid dimensions
    d = atoi(argv[1]);
    if(d < DIM_MIN || d > DIM_MAX) {
        printf("Board must be between %d x %d and %d x %d.\n", DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // initialize the board
    init();

    // play the game until it is won
    while(1) {
        // clear the screen
        clear();

        // draw the board
        draw();

        // check for a win
        if(won()) {
            printf("FTW!\n");
            break;
        }

        // prompt for move
        int tile = 0;
        printf("Tile to move: ");
        scanf("%d", &tile);

        if(!move(tile)) {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation
        usleep(500000);
    }
    
    // exit
    return 0;
}
