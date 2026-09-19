#pragma once

#include <Arduino.h>

#include "vec2.hpp"

// メモリ領域を共有できるunion構造体を使用して
// 自動的に4byteのfloatを1byteずつに分解
typedef union{
  float f;
  uint8_t bytes[4];
} FloatByte;

class Line{
  private:
    // エンジェルリングのセンサ個数
    // サイドのセンサ個数
    inline static constexpr uint8_t NUM_ANGEL = 32;
    inline static constexpr uint8_t NUM_SIDE = 2;

    // UART通信のデータサイズ（ヘッダ含む）
    inline static constexpr uint8_t STR_SIZE[] = {6, 9};

    // データヘッダ
    static constexpr uint8_t STR_HEADER = 0xAA;

    // エンジェルリングの生センサ値
    // サイドの生センサ値
    uint32_t m_signalAngelRaw = 0;
    uint8_t m_signalSideRaw = 0;

    // 反応しているセンサの個数
    int num = 0;

    // 反応しているカタマリの個数
    int area = 0;

    // 機体中心から白線への方向ベクトル（以下「方向ベクトル」と呼称）
    Vec2 vec;

    // 方向ベクトルの前回角度
    float dirPrev;

    // エンジェルリングの白線検知の有無
    // サイドの白線検知の有無
    // 前回白線検知の有無
    bool onAngel = false;
    bool onSide = false;
    bool onPrev = false;

  public:
    Line() = default;
    ~Line() = default;
    
    // センサ値配列（エンジェルリング・サイド両方）
    // 右サイドのセンサ値
    // 左サイドのセンサ値
    bool signal[Line::NUM_ANGEL + Line::NUM_SIDE] = {};
    bool right;
    bool left;
  
    // 方向ベクトルの角度
    // 方向ベクトルの大きさ（白線までの距離）
    float dir;
    float distance;

    // 白線検知の有無
    bool on = false;

    void init(int baudrate);
    void receive(uint8_t receivetype);
    void calc();

    static constexpr uint8_t ALL = 0;
    static constexpr uint8_t VECTOR = 1;
};

extern Line line;