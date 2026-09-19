#include "line_atmega.hpp"

void setup() {
  line.init(115200);
}

void loop() {
  line.read();
  line.sendAll();
}