#include<stdio.h>
#include "game.h"
#include "board.h"
int moves[8][2]={ //all possible distances
        { 2,  1},
        { 2, -1},
        { 1,  2},
        { 1, -2},
        {-2,  1},
        {-2, -1},
        {-1,  2},
        {-1, -2} };  
  
int check_connections_is_valid(int x1,int y1,int x2,int y2){
for (int i = 0; i < 8; i++) {
        int nx = x1 + moves[i][0];
        int ny = y1 + moves[i][1];
        if (nx == x2 && ny == y2)
            return 1;
    }
    return 0;
}

int interval_overlapping(int a1, int a2, int b1, int b2)//checks whether the projections of two line segments overlap on one axis, but without full containment
{
    if (a1 > a2){int t=a1; a1=a2; a2=t;}
    if (b1 > b2){int t=b1; b1=b2; b2=t;}
    int overlap = (a1 < b2) && (b1 < a2);
    int containA = (a1 <= b1 && a2 >= b2);
    int containB = (b1 <= a1 && b2 >= a2);
    return overlap && !containA && !containB;
}

int crosslink(int x1, int y1, int x2, int y2, int p1, int q1, int p2, int q2)
{if ((x1==p1 && y1==q1) || (x1==p2 && y1==q2) || (x2==p1 && y2==q1) || (x2==p2 && y2==q2))
return 0;
int inter_x = interval_overlapping(x1, x2, p1, p2);
int inter_y = interval_overlapping(y1, y2, q1, q2);
return inter_x && inter_y; // return 1 if crossing is detected
}

void add_connections(gamestate *g, int x, int y) { // implements autolinking
cellstate mycolor = g->board[x][y];
for (int i = 0; i < 8; i++) {
int nx = x + moves[i][0];
int ny = y + moves[i][1];

if (!check_if_within_boundry(nx, ny)) continue;
if (g->board[nx][ny] != mycolor) continue;
if (!check_connections_is_valid(x, y, nx, ny)) continue;
 int crossing = 0;
        for (int r = 0; r < BOARD_SIZE && !crossing; r++) {
        for (int c = 0; c < BOARD_SIZE && !crossing; c++) {
        for (int d = 0; d < 8; d++){
        if (g->conn.connected[r][c][d]) { //d is the index ofmoves array it is coonected to
                        int p1 = r;
                        int q1 = c;
                        int p2 = r + moves[d][0];
                        int q2 = c + moves[d][1];
                        if (crosslink(x, y, nx, ny, p1, q1, p2, q2)) {
                        crossing = 1;
                         break;
                        }
}
}
}
 }

if(crossing)continue;
g->conn.connected[x][y][i] = 1;
printf("%d %d is connected to %d %d\n",x,y,nx,ny);
for (int k = 0; k < 8; k++){ // make connection bidirectional
if(nx + moves[k][0] == x && ny + moves[k][1] == y) {
g->conn.connected[nx][ny][k] = 1;
break;
}
}
}
}

int check_if_redwins(gamestate *g) {
int dp[BOARD_SIZE][BOARD_SIZE]; //dp is 1 if there is a path to cell x,y from left using red coonections
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            dp[i][j] = 0;

int flag = 1;
for(int x = 0; x < BOARD_SIZE; x++) {
if (g->board[x][0] == redpin) {
dp[x][0] = 1;                       //starting node
}
}
while (flag) {
flag = 0;
for (int x = 0; x < BOARD_SIZE; x++) {    //flag matlab ,Did I discover any NEW reachable cell in this iteration?in the start, flag = 1 to enter the loop. Inside, you set flag = 0 and only turn it back to 1 when you discover a new reachable node.
for (int y = 0; y < BOARD_SIZE; y++) {
if (dp[x][y] == 1) {
for (int i = 0; i < 8; i++) {
if (g->conn.connected[x][y][i]) {

                            int nx = x + moves[i][0];
                            int ny = y + moves[i][1];

                            if (check_if_within_boundry(nx, ny)) {

                                if (dp[nx][ny] == 0) {
                                    dp[nx][ny] = 1;
                                    flag = 1;}
    }
    }
    }
    }
    }}
    }
    for (int x = 0; x < BOARD_SIZE; x++) {
        if (dp[x][BOARD_SIZE - 1] == 1) {
            return 1;
}
}

return 0; 
}


int check_if_blackwins(gamestate *g){
int dp[BOARD_SIZE][BOARD_SIZE];
for (int i = 0; i < BOARD_SIZE; i++)
    for (int j = 0; j < BOARD_SIZE; j++)
        dp[i][j] = 0;
int flag = 1;
for(int y = 0; y< BOARD_SIZE; y++){
        if(g->board[0][y]==blackpin){
        dp[0][y]=1;
        }
    }
while(flag){
flag= 0;
for(int x=0;x<BOARD_SIZE;x++){
for (int y=0;y<BOARD_SIZE;y++){
if(dp[x][y] == 1){
   for (int i=0;i<8;i++){
   if(g->conn.connected[x][y][i]){
   int nx = x + moves[i][0];
   int ny = y + moves[i][1];
if(check_if_within_boundry(nx,ny)){
   if(dp[nx][ny]==0){
   dp[nx][ny]=1;
flag=1;}
    }
    }
    }
    }
     }
    }
    }

for(int y =0;y<BOARD_SIZE;y++){
if(dp[BOARD_SIZE - 1][y]==1){
return 1;  // BLACK WINS
    }
    }
return 0;  // No winning
}
