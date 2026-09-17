from machine import UART
from board import board_info
from fpioa_manager import fm
import time
from Maix import GPIO
from modules import ws2812

class_ws2812 = ws2812(8, 1)

def Flash_LED():
    b = class_ws2812.set_led(0,(0,50,50))
    b = class_ws2812.display()
    time.sleep_ms(200)
    b = class_ws2812.set_led(0,(0,0,0)) # turn off
    b = class_ws2812.display()


# LEDピンの設定 (UnitVのオンボードLED: GPIO 12/13/14 等)
# 送信処理と同時にLEDをチカチカさせる
fm.register(34, fm.fpioa.UART2_TX, force=True)
fm.register(35, fm.fpioa.UART2_RX, force=True)

uart = UART(UART.UART2, 115200, 8, 0, 1, timeout=1000, read_buf_len=4096)

send_buf = bytearray(1)
count = 10

while True:
    send_buf[0] = count
    uart.write(send_buf)

    # LEDを点滅させる
    Flash_LED()

    count = (count + 1) if count < 200 else 10
    time.sleep_ms(200)