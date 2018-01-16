#include<bits/stdc++.h>
#define MAX 1024
#define MOD 1000000007LL
using namespace std;
typedef long long int ll;
ll memo[MAX][MAX];
ll c[MAX][MAX];
inline void init(void)
{
	memset(memo, -1, sizeof memo);
	for (int i = 0; i < MAX; ++i)
	{
		c[i][0] = 1LL;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		c[i][i] = 1LL;
		for (int j = i + 1; j < MAX; ++j)
			c[i][j] = 0LL;
	}
}
// i children, j games
inline ll dp(const int i, const int j)
{
	ll & ret = memo[i][j];
	if (ret != -1LL) return ret;
	if (j < i) return ret = 0LL;
	if (i == 1) return ret = 1LL;
	ret = 0LL;
	// at least 1 game, and at most j - 1
	for (int k = 1; j - k >= i - 1; ++k)
		ret = (ret + c[j][k] * dp(i - 1, j - k)) % MOD;
	return ret;
}
int main(void)
{
	freopen("galactic.in", "r", stdin);
	init();
	int TC; scanf("%d", &TC);
	for(int n, k; TC--;)
	{
		scanf("%d%d", &n, &k);	// games and children
		cout << ((n < k) ? 0LL : dp(k, n)) << endl;
	}
	return 0;
}

