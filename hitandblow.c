#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIGITS 3

int main(void) {
	int ans[DIGITS];
	int i, j;
	int hit_num = 0, blow_num = 0;

	srand((unsigned)time(NULL));

  // 1. 答えとなる数を設定する
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
		int input;
		hit_num = 0, blow_num = 0;

		// 2. プレイヤーからの数の入力を行う
		for(i = 0; i < 9; i++) {
			illegal_num[i] = 0;
		}
		i = 0;
		printf("%d桁の整数を入力: ", DIGITS);
		scanf("%d", &input);
		while(i < DIGITS) {
			input_array[i] = input%10;
			input /= 10;
			
			if(illegal_num[input_array[i]] == 1) {
				printf("重複した値を入力しないでください\n");
				break;
			}

			illegal_num[input_array[i]] = 1;
			i++;
		}

    // 3. 入力された数のヒット数を計算
		for(i = 0; i < DIGITS; i++) {
			if(input_array[i] == ans[i]) {
				hit_num++;
			}
		}

    // 4. 入力された数のブロー数を計算
		for(i = 0; i < DIGITS; i++) {
			for(j = 0; j < DIGITS; j++) {
				if(ans[i] == input_array[j]) {
					if(i != j) {
						blow_num++;
					}
				}	
			}
		}

    // 5. 結果を表示
		if(hit_num == DIGITS) {
			printf("正解!\n");
			break;
		}
		printf("hit: %d, blow: %d\n\n", hit_num, blow_num);

	}
	return 0;
}