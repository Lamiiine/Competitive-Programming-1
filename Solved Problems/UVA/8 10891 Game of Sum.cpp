#include <bits/stdc++.h>
#define MAX 105
using namespace std;
typedef long long int ll;
int n;
ll arr[MAX];
ll acc[MAX];
ll memo[MAX][MAX];
inline ll sum(const int i, const int j){
	return acc[j+1] - acc[i];
}
inline ll dp(const int i, const int j){
	ll & ret = memo[i][j];
	if (ret != -1LL) return ret;
	ll ans = 0;
	for (int k = i; k <= j; ++k)
	ans = min(ans, dp(k + 1, j));
	for (int k = j; k >= i; --k)
	ans = min(ans, dp(i, k - 1));
	return ret = sum(i, j) - ans;
}
inline void read(void){
	for (int i = 0; i < n; ++i)
		scanf("%lld", arr + i);	
}
inline void calc_acc(void){
	acc[0] = 0;
	for (int i = 1; i <= n; ++i)
		acc[i] = acc[i-1] + arr[i-1];
}
inline void init_memo(void){
	memset(memo, 0xFF, sizeof memo);
	for (int i = 0; i < n; ++i)
	{
		memo[i][i] = arr[i];
		memo[i+1][i] = 0LL;
	}
}
int main() {
	while(scanf("%d", &n), n){
		read();
		calc_acc();
		init_memo();
		printf("%lld\n", (dp(0, n-1)<<1LL) - sum(0, n-1));
	}
	return 0;
}
