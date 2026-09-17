#pragma once

#include <Arduino.h>

#include "vec2.hpp"

class Camera{
  private:
    static constexpr uint8_t STR_SIZE = 3;

  public:
    Camera() = default;
    ~Camera() = default;

    Vec2 ball;

    void init(HardwareSerialIMXRT&, int);
    void receive(HardwareSerialIMXRT&);
    void send(HardwareSerialIMXRT&);
};

extern Camera camera1;
extern Camera camera2;
extern Camera camera3;
extern Camera camera4;
extern Camera camera5;