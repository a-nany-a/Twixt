#ifndef GAME_H
#define GAME_H
#include "board.h"

int check_connections_is_valid(int x1,int y1,int x2,int y2);
int interval_overlapping(int a1,int a2,int b1,int b2);
int crosslink(int x1,int y1,int x2,int y2,int p1,int q1,int p2,int q2);
void add_connections(gamestate *g, int x, int y);
int check_if_redwins(gamestate *g);
int check_if_blackwins(gamestate *g);






#endif