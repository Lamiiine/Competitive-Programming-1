#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int memo[23][102][52][2];
int cost[52], v[52];
int k, m, n;
inline int dp(const int d, const int b, const int p, const int second)
{
	// memory
	int & ret = memo[d][b][p][second];
	if (ret != -1)
	{
		return ret;
	}

	// base case
	if (d == k)
	{
		return ret = 0;
	}

	ret = 0;

	// recurse
	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		if (cost[i] <= b)
		{
			if (p != i)
			{
				const int next = dp(d + 1, b - cost[i], i, 0) + v[i];
				flag = flag || next > 0;
				ret = max(ret, next);
			}
			else
			{
				if (!second)
				{
					const int next = dp(d + 1, b - cost[i], i, 1) + (v[i] >> 1);
					flag = flag || next > 0;
					ret = max(ret, next);
				}
				else
				{
					const int next = dp(d + 1, b - cost[i], i, 1);
					flag = flag || next > 0;
					ret = max(ret, next);
				}
			}
		}
	}

	return ret = flag ? ret : -INF;
}

inline void read(void)
{
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", cost + i, v + i);
		v[i] <<= 1;
	}
}

int cost_memo[23][102][52][2];
inline int get_cost(const int d, const int b, const int p, const int second)
{
	int & ret = cost_memo[d][b][p][second];
	if (ret != -1)
	{
		return ret;
	}

	if (d == k)
	{
		return ret = 0;
	}

	ret = INF;
	const int max_value = dp(d, b, p, second);
	for (int i = 0; i < n; ++i)
	{
		if (cost[i] <= b)
		{
			if (p != i)
			{
				if (dp(d + 1, b - cost[i], i, 0) + v[i] == max_value)
				{
					ret = min(ret, cost[i] + get_cost(d + 1, b - cost[i], i, 0));
				}
			}
			else
			{
				if (!second)
				{
					if (dp(d + 1, b - cost[i], i, 1) + (v[i] >> 1) == max_value)
					{
						ret = min(ret, cost[i] + get_cost(d + 1, b - cost[i], i, 1));
					}
				}
				else
				{
					if (dp(d + 1, b - cost[i], i, 1) == max_value)
					{
						ret = min(ret, cost[i] + get_cost(d + 1, b - cost[i], i, 1));
					}
				}
			}
		}
	}

	return ret;
}
inline void path(const int d, const int b, const int p, const int second)
{
	const int max_value = dp(d, b, p, second);
	const int min_cost = get_cost(d, b, p, second);
	for (int i = 0; i < n; ++i)
	{
		if (cost[i] <= b)
		{
			if (p != i)
			{
				if (dp(d + 1, b - cost[i], i, 0) + v[i] == max_value && get_cost(d + 1, b - cost[i], i, 0) + cost[i] == min_cost)
				{
					printf("%d", i + 1);
					if (d == k - 1)
					{
						printf("\n");
					}
					else
					{
						printf(" ");
						path(d + 1, b - cost[i], i, 0);
					}
					return;
				}
			}
			else
			{
				if (!second)
				{
					if (dp(d + 1, b - cost[i], i, 1) + (v[i] >> 1) == max_value && cost[i] + get_cost(d + 1, b - cost[i], i, 1) == min_cost)
					{
						printf("%d", i  + 1);
						if (d == k - 1)
						{
							printf("\n");
						}
						else
						{
							printf(" ");
							path(d + 1, b - cost[i], i, 1);
						}
						return;
					}
				}
				else
				{
					if (dp(d + 1, b - cost[i], i, 1) == max_value && cost[i] + get_cost(d + 1, b - cost[i], i, 1) == min_cost)
					{
						printf("%d", i + 1);
						if (d == k - 1)
						{
							printf("\n");
						}
						else
						{
							printf(" ");
							path(d + 1, b - cost[i], i, 1);
						}
						return;
					}
				}
			}
		}
	}
}
inline void init(void)
{
	memset(memo, -1, sizeof memo);
	memset(cost_memo, -1, sizeof cost_memo);
}

int main(void)
{
	while(scanf("%d%d%d", &k, &n, &m), k || n || m)
	{
		read();
		init();
		const int ans = dp(0, m, 51, 0);
		if (ans < 0)
		{
			printf("0.0\n\n");
			continue;
		}
		printf("%.1lf\n", (double) ans / 2.0 + 1e-5);
		path(0, m, 51, 0);
	}

	return 0;
}

