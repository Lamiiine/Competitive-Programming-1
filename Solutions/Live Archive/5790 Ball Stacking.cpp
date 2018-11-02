#include<bits/stdc++.h>
#define MAX 1010
using namespace std;
typedef long long int ll;
ll b[MAX][MAX];
ll memo[MAX][MAX];
ll sum[MAX][MAX];
int n;
inline void read(void){
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j)
			scanf("%lld", &b[j][i]);
}
inline void calc_sum(void){
	for (int i = 0; i < n; ++i)
		sum[i][i] = b[i][i];
	// loop over all columns
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			sum[i][j] = sum[i][j-1] + b[i][j];
}
inline ll dp(const int i, const int j){
	if (i < 0LL) return 0;
	if (j >= n) return -1000000000000LL;
	ll & ret = memo[i][j];
	if (ret != -1LL) return ret;
	return ret = max(sum[i][j] + dp(i - 1, j - 1), dp(i, j + 1));
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	// memo[0][n] = sum[0][n-1];
	// for (int i = 1; i < MAX; ++i) memo[i][n] = sum[i][n-1] + memo[i-1][n-1];
}
int main(void){
	while(scanf("%d", &n), n){
		read();
		calc_sum();
		init();
		ll ans = 0LL;
		for (int i = 0; i < n; ++i)
			for (int j = i; j < n; ++j)
				ans = max(ans, dp(i, j));
		printf("%lld\n", ans);
	}
	return 0;
}

