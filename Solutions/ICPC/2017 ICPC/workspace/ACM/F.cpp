#include<bits/stdc++.h>
#define MAX 260
#define OO 1000000000000000
using namespace std;
typedef long long int ll;
// int head[2 * MAX], nxt[MAX * MAX];
int d, k;
ll r[MAX], p[MAX], max_r;
ll memo[MAX][MAX][MAX];
ll cost[MAX][MAX];
inline bool out_range(const int i)
{
	return i < 0 || i > 255;
}
inline ll get_cost(const int i, const int j)
{
	ll & ret = cost[i + 1][j];
	if (ret != -1LL) return ret;
	if (out_range(i) && out_range(j))
		return ret = OO;

	ret = 0;
	if (out_range(i))
	{
		for (int s = 0; s < d; ++s)
		{
			if (r[s] >= i && r[s] <= j)
			{
				const ll cc = r[s] - j;
				ret += cc * cc * p[s];
			}
		}
	} else
	if (out_range(j))
	{
		for (int s = 0; s < d; ++s)
		{
			if (r[s] >= i && r[s] <= j)
			{
				const ll cc = r[s] - i;
				ret += cc * cc * p[s];
			}
		}
	} else
	for (int s = 0; s < d; ++s)
	{
		if (r[s] >= i && r[s] <= j)
		{
			const ll cc = min(abs(r[s] - i), abs(r[s] - j));
			ret += cc * cc * p[s];
		}
	}

	return ret;
}
inline ll dp(const int i, const int j, const int l)
{
	/*
	 * return the minimum cost starting at intensity i,
	 * knowing that you have last selected intensity j,
	 * having l intensities left
	 */
	ll & ret = memo[i][j][l];
	if (ret != -1LL) return ret;
	if (l == 0 || i > max_r) return ret = get_cost(j, MAX - 1);
	// either don't pick this intensity
	ret = min(dp(i + 1, j, l), get_cost(j, i) + dp(i + 1, i, l - 1));
	return ret;
}
inline void read()
{
	scanf("%d%d", &d, &k);
	for (int i = 0; i < d; ++i)
	{
		scanf("%lld%lld", r + i, p + i);
	}
	max_r = *max_element(r, r + d);
}
inline void init()
{
	memset(cost, -1, sizeof cost);
	memset(memo, -1, sizeof memo);
}
int main()
{
	read();
	init();
	ll ans = OO;
	for (int i = *min_element(r, r + i); i <= max_r; ++i)
	{
		ans = min(ans, get_cost(-1, i) + dp(i + 1, i, k - 1));
	}
	printf("%lld", ans);
	return 0;
}

/*

2 1
50 20000
150 10000

2 2
50 20000
150 10000

4 2
0 30000
25 30000
50 30000
255 30000
 */
