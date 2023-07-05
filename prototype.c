#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIGITS_NUM 3

int main(void) {
  int ans[DIGITS_NUM];
  int i, j;
  int hit_num = 0, blow_num = 0;
  int input;

  srand((unsigned)time(NULL));

  // 1. 答えとなる数を設定する

  while(/* プレイヤーが正解しない間 */) {
    int input_array[DIGITS_NUM];
    int hit_num = 0, blow_num = 0;

    // 2. プレイヤーからの数の入力を行う

    // 3. 入力された数のヒット数を計算

    // 4. 入力された数のブロー数を計算

    // 5. 結果を表示

  }

  return 0;
}