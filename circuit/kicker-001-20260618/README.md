# Kicker 001

キッカー基板 ver.001のREADME

## 設計者
- @penguin92-prg
- @ryo-robot14

## 使用上の注意

- ソレノイドが2種類あるため注意
  - 通常キック用ソレノイド「Stroke」
  - チップキック用ソレノイド「Chip」
- ワンショット回路組み込み済み
  - 1000ms程度で連続通電を回路的に遮断する
  - 過信しすぎず、まずはプログラム側での制御を！
  - ワンショット回路を使用するかどうかは基板表面のジャンパで切り替え可能
    - 2コのソレノイドそれぞれに対してONとOFFの2種のジャンパがある
    - 設定したい方のジャンパをはんだ付けして導通させること

## 使用部品

|No.|Name|QTY|Assembled By|Note|URL|
|---|---|---|---|---|---|
|001|XL6009E1|1|OWN|昇圧素子|[謎](https://mega-radiodetali.com.ua/uploads/files_predprenimatel/XL6009E1.pdf)|
|002|BSS138|1|OWN|昇圧素子への給電EN用NMOS|[秋月電子](https://akizukidenshi.com/catalog/g/g104232)|
|003|TJ15S06M3L|1|OWN|昇圧素子への給電EN用PMOS|[秋月電子](https://akizukidenshi.com/catalog/g/g117253/)|
|004|MTB010N06RJ3|2|OWN|ソレノイドスイッチング用NMOS|[秋月電子](https://akizukidenshi.com/catalog/g/g117074/)|
|005|TLP2361|3|OWN|フォトカプラ|[秋月電子](https://akizukidenshi.com/catalog/g/g111004/)|
|006|74AHC1G04W5|5|OWN|NOTゲート（インバータ）|[秋月電子](https://akizukidenshi.com/catalog/g/g117602/)|
|007|74AHC1G08W5|2|OWN|ANDゲート|[秋月電子](https://akizukidenshi.com/catalog/g/g117603/)|
|008|DRV8874PWPR|1|OWN|ドリブラー制御用MD|[DigiKey](https://www.digikey.jp/ja/products/detail/texas-instruments/DRV8874PWPR/11502339)|
|009|NJL7502L|1|OWN|ボール補足用フォトトランジスタ|[秋月電子](https://akizukidenshi.com/catalog/g/g102325/)|
|010|OSR5JA3Z74A|1|OWN|ボール補足用LED|[秋月電子](https://akizukidenshi.com/catalog/g/g111577/)|
|011|ピンヘッダ 02x05|1|OWN|供給基板との接続|[秋月電子](https://akizukidenshi.com/catalog/g/g100168/)|
|012|B2B-XH-A|4|OWN|前ドリブラー/ソレノイド-Stroke/ソレノイド-Chip/コンデンサ基板|[秋月電子](https://akizukidenshi.com/catalog/g/g112247/)|