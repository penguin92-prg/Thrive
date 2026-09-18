#include "ball.hpp"

Ball balls[4];
Ball ballGlobal;

void Ball::globalize(Ball ball4[4]){
  int8_t ballIndex = -1;
  isExist = false;
  for(uint8_t i=0; i<4; i++){
    if(ball4[i].isExist){
      isExist = true;
      ballIndex = i;
      break;
    }
  }

  if(!isExist) return;

  dirPrev = dir;
  dir = ball4[ballIndex].dir;
  distance = ball4[ballIndex].distance;
  
  return;
}