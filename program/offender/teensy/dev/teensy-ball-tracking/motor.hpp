#pragma once

#include <Arduino.h>

class Motor{
  private:
    // モーター数とPWM周波数（maxonは40kHzが目安）
    static constexpr uint8_t NUM = 4;
    static constexpr uint32_t FREQUENCY = 50000;

    // EN/PHピン
    static constexpr uint8_t PIN_EN = 6;
    static constexpr uint8_t PIN_PH[NUM] = {9, 10, 11, 12};

    // 回転方向の補正配列
    static constexpr int8_t DIR[NUM] = {1, -1, 1, 1};

    // 補正前の出力値と補正後（生）出力値
    int8_t motor[NUM] = {0};
    int8_t motorRaw[NUM] = {0};

    // 移動平均のキュー数
    static constexpr uint8_t QUEUE_SIZE = 24;
    int8_t queue[QUEUE_SIZE][NUM] = {};


  public:
    void init();
    void output();

    void calcAvr();

    void set(int8_t m0, int8_t m1, int8_t m2, int8_t m3);
    void setRaw(int8_t m0, int8_t m1, int8_t m2, int8_t m3);

    void setDeg(float deg, int8_t power);
};

extern Motor motor;