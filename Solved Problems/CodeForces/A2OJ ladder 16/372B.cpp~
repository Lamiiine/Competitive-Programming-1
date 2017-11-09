#include <bits/stdc++.h>
#define MAX 42
using namespace std;
typedef pair<int, int> ii;
int count[MAX][MAX];
int memo[MAX][MAX][MAX][MAX];
char arr[MAX + 2][MAX + 2];
vector<int> ones_in_row[MAX];
vector<int> ones_in_col[MAX];
int n, m, q;
inline int first_one_in_row(const int r, const int c)
{
	return *lower_bound(ones_in_row[r].begin(), ones_in_row[r].end(), c);
}
inline int first_one_in_col(const int c, const int r)
{
	return *lower_bound(ones_in_col[c].begin(), ones_in_col[c].end(), r);
}
inline ii first_one_in_grid(const int a, const int b, const int c, const int d)
{
	for (int i = a; i <= c; ++i)
	{
		const int cur = first_one_in_row(i, b);
		if (cur <= d)
			return ii(i, cur);
	}
	return ii(-1, -1);
}
inline int sum(const int n)
{
	return (n * (n + 1)) >> 1;
}
inline int sum(const int n, const int m)
{
	return sum(n) * sum(m);
}
inline int dp(const int a, const int b, const int c, const int d)
{
	if (a < 0 || b < 0 || c < 0 || d < 0 ||
			a >= n || c >= n || b >= m || d >= m ||
			a > c || b > d)
		return 0;
	int & ret = memo[a][b][c][d];
	if (ret != -1) return ret;
	// find a 1 inside (a, b) ..., ...(c, d)
	if (a == c)
	{
		// same row!
		// from b to d
		const int first_one_idx = first_one_in_row(a, b);
		if (first_one_idx > d)
		{
			return ret = sum(d - b + 1);
		}
		else
		{
			return ret = dp(a, b, c, first_one_idx - 1) + dp(a, first_one_idx + 1, c, d);
		}
	}
	if (b == d)
	{
		// same column!
		// from a to c!
		const int first_one_idx = first_one_in_col(b, a);
		if (first_one_idx > c)
		{
			return ret = sum(c - a + 1);
		}
		else
		{
			return ret = dp(a, b, first_one_idx - 1, d) + dp(first_one_idx + 1, b, c, d);
		}
	}
	const ii split = first_one_in_grid(a, b, c, d);
	const int x = split.first, y = split.second;
	if (x == -1)
	{
		// no ones!
		return ret = sum(c - a + 1, d - b + 1);
	}
	else
	{
		return ret = dp(a, b, x - 1, d) +
				dp(x + 1, b, c, d) +
				dp(a, b, c, y - 1) +
				dp(a, y + 1, c, d) -
				dp(a, b, x - 1, y - 1) -
				dp(a, y + 1, x - 1, d) -
				dp(x + 1, b, c, y - 1) -
				dp(x + 1, y + 1, c, d);
	}
}
inline void init()
{
	memset(memo, -1, sizeof memo);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			memo[i][j][i][j] = (arr[i][j] == '0');
		}
	}
}
inline void read()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", arr[i]);
	}
}
inline void preprocess()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (arr[i][j] == '1')
			{
				ones_in_row[i].push_back(j);
			}
		}
		ones_in_row[i].push_back(m);
	}
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (arr[i][j] == '1')
			{
				ones_in_col[j].push_back(i);
			}
		}
		ones_in_col[j].push_back(n);
	}
}
int main()
{
	init();
	read();
	preprocess();
	for (int a, b, c, d; q--; )
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		--a; --b; --c; --d;
		printf("%d\n", dp(a, b, c, d));
	}
}

