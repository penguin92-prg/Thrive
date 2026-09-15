#pragma once

#include <Arduino.h>
#include <stdint.h>

#include "vec2.hpp"

class Line{
  private:
    inline static constexpr uint8_t NUM_ANGEL = 32;
    inline static constexpr uint8_t NUM_SIDE = 2;

    inline static constexpr uint8_t PIN_THRESHOLD[4] = {2, 3, 4, 5};
    inline static constexpr uint8_t FRONTRIGHT = 0;
    inline static constexpr uint8_t BACKRIGHT = 1;
    inline static constexpr uint8_t BACKLEFT = 2;
    inline static constexpr uint8_t FRONTLEFT = 3;

    inline static constexpr uint8_t PIN_LED[2] = {25, 26};

    inline static constexpr int BAUDLATE = 115200;

    uint32_t m_signals_angel_raw = 0;
    uint8_t m_signals_side_raw = 0;

    
    public:
    Line() = default;
    ~Line() = default;
    
    bool signal[Line::NUM_ANGEL + Line::NUM_SIDE] = {};
    bool right = false;
    bool left = false;

    int num;
    int area;

    Vec2 vec;

    float dir;
    float distance;
    bool on = false;

    void init(int);
    void read();
    void calc();
    
    uint8_t threshold[4] = {100, 100, 100, 100};

    void setThreshold(uint8_t, uint8_t);
};

extern Line line;