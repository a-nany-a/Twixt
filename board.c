#include <stdio.h>
#include "board.h"


void initialize(gamestate *ptr){for(int i=0;i<24;i++){
    for(int j=0;j<24;j++){
       ptr->board[i][j]=empty;
    }
}    
ptr->currentplayer =redplayer;
}

void printboard(gamestate *ptr){
  for(int i=0;i<24;i++){
    for(int j=0;j<24;j++){  
 if(ptr->board[i][j]==empty)printf(". ");//acc to cellstate
else if(ptr->board[i][j]==redpin)printf("R "); 
else if(ptr->board[i][j]==blackpin)printf("B ");  
    }
    printf("\n");
}
}

int check_if_within_boundry(int row, int column){
if(0<=row && row<BOARD_SIZE && 0<=column && column<BOARD_SIZE)return 1;
else return 0;
}

int check_if_cellis_empty(gamestate *ptr, int row, int col){
if(ptr->board[row][col]==empty)return 1;
else return 0;
}

void placement(gamestate *ptr, int row, int column){
if(ptr->currentplayer==redplayer)ptr->board[row][column]=redpin;
else ptr->board[row][column]=blackpin;
}

void change_player(gamestate *ptr){
if(ptr->currentplayer==redplayer)ptr->currentplayer=blackplayer;
else ptr->currentplayer=redplayer;
}

