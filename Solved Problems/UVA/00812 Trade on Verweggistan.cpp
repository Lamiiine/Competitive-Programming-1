/* This is a dirty problem
 * It looks like it's an optimization problem, but it's actually
 * a difficult knapsack problem
 * */
#include<bits/stdc++.h>
using namespace std;
int b[55];
int gain[55][25];
int max_gain[55];
int w;
char memo[55][1010];
/*
 * is it possible to form a max-gain collection of size j
 * starting at workyard i?
 */
inline char dp(const int i, const int j)
{
	char & ret = memo[i][j];
	if (ret != -1) return ret;
	if (i == w)
		return ret = (j == 0);
	if (max_gain[i] == 0 && dp(i + 1, j)) return ret = 1;
	for (int t = 0; t < min(b[i], j); ++t)
		if (gain[i][t] == max_gain[i] && dp(i + 1, j - t - 1))
			return ret = 1;
	return ret = 0;
}
inline bool read(void)
{
	scanf("%d", &w);
	if (!w)
	{
		return 0;
	}
	for (int i = 0; i < w; ++i)
	{
		scanf("%d", b + i);
		for (int j = 0; j < b[i]; ++j)
		{
			scanf("%d", gain[i] + j);
		}
	}
	return 1;
}
inline void calc_max_gain(void)
{
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < b[i]; ++j)
		{
			gain[i][j] = 10 - gain[i][j];
		}
	}

	for (int i = 0; i < w; ++i)
	{
		for (int j = 1; j < b[i]; ++j)
		{
			gain[i][j] += gain[i][j-1];
		}
	}

	for (int i = 0; i < w; ++i)
	{
		max_gain[i] = 0;
		for (int j = 0; j < b[i]; ++j)
		{
			max_gain[i] = max(max_gain[i], gain[i][j]);
		}
	}
}
inline void init(void)
{
	memset(memo, 0xFF, sizeof memo);
}
int main(void)
{
	for(int tc = 1; read(); ++tc)
	{
		calc_max_gain();
		init();
		int ans = 0;
		for (int i = 0; i < w; ++i)
			ans += max_gain[i];
		printf("%sWorkyards %d\nMaximum profit is %d.\nNumber of pruls to buy:", tc == 1 ? "" : "\n", tc, ans);
		for (int i = 0, counter = 0; counter < 10 && i < 1010; ++i)
		{
			if (dp(0, i))
			{
				printf(" %d", i);
				++counter;
			}
		}
		printf("\n");
	}
	return 0;
}
/*
1
6 12 3 10 7 16 5
2
5 7 3 11 9 10
9 1 2 3 4 10 16 10 4 16
0
*/

