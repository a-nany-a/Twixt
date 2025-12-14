#include<stdio.h>
#include "handling.h"
#include "board.h"

movement get_player_move(){
movement m;
int r, c;
printf("Enter row and column (0-23), or -1 to quit:\n");
while(1){
        if(scanf("%d %d", &r, &c) != 2) {
            while (getchar() != '\n');
            printf("Invalid input! Enter two integers:\n");
            continue;
        }
        m.row = r;
        m.column = c;
        return m;
    }
}

int is_valid_move(gamestate *g, int r, int c) {

    if (!check_if_within_boundry(r, c)) {
        printf("The position is outside the board!\n");
        return 0;
    }

    if (!check_if_cellis_empty(g, r, c)) {
        printf("cell is already occupied!\n");
        return 0;
    }

    return 1;
}
