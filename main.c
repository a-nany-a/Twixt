#include <stdio.h>
#include "board.h"
#include "game.h"
#include "handling.h"

gamestate game;

int main(){
printf("\nCongratulations! you have been assigned the mighty Red color as your symbol,let the game begin!\n");
printf("\nHey! no pressure if you want to end or quit the game you are free to do so just type -1\n");

initialize(&game);
while(1){
printboard(&game);
if(game.currentplayer == redplayer)printf("it is red player's turn\n");
else printf("it is black player's turn\n");

movement mv= get_player_move();
if(mv.row == -1 || mv.column == -1) {
printf("Exiting game...\n");
break;
}
if(!is_valid_move(&game, mv.row, mv.column)) {
continue;   // Ask again
}
placement(&game, mv.row, mv.column);
add_connections(&game, mv.row, mv.column);
     if(game.currentplayer == redplayer){
     if(check_if_redwins(&game)){
                printboard(&game);
                printf("RED WINS!\n");
                break;
            }
        } 
     else{
     if(check_if_blackwins(&game)){
                printboard(&game);
                printf("BLACK WINS!\n");
                break;
            }
        }
     change_player(&game);
    }
return 0;
}

