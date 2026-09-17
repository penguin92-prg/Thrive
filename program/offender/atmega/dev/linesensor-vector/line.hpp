#pragma once

#include <Arduino.h>
#include <stdint.h>

#include "vec2.hpp"

class Line{
  private:
    // エンジェルリングのセンサ個数
    // サイドのセンサ個数
    inline static constexpr uint8_t NUM_ANGEL = 32;
    inline static constexpr uint8_t NUM_SIDE = 2;

    // しきい値のPWM出力用ピン
    inline static constexpr uint8_t PIN_THRESHOLD[4] = {2, 3, 4, 5};

    // LED出力用ピン
    inline static constexpr uint8_t PIN_LED[2] = {25, 26};

    // エンジェルリングの生センサ値
    // サイドの生センサ値
    uint32_t m_signals_angel_raw = 0;
    uint8_t m_signals_side_raw = 0;

    
  public:
    // コンストラクタとデコンストラクタ
    Line() = default;
    ~Line() = default;
    
    // センサ値配列（エンジェルリング・サイド両方）
    // 右サイドのセンサ値
    // 左サイドのセンサ値
    bool signal[Line::NUM_ANGEL + Line::NUM_SIDE] = {};
    bool right = false;
    bool left = false;

    // 反応しているセンサの個数
    int num = 0;

    // 反応しているカタマリの個数
    int area = 0;

    // 機体中心から白線への方向ベクトル（以下「方向ベクトル」と呼称）
    Vec2 vec;

    // 方向ベクトルの角度
    // 方向ベクトルの大きさ（白線までの距離）
    float dir;
    float dirPrev;
    float distance;

    // エンジェルリングの白線検知の有無
    // サイドの白線検知の有無
    // 白線検知の有無
    bool onAngel = false;
    bool onSide = false;
    bool on = false;
    bool onPrev = false;

    void init(int);
    void read();
    void calc();
    
    // しきい値
    uint8_t threshold[4] = {100, 100, 100, 100};

    void setThreshold(uint8_t, uint8_t);
};

extern Line line;