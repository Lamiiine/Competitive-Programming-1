#include <bits/stdc++.h>
#define MAX 30100
using namespace std;
typedef long long int ll;
const ll val[4] = {50, 25, 10, 5};
ll memo[MAX][5];
inline ll dp(const int i, const int j)
{
	ll & ret = memo[i][j];
	if (ret != -1LL)
	{
		return ret;
	}
	if (i == 0 || j == 4)
	{
		return ret = 1;
	}
	return ret = dp(i, j + 1) + (i < val[j] ? 0 : dp(i - val[j], j));
}

inline void test(void)
{
	for (int i = 0; i <= 30000; i += 100)
	printf("%lld\n", dp(i, 0));
}

int main() {
	memset(memo, -1, sizeof memo);
	// test();
	for (int x; ~scanf("%d", &x);)
	{
		ll ans = dp(x, 0);
		if (ans == 1)
		printf("There is only 1 way to produce %d cents change.\n", x);
		else printf("There are %lld ways to produce %d cents change.\n", ans, x);
	}
	return 0;
}
