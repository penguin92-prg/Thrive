#include "HardwareSerial.h"
#pragma once

#include <Arduino.h>

class Camera{
  private:
    static constexpr uint8_t STR_SIZE = 6;

  public:
    Camera() = default;
    ~Camera() = default;

    void init(int);
    void receive(HardwareSerialIMXRT&);
    void send(HardwareSerialIMXRT&);
};

extern Camera camera;