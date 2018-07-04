//
//  lotto.c
//  algorithm_5_backtracking
//
//  Created by 김경이 on 2018. 5. 20..
//  Copyright © 2018년 kyungee. All rights reserved.
//

#include <stdio.h>

int arr[100], lt[100];
int k, i;

void dfs(int len, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i<6; i++)
			printf("%d ", lt[i]);
		printf("\n");
		return;
	}
	if (len >= k) return;
	lt[cnt] = arr[len];
	dfs(len + 1, cnt + 1);
	dfs(len + 1, cnt);
}

int main() {
	while (1) {
		scanf("%d", &k);
		if (k == 0)
			return 1;

		for (i = 0; i<k; i++) {
			scanf("%d", &arr[i]);
		}
		dfs(0, 0);
		printf("\n");
	}
}