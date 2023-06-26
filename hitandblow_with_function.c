#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIGITS 3

int input_num(int input[]);
int count_hit(int ans[], int input[]);
int count_blow(int ans[], int input[]);

int main(void) {
	int ans[DIGITS_NUM];
	int i, j;
	int hit_num = 0, blow_num = 0;

	srand((unsigned)time(NULL));

	i = 0;
	int illegal_num[9] = {0};
	while(i < DIGITS_NUM) {
		ans[i] = rand()%9;
		if(illegal_num[ans[i]] == 1) {
			continue;
		}
		illegal_num[ans[i]] = 1;
		i++;
	}

	while(hit_num != DIGITS_NUM) {

		hit_num = 0, blow_num = 0;
		int input[DIGITS_NUM];
    while(input_num(input)) {
      printf("(再入力)");
    }
		hit_num = count_hit(ans, input);
    blow_num = count_blow(ans, input);

		if(hit_num == DIGITS_NUM) {
			printf("正解!\n");
			break;
		}

		printf("hit: %d, blow: %d\n\n", hit_num, blow_num);
	}
	return 0;
}

int input_num(int input_array[]) {
  int illegal_num[9] = {0};
  int i, j;
  int input;
  printf("%d桁の整数を入力: ", DIGITS_NUM);
  scanf("%d", &input);

  for(j = DIGITS_NUM - 1; j >= 0; j--) {
    if(input == 0) {
      printf("%d桁以下の値を入力しないでください\n", DIGITS_NUM);
      return 1;
    }
    input_array[j] = input % 10;
    input /= 10;
  }
  if(input != 0) {
    printf("%d桁を超えた値を入力しないでください\n", DIGITS_NUM);
    return 1;
  }

  i = 0;
  while(i < DIGITS_NUM) {
    if(illegal_num[input_array[i]] == 1) {
      printf("重複した値を入力しないでください\n");
      return 1;
    }

    illegal_num[input_array[i]] = 1;
    i++;
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