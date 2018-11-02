#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll memo[8][8][8][8][4][4][4][4];
inline ll dp(const int a, const int b, const int c, const int d, const int prev_color, const int prev_size, const int first_color, const int first_size)
{
	// memorization
	ll & ret = memo[a][b][c][d][prev_color][prev_size][first_color][first_size];
	if (ret != -1LL)
	{
		return ret;
	}
	int cur[4] = {a, b, c, d};
	// base case; no more marbles
	if (a == 0 && b == 0 && c == 0 && d == 0)
	{
		return ret = (prev_color != first_color && prev_size != first_size);
	}
	// start counting
	ret = 0LL;
	for (int i = 0; i < 4; ++i)
	{
		if (cur[i] && i != prev_color)
		{
			int counter = 0;
			while(cur[i] && counter < 3)
			{
				--cur[i]; ++counter;
				if (counter != prev_size)
					ret += dp(cur[0], cur[1], cur[2], cur[3], i, counter, first_color, first_size);
			}
			cur[i] += counter;
		}
	}
	return ret;
}
int main(void)
{
	memset(memo, -1, sizeof memo);
	int TC; scanf("%d", &TC);
	int n, cur[4];
	while(TC--)
	{
		scanf("%d", &n);
		memset(cur, 0, sizeof cur);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", cur + i);
		}
		bool flag = false;
		for (int i = 0; i < 4; ++i)
		{
			if (cur[i])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			printf("1\n");
			continue;
		}
		ll ans = 0;
		for (int i = 0; i < 4; ++i)
		{
			if (cur[i])
			{
				int counter = 0;
				while(cur[i] && counter < 3)
				{
					--cur[i]; ++counter;
					ans += dp(cur[0], cur[1], cur[2], cur[3], i, counter, i, counter);
				}
				cur[i] += counter;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

