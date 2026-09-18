from machine import UART
from fpioa_manager import fm
import sensor, image, time

#==================================================
#UART設定
send_list = [0,0,0]
fm.register(34,fm.fpioa.UART1_TX,force=True)
fm.register(35,fm.fpioa.UART1_RX,force=True)
uart = UART(UART.UART1, 115200, 8, 0, 0, timeout=1000, read_buf_len=4096)
# UART(port, baudrate, data-length(bit), parity-bit, stop-bit, timeout(ms), read-buffer-length(byte))
#==================================================


#==================================================
#検出色しきい値設定（LAB色空間）
orange_threshold = (30, 80, 20, 70, 20, 70)
#==================================================

#==================================================
#カメラの初期化
sensor.reset(dual_buff=True)  #dual_buff=Trueでダブルバッファリングを有効化してフレームレート向上
sensor.set_pixformat(sensor.RGB565) #画像色フォーマットをRGB565に設定
sensor.set_framesize(sensor.QVGA) #画像解像度をQVGA（320x240）に設定
sensor.skip_frames(time=2000) #設定変更後2000ms間は露出やホワイトバランスの安定用にフレームをスキップして待機
#==================================================

while True:
    #==================================================
    #画像を撮影してimgに格納
    img = sensor.snapshot()

    #色領域を検出
    blobs = img.find_blobs([orange_threshold], pixels_threshold=100, area_threshold=100, merge=True)
    #==================================================

    #==================================================
    #画面に短形と座標を描画
    #for b in blobs:
        #x_center = b.cx()
        #y_center = b.cy()
        #img.draw_rectangle(b.rect())
        #img.draw_cross(x_center, y_center)
        #img.draw_string(x_center, y_center, "({}, {})".format(x_center, y_center))
    #==================================================

    #==================================================
    if blobs:
        #認識色のピクセル数が最多のblobを取得
        b = max(blobs, key=lambda x:x.pixels())

        #blobの中心座標を取得
        x_center = b.cx()
        y_center = b.cy()

        #中心X座標が0-319の範囲なので2byteに分けて格納
        send_list[0] = x_center >> 8
        send_list[1] = x_center & 0xFF

        #中心Y座標は0-239の範囲なので1byteで格納
        send_list[2] = y_center

        #UART通信で送信
        uart.write(bytearray(send_list))
    #==================================================

    #==================================================
    else:
        uart.write(bytearray([2,0,255]))
        #ball.x=512, ball.y=255として受信される
    #==================================================

    #データの送受信が安定しない場合は以下のコメントアウトを外すこと
    #time.sleep_ms(10);