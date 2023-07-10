#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIGITS_NUM 3

void generate_ans(int ans[]);
int input_num(int input[]);
int count_hit(int ans[], int input[]);
int count_blow(int ans[], int input[]);

int main(void) {
	int ans[DIGITS_NUM];
	int i, j;
	int hit_num = 0, blow_num = 0;

	srand((unsigned)time(NULL));

  // 1. 答えとなる数を設定する
	generate_ans(ans);

	while(1) {
		int input_array[DIGITS_NUM];
		hit_num = 0, blow_num = 0;
    
    // 2. プレイヤーからの数の入力を行う
    input_num(input_array);
    // 3. 入力された数のヒット数を計算
		hit_num = count_hit(ans, input_array);
    // 4. 入力された数のブロー数を計算
    blow_num = count_blow(ans, input_array);

    // 5. 結果を表示
		if(hit_num == DIGITS_NUM) {
			printf("正解!\n");
			break;
		}

		printf("hit: %d, blow: %d\n\n", hit_num, blow_num);
	}
	return 0;
}

void generate_ans(int ans[]) {
  int i = 0;
	int illegal_num[10] = {0};
	while(i < DIGITS_NUM) {
		ans[i] = rand()%9;
		if(illegal_num[ans[i]] == 1) {
			continue;
		}
		illegal_num[ans[i]] = 1;
		i++;
  }
}

int input_num(int input_array[]) {
  int i;
  int input;
  printf("%d桁の整数を入力: ", DIGITS_NUM);
  scanf("%d", &input);
  for(i = 0; i < DIGITS_NUM; i++) {
    input_array[i] = input%10;
    input = input / 10;
  }

  return 0;
}

int count_hit(int ans[], int input[]) {
  int i, hit_num = 0;
  for(i = 0; i < DIGITS_NUM; i++) {
    if(input[i] == ans[i])
      hit_num++;
  }

  return hit_num;
}

int count_blow(int ans[], int input[]) {
  int i, j, blow_num = 0;
  for(i = 0; i < DIGITS_NUM; i++) {
    for(j = 0; j < DIGITS_NUM; j++) {
      if(ans[i] == input[j]) {
        if(i != j) {
          blow_num++;
        }
      }
    }
  }

  return blow_num;
}