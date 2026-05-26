# PCB要件定義

### `寺田`
- MD基板
- キッカー基板
- ラインセンサ基板
- 電源基板

### `貝尻`
- メイン基板
- サブ基板
- (中継基板)

### `基板`
- ボール保持検知基板
- NeoPixel基板
- (ディスプレイ基板)
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
- [PinSocket](https://akizukidenshi.com/catalog/g/g105779/)
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



## `MD基板`
### 使用部品と機能
- [DRV8874](https://www.digikey.jp/ja/products/detail/texas-instruments/DRV8874PWPR/11502339)
  - モータードライバ素子
  - maxonモーターはLAP駆動で操作予定
  - 5コ搭載予定
    - 4コは駆動モータ
    - 1コは前ドリブラー (IG22/秋月モーター 1:1)
- [PinSocket | 1](https://akizukidenshi.com/catalog/g/g105779/)
  - 中継基板に接続
  - モーターが直接接続するのはMD基板ではなく中継基板
- [PinSocket | 2](https://akizukidenshi.com/catalog/g/g105779/)
  - 中継基板に接続
  - モーター駆動用信号をマイコンから伝達
- [XT30 B M](https://akizukidenshi.com/catalog/g/g117951/)
  - MD基板への電源供給線
  - 中継基板と接続



## `キッカー基板`
### 使用部品と機能
- [XL6009e1](https://www.aitendo.com/product/10307)
  - 11.1VDCを40VDC程度まで昇圧し両キッカー用高電圧電源の生成
- [PinSocket](https://akizukidenshi.com/catalog/g/g105779/)
  - 中継基板に接続
  - キッカー基板への電源供給線
- [XH 02B F](https://akizukidenshi.com/catalog/g/g112247/)
  - ソレノイドとの接続
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
  - THT
  - 照度センサは38コ
    - 円形に32コ（個別監視）
    - 左右のみ一回り大きい円形で3コずつ（並列でまとめて監視）
- [OSR5JA3Z74A](https://akizukidenshi.com/catalog/g/g111577/)
  - 地面を照らして反射光を生成
- [LM393DR2G](https://www.digikey.jp/ja/products/detail/onsemi/LM393DR2G/918527)
  - ATMEGAの平滑化された比較電圧と照度センサの値を比較
- [圧電ブザー | PKM13EPYH4000-A0](https://akizukidenshi.com/catalog/g/g104118/)