#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#define _XOPEN_SOURCE 500

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
int move(int tile);
int won(void);
int canMove(int row, int column);

#endif  // GAMEFUNCTIONS_H
