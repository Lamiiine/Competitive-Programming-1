#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> memo;
int n, t, m;
vector<int>len;
inline void init(void){
	memo.resize(n + 2);
	for (int i = 0; i < n + 2; ++i){
		memo[i].resize(t + 2);
		for (int j = 0; j < t + 2; ++j)
			memo[i][j].resize(m + 2);
	}
	for (int i = 0; i < n + 2; ++i)
		for (int j = 0; j < t + 2; ++j)
			for (int k = 0; k < m + 2; ++k)
				memo[i][j][k] = -1;
	for (int j = 0; j < t + 2; ++j)
		for (int k = 0; k < m + 2; ++k)
			memo[n][j][k] = 0;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= t; ++j)
			memo[i][j][m] = 0;
}
/* the maximum number of files you can take in, starting at file i
 * knowing that you have consumed j minutes from disk k, and you have
 * consumed all the previous disks
 * */
inline int dp(const int i, const int j, const int k){
	int & ret = memo[i][j][k];
	if (ret != -1) return ret;
	if (len[i] > t - j)
		// you can't put this file on this disk
		return ret = max(dp(i + 1, j, k), dp(i, 0, k + 1));
	return ret = max(dp(i + 1, j, k), 1 + dp(i + 1, j + len[i], k));
}
inline void read(void){
	scanf("%d%d%d", &n, &t, &m);
	len.resize(n);
	char s[20];
	for (int i = 0; i < n - 1; ++i){
		scanf("%s", s);
		s[strlen(s) - 1] = 0;
		sscanf(s, "%d", &len[i]);
	}
	scanf("%s", s);
	len[n-1] = atoi(s);
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		read();
		init();
		printf("%d\n", dp(0, 0, 0));
		if (TC) printf("\n");
	}
	return 0;
}

