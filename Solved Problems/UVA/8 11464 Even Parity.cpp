#include<bits/stdc++.h>
#define MAX (1 << 4)
#define INF (1 << 20)
using namespace std;
int arr[MAX][MAX];
int n;
int ans;
inline void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", arr[i] + j);
}
const int di[4] = {0, 0, 1, -1},
		dj[4] = {-1, 1, 0, 0};
inline bool even_parity(const int i, const int j)
{
	int ans = 0;
	for (int k = 0; k < 4; ++k)
	{
		const int x = i + di[k],
				y = j + dj[k];
		if (x >= 0 && x < n && y >= 0 && y < n)
			ans += arr[x][y];
	}
	return !(ans & 1);
}
inline void flip(int & x)
{
	x = 1 - x;
}
inline void rec(const int idx, const int cur)
{
	if (cur >= ans) return;
	if (idx == n * n)
	{
		// last element in last row!
		// check for parity of last row
		for (int j = 0; j < n; ++j)
			if (!even_parity(n - 1, j))
				return;
		ans = min(cur, ans);
		return;
	}
	const int i = idx / n, j = idx % n;
	if (i == 0)
	{
		// first row
		// we try both
		if (arr[i][j] == 0)
		{
			rec(idx + 1, cur);
			flip(arr[i][j]);
			rec(idx + 1, cur + 1);
			flip(arr[i][j]);
		}
		else rec(idx + 1, cur);
	}
	else
	{
		if (!even_parity(i - 1, j))
		{
			if (arr[i][j] == 0)
			{
				flip(arr[i][j]);
				rec(idx + 1, cur + 1);
				flip(arr[i][j]);
			}
		}
		else rec(idx + 1, cur);
	}
}
int main(void)
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		read();
		ans = INF;
		rec(0, 0);
		printf("Case %d: %d\n", tc, ans >= INF ? -1 : ans);
	}
	return 0;
}

