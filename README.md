# HITandBLOW

C言語でヒットアンドブローを作成する手順を以下に示します

## とりあえず動かしてみる

タグから完成したC言語のコードをダウンロードして実行する

## ゲームを実装するために何が必要か考えてみる

いきなりコードを書き始めるのではなく、まずおおまかにこのゲームの設計を考える
タグからコードをダウンロード

1から断片的にコードを書いていき、最後につなげて完成させる

### プロトタイプの説明

#### 変数の説明

このゲームを作るうえで、どのような変数が必要になってくるのか
```prototype.c
int main(void) {
  int ans[DIGITS_NUM];
  int i, j;
```
main関数内の初めの2行は、変数宣言が行われています。正解の3桁を格納するansという名前のint型配列と、繰返しのインデックスとして後々使うiとjを宣言しています。
```prototype.c
while(/* プレイヤーが正解しない間 */) {
    int input[DIGITS_NUM];
    int hit_num = 0, blow_num = 0;
```
ゲームの進行部分にあたるループの中でも、変数宣言が行われています。inputという配列は、プレイヤーの入力した数を格納するため、hit_num, blow_numはそれぞれヒット数、ブロー数を格納するために用意しています。hit_num, blow_numについては、後にカウントを行うため、0で初期化しています。

ここまでの変数をまとめると、以下の様になります。
| 変数名 | 役割 | 生存期間 |
| ---- | ---- | ---- |
| ans | 正解を格納 | main関数内 |
| input | プレイヤーの回答を格納 | while文の中 | 
| i | 繰り返しのインデックスとして使用 | main関数内 |
| j | 繰り返しのインデックスとして使用 | main関数内 |
| hit_num | ヒット数を格納 | while文の中 |
| blow_num | ブロー数を格納 | while文の中 |
