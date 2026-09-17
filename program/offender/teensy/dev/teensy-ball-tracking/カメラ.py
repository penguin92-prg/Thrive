import sensor, image, time
import math


#カメラを初期化
sensor.reset()
sensor.set_pixformat(sensor.RGB565) #カラー画像
sensor.set_framesize(sensor.QVGA) #320x240
sensor.skip_frames(time=2000)
clock = time.clock()

#カメラ番号
c_num = 0 #前から時計回りに０～３

#カメラの焦点距離
fx = 230 #多分230
fy = 230 #多分240

#カメラの中心座標
c_cx = 160
c_cy = 120

#カメラの設置座標(m)
c_x = 0.05*math.sin(c_num*math.pi/2)
c_y = 0.11 
c_z = 0.05*math.cos(c_num*math.pi/2)

#カメラの設置角度(°)
c_degx = -25
c_degy = 90 * c_num
c_degz = 0

#[L_min, L_max, A_min, A_max, B_min, B_max]
orange_threshold = (30, 80, 20, 70, 20, 70)

#x軸方向の回転行列
def rot_x(c_degx):
    c = math.cos(c_degx/180*3.14)
    s = math.sin(c_degx/180*3.14)
    return [[1,0,0],[0,c,-s],[0,s,c]]

#y軸方向の回転行列
def rot_y(c_degy):
    c = math.cos(c_degy/180*3.14)
    s = math.sin(c_degy/180*3.14)
    return [[c,0,s],[0,1,0],[-s,0,c]]

#z軸方向の回転行列
def rot_z(c_degz):
    c = math.cos(c_degz/180*3.14)
    s = math.sin(c_degz/180*3.14)
    return [[c,-s,0],[s,c,0],[0,0,1]]

#行列の積
def mat_vec_mul(M, v):
    return [
        M[0][0]*v[0] + M[0][1]*v[1] + M[0][2]*v[2],
        M[1][0]*v[0] + M[1][1]*v[1] + M[1][2]*v[2],
        M[2][0]*v[0] + M[2][1]*v[1] + M[2][2]*v[2]
    ]

while True:
    clock.tick()
    img = sensor.snapshot()

    #色領域を検出
    blobs = img.find_blobs([orange_threshold], pixels_threshold=100, area_threshold=100, merge=True)

    for b in blobs:
        #中心座標を取得
        x_center = b.cx()
        y_center = b.cy()
        
        #画面に短形と座標を描画
        img.draw_rectangle(b.rect())
        img.draw_cross(x_center, y_center)
        img.draw_string(x_center, y_center, "({}, {})".format(x_center, y_center))

        #座標をシリアル出力
        #print(f"{x_center},{y_center}")
    if blobs:
        vx = x_center - c_cx #カメラの中心と物体の中心のx座標の差分
        vy = y_center - c_cy #カメラの中心と物体の中心のy座標の差分
        vz = fx

        #正規化
        norm = math.sqrt(vx*vx + vy*vy + vz*vz)
        vx /= norm
        vy /= norm
        vz /= norm
        d_camera = [vx, vy, vz]

        #回転行列
        R = rot_y(c_degy)
        R2 = rot_x(c_degx)
        R3 = rot_z(c_degz)
        d1 = mat_vec_mul(R3, d_camera)
        d2 = mat_vec_mul(R2, d1)
        d_robot = mat_vec_mul(R, d2)

        #コート上でのボールの座標
        t = c_y / d_robot[1]
        X = c_x + d_robot[0] * t
        Y = c_z + d_robot[2] * t
        
        #ボールの角度
        deg = math.atan2(Y, X)
        deg = deg/3.14*180 
        
        #print("Ball position: X={:.2f} m, Y={:.2f} m".format(X, Y))
        #print(deg)
    else:
        print("ボールなし")