#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int memo[MAX];
inline int dp(int i){
	int & ret = memo[i];
	if (ret != -1) return ret;
	int ans = 4 * dp(i - 2) + dp(i - 1);
	for (int j = 3; j <= i; ++j)
		ans += 2*dp(i - j);
	for (int j = 4; j <= i; j += 2)
		ans += dp(i - j);
	// return ret = 4 * dp(i - 2) + 2*dp(i - 3) + dp(i - 1);
	// for (int j = 4; j <= i; ++j) ans += dp(i - j);
	return ret = ans;
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 5;
	memo[3] = 11;
}
int main(void){
	init();
	int TC; scanf("%d", &TC);
	for (int x, tc = 1; tc <= TC; ++tc){
		scanf("%d", &x);
	printf("%d %d\n", tc, dp(x));
	}
	return 0;
}

