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
  ans[0] = 3;
  ans[1] = 2;
  ans[2] = 1;

  while(1) {
    int input_array[DIGITS_NUM];
    int hit_num = 0, blow_num = 0;

    // 2. プレイヤーからの数の入力を行う
    printf("%d桁の整数を入力: ", DIGITS_NUM);
    scanf("%d", &input);
    for(i = 0; i < DIGITS_NUM; i++) {
      input_array[i] = input%10;
      input = input / 10;
    }

    // 3. 入力された数のヒット数を計算
    for(i = 0; i < DIGITS_NUM; i++) {
      if(input_array[i] == ans[i]) {
        hit_num++;
      }
    }

    // 4. 入力された数のブロー数を計算
    for(i = 0; i < DIGITS_NUM; i++) {
      for(j = 0; j < DIGITS_NUM; j++) {
        if(ans[i] == input_array[j]) {
          if(i != j) {
            blow_num++;
          }
        }
      }
    }

    // 5. 結果を表示
    printf("hit: %d, blow: %d\n\n", hit_num, blow_num);

  }

  return 0;
}