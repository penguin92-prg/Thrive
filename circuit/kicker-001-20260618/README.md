# Kicker 001

キッカー基板 ver.001のREADME

## 設計者
- @penguin92-prg
- @ryo-robot14
- @AsaApp0424

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

### 昇圧・高電圧制御

- XL6009E1
  |Category|Data|
  |---|---|
  |QTY|1|
  |Package|TO-263-5|
  |Assembly|OWN|
  |Link|[謎](https://mega-radiodetali.com.ua/uploads/files_predprenimatel/XL6009E1.pdf)|
  |Note||

- BSS138
  |Category|Data|
  |---|---|
  |QTY|1|
  |Package|SOT-23|
  |Assembly|OWN|
  |Link|[秋月電子](https://akizukidenshi.com/catalog/g/g104232)|
  |Note|昇圧素子への給電EN用NMOS|

- TJ15S06M3L
  |Category|Data|
  |---|---|
  |QTY|1|
  |Package|TO-252|
  |Assembly|OWN|
  |Link|[秋月電子](https://akizukidenshi.com/catalog/g/g117253/)|
  |Note|昇圧素子への給電EN用PMOS|

- MTB010N06RJ3
  |Category|Data|
  |---|---|
  |QTY|2|
  |Package|TO-252|
  |Assembly|OWN|
  |Link|[秋月電子](https://akizukidenshi.com/catalog/g/g117074/)|
  |Note|ソレノイドのスイッチング用NMOS|

- TLP2361
  |Category|Data|
  |---|---|
  |QTY|3|
  |Package|SO-5-6|
  |Assembly|OWN|
  |Link|[秋月電子](https://akizukidenshi.com/catalog/g/g111004/)|
  |Note||

- 74AHC1G04W5
  |Category|Data|
  |---|---|
  |QTY|5|
  |Package|SOT23-5|
  |Assembly|OWN|
  |Link|[秋月電子](https://akizukidenshi.com/catalog/g/g117602/)|
  |Note|NOTゲート（インバータ）|

- 74AHC1G08W5
  |Category|Data|
  |---|---|
  |QTY|2|
  |Package|SOT23-5|
  |Assembly|OWN|
  |Link|[秋月電子](https://akizukidenshi.com/catalog/g/g117603/)|
  |Note|ANDゲート|

### ドリブラー制御
- DRV8874PWPR
  |Category|Data|
  |---|---|
  |QTY|1|
  |Package|HTSSOP-16-EP|
  |Assembly|OWN|
  |Link|[DigiKey](https://www.digikey.jp/ja/products/detail/texas-instruments/DRV8874PWPR/11502339)|
  |Note||

### ボール補足

- NJL7502L
  |Category|Data|
  |---|---|
  |QTY|1|
  |Package||
  |Assembly|OWN|
  |Link|[秋月電子](https://akizukidenshi.com/catalog/g/g102325/)|
  |Note||

### 一般部品

- ピンヘッダ 02x05
  |Category|Data|
  |---|---|
  |QTY|1|
  |Package||
  |Assembly|OWN|
  |Link|[秋月電子](https://akizukidenshi.com/catalog/g/g100168/)|
  |Note||

- B2B-XH-A
  |Category|Data|
  |---|---|
  |QTY|4|
  |Package||
  |Assembly|OWN|
  |Link|[秋月電子](https://akizukidenshi.com/catalog/g/g112247/)|
  |Note|前ドリブラー/ソレノイド-Stroke/ソレノイド-Chip/コンデンサ基板|