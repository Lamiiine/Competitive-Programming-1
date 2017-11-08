#include<bits/stdc++.h>
#define MAX 650
using namespace std;
int n, arr[35];
int memo[35][MAX][MAX];
inline void read(void){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += arr[i];
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j){
			int k = sum - (i + j);
			memo[n][i][j] = max(abs(j - k), max(abs(i - j), abs(i - k)));
		}
}
inline int dp(const int i, const int j, const int k){
	int & ret = memo[i][j][k];
	if (ret != -1) return ret;
	return ret = min(dp(i + 1, j, k), min(dp(i + 1, j + arr[i], k), dp(i + 1, j, k + arr[i])));
}
int main(void){
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		read();
		init();
		printf("Case %d: %d\n", tc, dp(0, 0, 0));
	}
	return 0;
}

