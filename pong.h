/* 

pong.h
par cynix (dark-s@evhr.net)

*/



#ifndef PONG_H
#define PONG_H



#define SCREEN_W 800
#define SCREEN_H 480

#define BAR_W 15
#define BAR_H 120

#define LINE_W 2

#define BALL_X 100
#define BALL_Y 100
#define BALL_SIZE 10
#define BALL_SPEED 5

#define SCORE_D 30


void resetBall(SDL_Rect *position,int *x,int *y);


#endif
