#include<bits/stdc++.h>
#define MAX1 105
#define MAX2 3005
#define mod 1000000007LL
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
int n, l;
ll memo[MAX1][2][MAX2];
ii type[MAX1];
ll dp(const int i, const bool d, const int j){
	// number of ways of constructing j meters knowing that the previous block had type i and direction d
	if (j < 0) return 0LL;
	if (memo[i][d][j] != -1) return memo[i][d][j];
	ll ans = 0;
	// if d is true, you can use first
	int prev_wid = d ? type[i].first : type[i].second;
	for (int k = 0; k < n; ++k){
		if (k == i) continue;
		ii tmp = type[k];
		if (tmp.first == prev_wid)
			ans = (ans + dp(k, false, j - prev_wid))%mod;
		else if (tmp.second == prev_wid)
			ans = (ans + dp(k, true, j - prev_wid)) % mod;
	}
	return memo[i][d][j] = ans;
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	for (int i = 0; i < MAX1; ++i)
		memo[i][0][0] = memo[i][1][0] = 1LL;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	init();
	scanf("%d%d", &n, &l);
	for (int i = 0, x, y; i < n; ++i){
		scanf("%d%d", &x, &y);
		type[i] = ii(x, y);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)		// try every type
	{
		ans = (ans + dp(i, true, l - type[i].second)) % mod;
		if (type[i].first != type[i].second)
			ans = (ans + dp(i, false, l - type[i].first)) % mod;
	}
	cout << ans;
	return 0;
}

