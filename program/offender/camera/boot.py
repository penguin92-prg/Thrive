from machine import UART
from fpioa_manager import fm
import sensor, image, time
import math

fm.register(34,fm.fpioa.UART1_TX,force=True)
fm.register(35,fm.fpioa.UART1_RX,force=True)

uart = UART(UART.UART1, 115200, 8, 0, 0, timeout=1000, read_buf_len=4096)

send_list = [0,0,0]

orange_threshold = (30, 80, 20, 70, 20, 70)

#カメラを初期化
sensor.reset(dual_buff=True)
sensor.set_pixformat(sensor.RGB565) #カラー画像
sensor.set_framesize(sensor.QVGA) #320x240
sensor.skip_frames(time=2000)
clock = time.clock()

while True:
    clock.tick()
    img = sensor.snapshot()
    #色領域を検出
    blobs = img.find_blobs([orange_threshold], pixels_threshold=100, area_threshold=100, merge=True)
    #for b in blobs:
        ##画面に短形と座標を描画
        #x_center = b.cx()
        #y_center = b.cy()
        #img.draw_rectangle(b.rect())
        #img.draw_cross(x_center, y_center)
        #img.draw_string(x_center, y_center, "({}, {})".format(x_center, y_center))
    if blobs:

        b = max(blobs, key=lambda x:x.pixels())
        #中心座標を取得
        x_center = b.cx()
        y_center = b.cy()

        send_list[0] = x_center >> 8
        send_list[1] = x_center & 0xFF
        send_list[2] = y_center
        uart.write(bytearray(send_list))
    else:
        uart.write(bytearray([0,0,255]))
    time.sleep_ms(10);

