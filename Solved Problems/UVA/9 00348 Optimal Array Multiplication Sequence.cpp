#include<bits/stdc++.h>
#define MAX 12
#define INF 1000000000000000000LL
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> llll;
ll memo[MAX][MAX];
llll d[MAX];	// dimensions
inline ll dp(const int i, const int j){
	ll & ret = memo[i][j];
	if (ret != -1LL) return ret;
	ret = INF;
	ll mul_cost = d[i].first * d[j].second;
	for (int k = i; k < j; ++k)
		ret = min(ret, (ll) dp(i, k) + dp(k + 1, j) + mul_cost * d[k].second);
	return ret;
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	for (int i = 0; i < MAX; ++i)
		memo[i][i] = 0;
}
int n;
inline void read(){
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", &d[i].first, &d[i].second);
}
inline string num(int i){
	return (i <= 9) ? string(1, '0' + i) : "10";
}
inline string path(int i, int j){
	if (i == j) return "A" + num(i + 1);
	ll ans = dp(i, j);
	ll mul_cost = d[i].first * d[j].second;
	for (int k = i; k < j; ++k)
		if (dp(i, k) + dp(k + 1, j) + mul_cost * d[k].second == ans)
			return "(" + path(i, k) + " x " + path(k + 1, j) + ")";
	return "";
}
int main(void){
	for(int tc = 1; scanf("%d", &n), n;++tc){
		init();
		read();
		printf("Case %d: %s\n", tc, path(0, n - 1).c_str());
	}
	return 0;
}

