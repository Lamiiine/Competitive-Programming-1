#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAX 26
using namespace std;
int num[MAX];
char grid[MAX][MAX];
int r, c, m, n;
int main(void){
	// freopen("Input.txt", "r", stdin);
	// DON'T FORGET TO REINITIALIZE BETWEEN TEST CASES!!!!
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		scanf("%d%d%d%d", &r, &c, &m, &n);
		int important = 0;
		int size = 0;
		memset(num, 0, sizeof num);
		for (int i = 0; i < r; ++i)
			scanf("%s", grid[i]);
		for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			important = max(important, ++num[grid[i][j] - 'A']);
		for (int i = 0; i < MAX; ++i){
			int temp = num[i];
			if (!temp) continue;
			if (temp == important) size += temp*m;
			else size += temp*n;
		}
		printf("Case %d: %d\n", tc, size);
	}
	return 0;
}

