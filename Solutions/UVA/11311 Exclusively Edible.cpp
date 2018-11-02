#include<bits/stdc++.h>
#define MAX 49
char memo[MAX][MAX][MAX][MAX];
inline char dp(const int m, const int n, const int i, const int j){
	char & ret = memo[m][n][i][j];
	if (ret != -1) return ret;
	for (int k = 1; k <= i; ++k)	// remove rows[0, k)
		if (!dp(m - k, n, i - k, j))
			return ret = 1;
	for (int k = i + 1; k < m; ++k)
		if (!dp(k, n, i, j))
			return ret = 1;	// remove rows[k, m)
	for (int k = 1; k <= j; ++k)
		if (!dp(m, n - k, i, j - k))
			return ret = 1;
	for (int k = j + 1; k < n; ++k)
		if (!dp(m, k, i, j)) return ret = 1;
	return ret = 0;
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	memset(memo[1][1], 0, sizeof memo[1][1]);
}
int main(void){
	init();
	int TC; scanf("%d", &TC);
	for (int m, n, r, c; TC--;)
		scanf("%d%d%d%d", &m, &n, &r, &c),
		printf("%s\n", dp(m, n, r, c) ? "Gretel" : "Hansel");
	return 0;
}

