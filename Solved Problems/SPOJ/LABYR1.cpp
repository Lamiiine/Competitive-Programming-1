#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
#define MAX 1005
using namespace std;
int c, r;
char map[MAX][MAX];
int memo[MAX][MAX][4];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
// 0 - 1
// 10 - 11
int dp(int i, int j, int from){
	if (memo[i][j][from] != -1) return memo[i][j][from];
	int ans = 0;
	int x, y;
	for (int k = 0; k < 4; ++k){
		if (k == from) continue;
		x = i + dx[k];
		y = j + dy[k];
		if (x < 0 || x >= r || y < 0 || y >= c) continue;
		if (map[x][y] == '#') continue;
		ans = max(ans, 1 + dp(x, y, k^1));
	}
	return memo[i][j][from] = ans;
}
int main(){
	int TC;
	scanf("%d", &TC);
	char d;
	while(TC--){
		memset(memo, 0xFF, sizeof memo);
		scanf("%d%d", &c, &r);
		scanf("%c", &d);
		for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j)
			scanf("%c", &map[i][j]);
		scanf("%c", &d);
		}
		int ans = 0;
		for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		if (map[i][j] == '.')
		for (int k = 0; k < 4; ++k) ans = max(ans, dp(i, j, k));
		printf("Maximum rope length is %d.\n", ans);
	}
	return 0;
}
