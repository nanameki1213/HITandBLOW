#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIGITS 3

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
		hit_num = 0, blow_num = 0;
		int input[DIGITS];

		// プレイヤーの入力にillegal_numを再利用
		for(i = 0; i < 9; i++) {
			illegal_num[i] = 0;
		}

		i = 0;
		printf("%d桁の整数を入力\n", DIGITS);

		while(i < DIGITS) {
			printf("%d桁目を入力: ", i + 1);
			scanf("%d", &input[i]);
			if(illegal_num[input[i]] == 1) {
				printf("重複しない値再入力\n");
				continue;
			}

			illegal_num[input[i]] = 1;
			i++;
		}

		// hit数をカウント
		for(i = 0; i < DIGITS; i++) {
			if(input[i] == ans[i]) {
				hit_num++;
			}
		}
		// blow数をカウント
		for(i = 0; i < DIGITS; i++) {
			for(j = 0; j < DIGITS; j++) {
				if(ans[i] == input[j]) {
					if(i != j) {
						blow_num++;
					}
				}	
			}
		}

		if(hit_num == DIGITS) {
			printf("正解!\n");
			break;
		}

		printf("hit: %d, blow: %d\n\n", hit_num, blow_num);
	}
	return 0;
}