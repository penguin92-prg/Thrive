# PCB要件定義

- メイン基板
- サブ基板
- MD基板
- キッカー基板
- ラインセンサ基板
- 電源基板
- ボール保持検知基板
- (中継基板)
- (スイッチ用基板)

## `メイン基板`
### 使用部品と機能
- [Teensy4.1](https://www.pjrc.com/store/teensy41.html)
  - MD基板へのモーター操作信号の出力
  - ロボット同士の相互位置取得用IRセンサの信号取得・処理
  - ドリブラー操作信号の出力
  - キッカー基板との通信(3.3V)
  - トグル/タクトスイッチ類の信号処理
  - ボール保持検知基板との通信(3.3V)
  - スイッチ基板との通信(3.3V)
  - BNO055モジュールとのI2C通信
  - M5UnitV (5x) とのUART通信
  - ATMEGA2560 on ラインセンサ基板 とのUART通信
  - ESP32C3 | 1 on サブ基板 とのUART通信(3.3V)
  - ESP32C3 | 2 on サブ基板 とのUART通信(3.3V)
- [BNO055 9軸センサモジュール](https://akizukidenshi.com/catalog/g/g116996/)
  - 基板に直付け(ピンソケット/ヘッダ)
  - I2Cは1KΩでPULLUPしておく
- [圧電ブザー | PKM13EPYH4000-A0](https://akizukidenshi.com/catalog/g/g104118/)
- ピンソケット
  - メイン基板への電源供給線
    - GND/5V/3.3V
  - ドリブラーとの通信線
- [BSS138](https://akizukidenshi.com/catalog/g/g104232)
  - ラインセンサとの通信のレベル変換(3.3v/5V)
- [XH 03B F](https://akizukidenshi.com/catalog/g/g112248/)
  - ※ ピンソケットが高さ的に合わない場合
  - メイン基板への電源供給線
- FPC
  - ラインセンサ基板との通信線
  - サブ基板との通信
  - スイッチ基板との通信



## `サブ基板`
### 使用部品と機能
- [ESP32C3 | 1](https://akizukidenshi.com/catalog/g/g117454/)
  - 超音波センサの信号取得・処理
  - NeoPixel操作信号の出力
  - ディスプレイとのI2C通信
  - 2機体間のBluetooth通信
- [ESP32C3 | 2](https://akizukidenshi.com/catalog/g/g117454/)
  - ?
- [SSD1306使用 ディスプレイモジュール](https://akizukidenshi.com/catalog/g/g112031/)
  - 機体UIとして使用
- [HC-SR04](https://akizukidenshi.com/catalog/g/g111009/)
  - コート壁との距離を測定
- FPC
  - メイン基板との電源/通信線
  


## `MD基板`
### 使用部品と機能
- [DRV8874](https://www.digikey.jp/ja/products/detail/texas-instruments/DRV8874PWPR/11502339)
  - モータードライバ素子
  - maxonモーターはLAP駆動で操作予定
- [XH 02B F](https://akizukidenshi.com/catalog/g/g112247/)
  - maxonモーター用配線
- [XT30 B M](https://akizukidenshi.com/catalog/g/g117951/)
  - MD基板への電源供給線



## `キッカー基板`
### 使用部品と機能
- [XL6009 module](https://www.aitendo.com/product/10257)
  - 11.1VDCを40VDC程度まで昇圧し両キッカー用高電圧電源の生成
- [XH 02B F](https://akizukidenshi.com/catalog/g/g112247/)
  - キッカー基板への電源供給線
  - ソレノイド用配線
- [C 2200μF 50V ルビコンPX](https://akizukidenshi.com/catalog/g/g113243/)
  - キッカー用電源の蓄電
  - 同時に逆起電圧の緩和



## `ラインセンサ基板`
### 使用部品と機能
- [ATMEGA2560-16AUR](https://akizukidenshi.com/catalog/g/g116567/)
  - 照度センサ素子の信号取得・処理
  - コンパレータの比較電圧の出力（PWMを平滑化）
  - メインマイコン(Teensy4.1)とのUART通信
  - (LEDの明るさの調整?)
- [NJL7502L](https://akizukidenshi.com/catalog/g/g102325/)
  - 反射光の照度計測
- [OSWT3166B](https://akizukidenshi.com/catalog/g/g100992/)
  - 地面を照らして反射光を生成
- [LM393DR2G](https://www.digikey.jp/ja/products/detail/onsemi/LM393DR2G/918527)
  - ATMEGAの平滑化された比較電圧と照度センサの値を比較



## `電源基板`
### 使用部品と機能
- [OKL-T/6-W12N-C](https://akizukidenshi.com/catalog/g/g106187/)
  - 電源電圧からロジック電圧(5V/3.3V)を生成
- [XH 02B F](https://akizukidenshi.com/catalog/g/g112247/)
  - キッカー基板への電源供給線
- [XH 03B F](https://akizukidenshi.com/catalog/g/g112248/)
  - メイン基板への電源供給線
- [XT30 B M](https://akizukidenshi.com/catalog/g/g117951/)
  - ラインセンサ基板への電源供給線
  - MD基板への電源供給線
- LiPoのコネクタ(VHコネクタ?)
  - 電源基板への電源供給線



## `ボール保持検知基板`
### 使用部品と機能
- [NJL7502L](https://akizukidenshi.com/catalog/g/g102325/)
  - ボールによる反射光の照度計測
- [OSWT3166B](https://akizukidenshi.com/catalog/g/g100992/)
  - ボールを照らして反射光を生成



## `(中継基板)`



## `(スイッチ用基板)`