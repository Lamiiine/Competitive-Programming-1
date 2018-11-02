#include<bits/stdc++.h>
#define MAX 1010
using namespace std;
char memo[MAX][MAX];
inline char dp(int n, int m){
	// do you win if you have n stones left where the other player removed m stones?
	char & ret = memo[n][m];
	if (ret != -1) return ret;
	for (m = min(n - 1, m << 1); m >= 1; --m)
		if (!dp(n - m, m)) return ret = 1;
	return ret = 0;
}
inline void init_memo(void){
	memset(memo, 0xFF, sizeof memo);
	memset(memo[0], 0, sizeof memo[0]);
	memset(memo[1], 1, sizeof memo[0]);
	memset(memo[2], 1, sizeof memo[2]);
	for (int i = 3; i < MAX; ++i)
		memset(&memo[i][(i >> 1) + (i & 1)], 1, sizeof (char)*(1001 - ((i >> 1) + (i & 1))));
}
int main(void){
	init_memo();
	// dp(100, 100);
	for (int n; scanf("%d", &n), n; )
	{
		bool flag = false;
		for (int i = 1; i < n && !flag; ++i)
			if (!dp(n - i, i)) flag = true;
		printf("%s\n", flag ? "Alicia" : "Roberto");
	}
	return 0;
}

