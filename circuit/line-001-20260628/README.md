# ラインセンサ基板 001

ラインセンサ基板 ver.001のREADME

## 設計者
- @penguin92-prg
- @ryo-robot14

## ピンアサイン

## 使用上の注意

## 使用部品

|No.|Ref.|Name|QTY|Assembled By|Note|URL|
|---|---|---|---|---|---|---|
|001|D1~40|OSR5JA3Z74A|40|OWN|赤色LED|[秋月電子](https://akizukidenshi.com/catalog/g/g111577/)|
|002|R41~72,77~80|Resister 10kΩ|34|JLCPCB|LED用75Ω|[JLCPCB](https://jlcpcb.com/partdetail/21350-0805W8F750JT5E_SMTonly/C20638)|
|003|Q1~40|NJL7502L|40|OWN|フォトトランジスタ|[秋月電子](https://akizukidenshi.com/catalog/g/g102325/)|
|004|R1~32,38,40|Resister 10kΩ|34|JLCPCB|プルダウン用100kΩ|[JLCPCB](https://jlcpcb.com/partdetail/18102-0805W8F1002T5E/C17414)|
|005|U1~16,19,20|LM339DR|20|JLCPCB|コンパレータ|[JLCPCB](https://jlcpcb.com/partdetail/TexasInstruments-LM393DR/C67470)|
|006|C1~16,23,24|Capacitor 100nF|20|JLCPCB|コンパレータ用バイパスコンデンサ|[JLCPCB](https://jlcpcb.com/partdetail/YAGEO-CC0805KRX7R9BB104/C49678)|
|007|C21,22,26,27|Capacitor 10uF|4|JLCPCB|PWM平滑化用コンデンサ|[JLCPCB](https://jlcpcb.com/partdetail/439567-GRM21BR61H106KE43L/C440198)|
|008|R83,84,87,88|Resister 1kΩ|4|JLCPCB|PWM平滑化用抵抗器|[JLCPCB](https://jlcpcb.com/partdetail/18201-0805W8F1001T5E/C17513)|
|009|U17|ATMega2560-16A|1|OWN||[秋月電子](https://akizukidenshi.com/catalog/g/g116567/)|
|010|C28|Capacitor 100nF|1|JLCPCB|ATMegaARFF用コンデンサ|[JLCPCB](https://jlcpcb.com/partdetail/YAGEO-CC0805KRX7R9BB104/C49678)|
|011|SW1|TVBP06-B043C|1|OWN|ATMegaRST用白色タクトスイッチ|[秋月電子](https://akizukidenshi.com/catalog/g/g108074/)|
|012|C18|Capacitor 100nF|1|JLCPCB|ATMegaRST用コンデンサ|[JLCPCB](https://jlcpcb.com/partdetail/YAGEO-CC0805KRX7R9BB104/C49678)|
|013|R81|Resister 10kΩ|1|JLCPCB|ATMegaRST用抵抗器|[JLCPCB](https://jlcpcb.com/partdetail/18102-0805W8F1002T5E/C17414)|
|014|C20|Capacitor 100uF|1|JLCPCB|ATMega用バルクコンデンサ|[JLCPCB](https://jlcpcb.com/partdetail/15681-CL31A107MQHNNNE/C15008)|
|015|C34~38|Capacitor 100nF|5|JLCPCB|ATMega用バイパスコンデンサ|[JLCPCB](https://jlcpcb.com/partdetail/YAGEO-CC0805KRX7R9BB104/C49678)|
|016|SW2|SS12D01G4|1|OWN|5V切り替え用スライドスイッチ|[秋月電子](https://akizukidenshi.com/catalog/g/g112723/)|
|017|J3|コネクタハウジング 02x03|1|OWN|ICSP用ハウジング（配線を介すること）|[秋月電子](https://akizukidenshi.com/catalog/g/g112435/)|
|018|D41|OSG50603C1E|1|OWN|信号緑色LED|[秋月電子](https://akizukidenshi.com/catalog/g/g108275/)|
|019|D42|OSWT1608C1A|1|OWN|信号青色LED|[秋月電子](https://akizukidenshi.com/catalog/g/g103986/)|
|020|R85,86|Resister 330Ω|2|JLCPCB|LED用抵抗器|[JLCPCB](https://jlcpcb.com/partdetail/18318-0805W8F3300T5E/C17630)|
|021|U18|CH340G|1|OWN|USB-UART変換IC|[秋月電子](https://akizukidenshi.com/catalog/g/g113544/)|
|022|C31,32,33|Capacitor 100nF|3|JLCPCB|CH340G用コンデンサ|[JLCPCB](https://jlcpcb.com/partdetail/YAGEO-CC0805KRX7R9BB104/C49678)|
|023|R93|Resister 4.7kΩ|1|JLCPCB|CH340G用抵抗器|[JLCPCB](https://jlcpcb.com/partdetail/18361-0805W8F4701T5E/C17673)|
|024|Y1|Crystal 16MHz|1|OWN|クリスタル|[秋月電子](https://akizukidenshi.com/catalog/g/g108671/)|
|025|C17,19|Capacitor 22pF|2|JLCPCB|クリスタル用コンデンサ|[JLCPCB](https://jlcpcb.com/partdetail/2005-CL10C220JB8NNNC/C1653)|
|026|R82|Resister 1MΩ||JLCPCB|クリスタル用抵抗器|[JLCPCB](https://jlcpcb.com/partdetail/18202-0805W8F1004T5E/C17514)|
|027|Y2|Crystal 12MHz|1|OWN|クリスタル|[秋月電子](https://akizukidenshi.com/catalog/g/g108669/)|
|028|C29,30|Capacitor 22pF|2|JLCPCB|クリスタル用コンデンサ|[JLCPCB](https://jlcpcb.com/partdetail/2005-CL10C220JB8NNNC/C1653)|
|029|R89|Resister 1MΩ|1|JLCPCB|クリスタル用抵抗器|[JLCPCB](https://jlcpcb.com/partdetail/18202-0805W8F1004T5E/C17514)|
|030|P1|USB Type-C|1|OWN|1|[秋月電子](https://akizukidenshi.com/catalog/g/g114356/)|
|031|R90,91|Resister 5.1kΩ|2|JLCPCB|USB用抵抗器|[JLCPCB](https://jlcpcb.com/partdetail/28584-0805W8F5101T5E/C27834)|
|032|D43|CH213K|1|OWN|USB用理想ダイオード|[秋月電子](https://akizukidenshi.com/catalog/g/g129462/)|
|033|D44|OSR50603C1E|1|OWN|VBUS確認用LED|[秋月電子](https://akizukidenshi.com/catalog/g/g108274/)|
|034|R92|Resister 330Ω|1|JLCPCB|VBUS確認用抵抗器|[JLCPCB](https://jlcpcb.com/partdetail/18318-0805W8F3300T5E/C17630)|
|035|J1|XT30U-M|1|OWN|供給基板との接続|[秋月電子](https://akizukidenshi.com/catalog/g/g117951/)|
|036|J2|---|-|---|2pin配線を直接実装すること|---|