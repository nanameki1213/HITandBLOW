#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIGITS 3

int input_num(int input[]);
int count_hit(int ans[], int input[]);
int count_blow(int ans[], int input[]);

int main(void) {
	int ans[DIGITS];
	int i, j;
	int hit_num = 0, blow_num = 0;

	srand((unsigned)time(NULL));

	i = 0;
	int illegal_num[9] = {0};
	while(i < DIGITS) {
		ans[i] = rand()%9;
		if(illegal_num[ans[i]] == 1) {
			continue;
		}
		illegal_num[ans[i]] = 1;
		i++;
	}

	while(hit_num != DIGITS) {
		int input_array[DIGITS];
		hit_num = 0, blow_num = 0;
    
    while(input_num(input_array)) {
      printf("(再入力)");
    }
		hit_num = count_hit(ans, input_array);
    blow_num = count_blow(ans, input_array);

		if(hit_num == DIGITS) {
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
  printf("%d桁の整数を入力: ", DIGITS);
  scanf("%d", &input);

  for(j = DIGITS - 1; j >= 0; j--) {
    
    input_array[j] = input % 10;
    input /= 10;
  }
  if(input != 0) {
    printf("%d桁を超えた値を入力しないでください\n", DIGITS);
    return 1;
  }

  i = 0;
  while(i < DIGITS) {
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
  for(i = 0; i < DIGITS; i++) {
    if(input[i] == ans[i])
      hit_num++;
  }

  return hit_num;
}

int count_blow(int ans[], int input[]) {
  int i, j, blow_num = 0;
  for(i = 0; i < DIGITS; i++) {
    for(j = 0; j < DIGITS; j++) {
      if(ans[i] == input[j]) {
        if(i != j) {
          blow_num++;
        }
      }
    }
  }

  return blow_num;
}