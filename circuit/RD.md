# PCB要件定義


## `メイン基板`

### 使用部品
- [Teensy4.1](https://www.pjrc.com/store/teensy41.html)
- [BNO055 9軸センサモジュール](https://akizukidenshi.com/catalog/g/g116996/)
- [圧電ブザー | PKM13EPYH4000-A0](https://akizukidenshi.com/catalog/g/g104118/)

### 機能
#### Teensy
- MD基板へのモーター操作信号の出力
- BNO055を用いたyaw角の取得・処理
- ロボット同士の相互位置取得用IRセンサの信号取得・処理
- ドリブラー操作信号の出力
- トグル/タクトスイッチ類の信号処理
- M5UnitV (5x) との通信
- ATmega2560 on ラインセンサ基板 との通信
- ESP32C3① on サブ基板 との通信
- ESP32C3② on サブ基板 との通信

---

## `サブ基板`
### 使用部品
- [ESP32C3](https://akizukidenshi.com/catalog/g/g117454/)

### 機能
#### ESP32C3①
- ディスプレイとの通信（I2C）
- NeoPixel操作信号の出力
- 無線通信(?)

---

## `電源基板`

---

## `昇圧基板`

---

## `ラインセンサ基板`