// Surprisingly, this top-down DP solution works
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <limits.h>

#define MAX 103

using namespace std;
int n, m;
int memo[MAX][MAX][1200];
pair<int, int>power[MAX][MAX];
int dp(int i, int j, int p){		// maximum power of 2 that you can get starting at stone i, j if you want to get a p-power of 3 exactly
	if (p < 0) return INT_MIN;
	if (memo[i][j][p] != -1) return memo[i][j][p];
	if (i == n && j == m) return (!p)?0:INT_MIN;
	if (i == n) return memo[i][j][p] = power[i][j].first + dp(i, j + 1, p - power[i][j].second);
	if (j == m) return memo[i][j][p] = power[i][j].first + dp(i + 1, j, p - power[i][j].second);
	return memo[i][j][p] = power[i][j].first + max(dp(i+1, j, p-power[i][j].second), dp(i, j+1, p-power[i][j].second));
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int x;
	int TC;
	scanf("%d", &TC);
	while (TC--){
		memset(power, 0, sizeof power);
		memset(memo, 0xFF, sizeof memo);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			scanf("%d", &x);
			while (!(x & 1)) { power[i][j].first++; x >>= 1; }
			while (!(x % 3)) { power[i][j].second++; x /= 3; }
		}
		int ans = 0;
		for (int i = 0; i < 1200; i++)
			ans = max(ans, min(i, dp(0, 0, i)));
		printf("%d\n", ans);
	}
	return 0;
}
