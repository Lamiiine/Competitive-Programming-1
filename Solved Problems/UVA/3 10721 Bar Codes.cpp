#include <bits/stdc++.h>
#define MAX 52
using namespace std;
typedef long long int ll;
int n, m, k;
ll memo[MAX][MAX];
/* number of barcodes of length i containing exactly j bars
*/
inline ll dp(const int i, const int j)
{
	if (i < 0 || j < 0)
	{
		return 0LL;
	}
	ll & ret = memo[i][j];
	if (ret != -1LL)
	{
		return ret;
	}
	if (i == 0 || j == 0)
	{
		return ret = 0LL;
	}
	ret = 0LL;
	for (int t = 1; t <= m; ++t)
	{
		ret += dp(i - t, j - 1);
	}
	return ret;
}
inline void init_memo(void)
{
	memset(memo, -1, sizeof memo);
	memo[0][0] = 1LL;
}
int main() {
	while(~scanf("%d%d%d", &n, &k, &m))
	{
		init_memo();
		printf("%lld\n", dp(n, k));
	}
	return 0;
}