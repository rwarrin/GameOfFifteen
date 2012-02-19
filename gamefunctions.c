#include "gamefunctions.h"

#include <stdio.h>
#include <unistd.h>

/*
 * Clears the screen
 */
void clear(void) {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/*
 * Greets the player
 */
void greet(void) {
    clear();
    printf("Welcome to the game of Fifteen!\n");
    usleep(200000);
}

/*
 * Initializes the game's board with tiles numbered through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void) {
    // fill in array
    int counter = (d * d) - 1;
    for(int row = 0; row < d; row++) {
        for(int column = 0; column < d; column++) {
            board[row][column] = counter--;
        }
    }

    // swap last two tiles if needed
    if(d % 2 == 0) {
        int temp = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = temp;
    }
}

/*
 * Prints the board
 */
void draw(void) {
    for(int row = 0; row < d; row++) {
        for(int column = 0; column < d; column++) {
            if(board[row][column] == 0)
                printf("[__]  ");
            else
                printf("[%2d]  ", board[row][column]);
        }
        printf("\n");
    }
}

/*
 * If tile borders empty space, moves tile and returns true, else
 * returns false
 */
int move(int tile) {
    // make sure the tile is valid
    if(tile < 1 || tile > (d * d) - 1)
        return 0;

    // find tiles coordinates
    int row = 0;
    int column = 0;
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            if(board[i][j] == tile) {
                row = i;
                column = j;
            }
        }
    }

    // check for open space, return false if blocked in
    int canmove = canMove(row, column);

    if(canmove) {
        // swap tiles
        // find 0 (open space)
        for(int i = 0; i < d; i++) {
            for(int j = 0; j < d; j++) {
                if(board[i][j] == 0) {  // find open tile
                    board[i][j] = board[row][column];
                }
            }
        }
        board[row][column] = 0;
    }

    return canmove;
}

/*
 * Returns true if game is won else false
 */
int won(void) {
    int counter = 0;
    for(int row = 0; row < d; row++) {
        for(int column = 0; column < d; column++) {
            if(board[row][column] != counter)
                return 0;
        }
    }
    return 1;
}

/*
 * Checks for open spaces around a tile returns true if so else false
 */
int canMove(int row, int column) {
    // check above
    if(row - 1 >= 0) {
        if(board[row - 1][column] == 0)
            return 1;
    }
    // check below
    if(row + 1 < d) {
        if(board[row + 1][column] == 0)
            return 1;
    }
    // check left
    if(column - 1 >= 0) {
        if(board[row][column - 1] == 0)
            return 1;
    }
    // check right
    if(column + 1 < d) {
        if(board[row][column + 1] == 0)
            return 1;
    }

    // can't move return false
    return 0;
}
