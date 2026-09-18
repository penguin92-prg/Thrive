#pragma once

#include <Arduino.h>

class Ball{
  public:
    int16_t dir;
    int16_t dirPrev;

    uint16_t distance;

    bool isExist;

    void globalize(Ball ball4[4]);
};

extern Ball balls[4];
extern Ball ballGlobal;