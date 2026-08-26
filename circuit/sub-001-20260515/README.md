# サブ基板 001

サブ基板 ver.001のREADME

## 設計者
- @penguin92-prg
- @ryo-robot14

## ピンアサイン

## 使用上の注意

## 使用部品

|No.|Ref.|Name|QTY|Assembled By|Note|URL|
|---|---|---|---|---|---|---|
|001|U1,3,6,8,10|Grove|5|OWN|UnitV用（配線を介すること）|[秋月電子](https://akizukidenshi.com/catalog/g/g131074/)|
|002|U16,17|ESP32C3|2|OWN||[秋月電子](https://akizukidenshi.com/catalog/g/g117454/)<br>[秋月電子](https://akizukidenshi.com/catalog/g/g105779/)|
|003|D1,2,5~10|OSI5FU3A11C|8|OWN|IR-LED|[秋月電子](https://akizukidenshi.com/catalog/g/g104313/)|
|004|R5,6,17,18,27,28,39,40|Resister 47Ω|8|JLCPCB|IRLED用|[JLCPCB](https://jlcpcb.com/partdetail/18402-0805W8F470JT5E/C17714)|
|005|U4,5,12,13,18,19,22,23|NE555DR|8|JLCPCB|タイマーIC|[JLCPCB](https://jlcpcb.com/partdetail/TexasInstruments-NE555DR/C7593)|
|006|C2,3,8,9,14,15,21,22,27,28,33,34,37,38,43,44|Capacitor 10nF|16|JLCPCB|タイマーIC用|[JLCPCB](https://jlcpcb.com/partdetail/2062-CL21B103KBANNNC/C1710)|
|007|C4,5,17,18,29,30,39,40|Capacitor 1nF|8|JLCPCB|タイマーIC用|[JLCPCB](https://jlcpcb.com/partdetail/47657-CL21B102KBCNNNC/C46653)|
|008|C10,11,24,25,35,36,45,46|Capacitor 10uF|8|JLCPCB|タイマーIC用|[JLCPCB](https://jlcpcb.com/partdetail/439567-GRM21BR61H106KE43L/C440198)|
|009|R1,2,11,12,23,24,33,34|Resister 18kΩ|8|JLCPCB|タイマーIC用|[JLCPCB](https://jlcpcb.com/partdetail/18194-0805W8F1802T5E/C17506)|
|010|R3,4,13,14,25,26,37,38|Resister 1.5kΩ|8|JLCPCB|タイマーIC用|[JLCPCB](https://jlcpcb.com/partdetail/4717-0805W8F1501T5E/C4310)|
|011|R7,8,19,20,29,30,41,42|Resister 100Ω|8|JLCPCB|タイマーIC用|[JLCPCB](https://jlcpcb.com/partdetail/18096-0805W8F1000T5E/C17408)|
|012|R9,10,21,22,31,32,43,44|Resister 1kΩ|8|JLCPCB|タイマーIC用|[JLCPCB](https://jlcpcb.com/partdetail/18201-0805W8F1001T5E/C17513)|
|013|Q1~8|BSS138|8|OWN|NchMOSFET|[秋月電子](https://akizukidenshi.com/catalog/g/g104232/)|
|014|U20,21,24,25|tssp58038|4|OWN|IR Sensor|[秋月電子](https://akizukidenshi.com/catalog/g/g129594/)|
|015|C41/C42/C47/C48|Capacitor 0.33uF|4|JLCPCB|tssp58038用|[JLCPCB](https://jlcpcb.com/partdetail/2092-0805B334K500NT/C1740)|
|016|R35/R36/R45/R46|Resister 39kΩ|4|JLCPCB|tssp58038用|[JLCPCB](https://jlcpcb.com/partdetail/26569-0805W8F3902T5E/C25826)|
|017|U2,7,9,11,14,15|LM1117GS-3.3|6|OWN|3.3V生成3端子レギュレータ|[秋月電子](https://akizukidenshi.com/catalog/g/g116989/)|
|018|C1,6,7,12,13,16,19,20,23,26,31,32|Capacitor 10uF|12|JLCPCB|3端子レギュレータ用|[JLCPCB](https://jlcpcb.com/partdetail/439567-GRM21BR61H106KE43L/C440198)|
|019|D3|OSR50603C1E|1|OWN|5V給電確認用赤色LED|[秋月電子](https://akizukidenshi.com/catalog/g/g108274/)|
|020|D4|OSG50603C1E|1|ONW|3.3V給電確認用緑色LED|[秋月電子](https://akizukidenshi.com/catalog/g/g108275/)|
|021|R15,16|Resister 330Ω|2|JLCPCB|LED用抵抗器|[JLCPCB](https://jlcpcb.com/partdetail/18318-0805W8F3300T5E/C17630)|
|022|U26~29|HC-SR04|4|OWN|USS|[秋月電子](https://akizukidenshi.com/catalog/g/g111009/)|
|023|R47,48|Resister 10kΩ|2|JLCPCB|トグルスイッチプルアップ用抵抗器|[JLCPCB](https://jlcpcb.com/partdetail/18102-0805W8F1002T5E/C17414)|
|024|J1|AFC01_S12FCA00|1|JLCPCB|ネオピクセル基板へのFPCコネクタ|[JLCPCB](https://jlcpcb.com/partdetail/JUSHUO-AFC01_S12FCA00/C262661)|
|025|J2|ピンソケット 01x03|1|OWN|電源基板へのピンソケット|[秋月電子](https://akizukidenshi.com/catalog/g/g105779/)|
|026|J3|XT30U-M|1|OWN|電源基板へのXT30コネクタ|[秋月電子](https://akizukidenshi.com/catalog/g/g117951/)|
|027|J4|AFC01_S18FCA00|1|JLCPCB|メイン基板へのFPCコネクタ|[JLCPCB](https://jlcpcb.com/partdetail/JUSHUO-AFC01_S18FCA00/C262666)|