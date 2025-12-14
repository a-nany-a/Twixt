#ifndef BOARD_H
#define BOARD_H
#define BOARD_SIZE 24

typedef enum{
empty,
redpin,
blackpin
}cellstate;

typedef enum{
    redplayer,
    blackplayer
}player;

typedef struct {
    int row;
    int column;
} movement;

typedef struct {
int connected[BOARD_SIZE][BOARD_SIZE][8];
}connections;

typedef struct {
    cellstate board[BOARD_SIZE][BOARD_SIZE];
    player currentplayer;
    connections conn;
} gamestate;

void initialize(gamestate *ptr);
void printboard(gamestate *ptr);
int check_if_within_boundry(int row, int column); 
int check_if_cellis_empty(gamestate *ptr, int row, int column); 
void placement(gamestate *ptr, int row, int column);
void change_player(gamestate *ptr);


#endif