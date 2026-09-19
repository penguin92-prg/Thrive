#pragma once

#include <Arduino.h>
#include <stdint.h>

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

    // しきい値のPWM出力用ピン
    inline static constexpr uint8_t PIN_THRESHOLD[4] = {2, 3, 4, 5};

    // LED出力用ピン
    inline static constexpr uint8_t PIN_LED[2] = {25, 26};

    // エンジェルリングの生センサ値
    // サイドの生センサ値
    uint32_t m_signalAngelRaw = 0;
    uint8_t m_signalSideRaw = 0;

    // send()で送信するデータ長（byte）
    inline static constexpr uint8_t STR_SIZE[] = {6, 9};

    // UART通信のデータヘッダ
    static constexpr uint8_t STR_HEADER = 0xAA;

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
    // コンストラクタとデコンストラクタ
    Line() = default;
    ~Line() = default;
    
    // センサ値配列（エンジェルリング・サイド両方）
    // 右サイドのセンサ値
    // 左サイドのセンサ値
    bool signal[Line::NUM_ANGEL + Line::NUM_SIDE] = {};
    bool right = false;
    bool left = false;

    // 方向ベクトルの角度
    // 方向ベクトルの大きさ（白線までの距離）
    float dir;
    float distance;

    // 白線検知の有無
    bool on = false;

    void init(int baudrate);
    void read();
    void calc();
    
    // しきい値
    uint8_t threshold[4] = {100, 100, 100, 100};

    void setThreshold(uint8_t, uint8_t);

    // teensyとの通信
    static constexpr uint8_t ALL = 0;
    static constexpr uint8_t VECTOR = 1;
    void send(uint8_t sendtype);
};

extern Line line;