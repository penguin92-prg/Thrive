#pragma once

#include <Arduino.h>

#include "matrix33.hpp"
#include "vec2.hpp"
#include "ball.hpp"

class Camera{
  private:
    // カメラ用シリアルポート
    inline static HardwareSerialIMXRT* const CAMERA_SERIAL[5] = {
      &Serial4, &Serial5, &Serial6, &Serial7, &Serial8
    };
    HardwareSerialIMXRT* camSerial = nullptr;

    // 受信データのデータ長（byte）
    static constexpr uint8_t STR_SIZE = 3;

    // カメラ番号
    uint8_t cameraNum;

    // カメラの焦点距離
    inline static const Vec2 cameraFocus = {230.0f, 240.0f};

    // カメラの中心座標
    inline static const Vec2 cameraCenter = {160.0f, 120.0f};

    // カメラの設置座標
    Vec3 cameraPos;

    // カメラの設置角度（deg）
    Vec3 cameraDeg = {-25.0f, 0.0f, 0.0f};

    // カメラからボールの向きの3次元単位ベクトル
    Vec3 ball3;

    Vec3 d1;
    Vec3 d2;
    Vec3 d;

    // コート上でのボールの2次元座標
    Vec2 court = {0.0f, 0.0f};

  public:
    explicit Camera(uint8_t num = 0) : cameraNum(num){}
    ~Camera() = default;

    Vec2 data;

    void init(int baudrate);
    void receive();
    void send();

    Ball calc();
};

extern Camera cameras[4];