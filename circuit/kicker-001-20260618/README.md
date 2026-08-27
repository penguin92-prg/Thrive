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

|No.|Ref.|Name|QTY|Assembled By|Note|URL|
|---|---|---|---|---|---|---|
|001|U3|XL6009E1|1|OWN|昇圧素子|[Aitendo](https://www.aitendo.com/product/10307)|
|002|Q1|BSS138|1|OWN|昇圧素子への給電EN用NMOS|[秋月電子](https://akizukidenshi.com/catalog/g/g104232)|
|003|Q2|TJ15S06M3L|1|OWN|昇圧素子への給電EN用PMOS|[秋月電子](https://akizukidenshi.com/catalog/g/g117253/)|
|004|Q4/Q5|MTB010N06RJ3|2|OWN|ソレノイドスイッチング用NMOS|[秋月電子](https://akizukidenshi.com/catalog/g/g117074/)|
|005|U2/U9/U10|TLP2361|3|OWN|フォトカプラ|[秋月電子](https://akizukidenshi.com/catalog/g/g111004/)|
|006|U1/U4/U5/U7/U8|74AHC1G04W5|5|OWN|NOTゲート（インバータ）|[秋月電子](https://akizukidenshi.com/catalog/g/g117602/)|
|007|U11/U12|74AHC1G08W5|2|OWN|ANDゲート|[秋月電子](https://akizukidenshi.com/catalog/g/g117603/)|
|008|U6|DRV8874PWPR|1|OWN|ドリブラー制御用MD|[DigiKey](https://www.digikey.jp/ja/products/detail/texas-instruments/DRV8874PWPR/11502339)|
|009|Q3|NJL7502L|1|OWN|ボール補足用フォトトランジスタ|[秋月電子](https://akizukidenshi.com/catalog/g/g102325/)|
|010|D1|OSR5JA3Z74A|1|OWN|ボール補足用LED|[秋月電子](https://akizukidenshi.com/catalog/g/g111577/)|
|011|J4|ピンヘッダ 02x05|1|OWN|供給基板との接続|[秋月電子](https://akizukidenshi.com/catalog/g/g100167/)|
|012|J1/J2/J3/J6|B2B-XH-A|4|OWN|前ドリブラー/ソレノイド-Stroke/ソレノイド-Chip/コンデンサ基板|[秋月電子](https://akizukidenshi.com/catalog/g/g112247/)|
|013|D2|CUHS20F60|1|OWN|昇圧素子用ダイオード|[秋月電子](https://akizukidenshi.com/catalog/g/g116782/)|
|014|L1|SRC1317|1|OWN|昇圧素子用インダクタ|[秋月電子](https://akizukidenshi.com/catalog/g/g116276/)|
|015|D3|OSR50603C1E|1|OWN|VCC確認用赤色LED|[秋月電子](https://akizukidenshi.com/catalog/g/g108274/)|
|016|D4|OSG50603C1E|1|OWN|LGC確認用緑色LED|[秋月電子](https://akizukidenshi.com/catalog/g/g108275/)|