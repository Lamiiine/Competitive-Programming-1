#include<bits/stdc++.h>
#define MAX (1 << 7)
#define X real()
#define Y imag()
#define dist(a, b) hypot((a).X - (b).X, (a).Y - (b).Y)
using namespace std;
typedef complex<int> point;
point arr[MAX];
double memo[MAX][MAX][2];
int n, b1, b2;
inline double dp(const int i, const int j, const int k)
{
	// memorization
	double & ret = memo[i][j][k];
	if (ret != -1.0) return ret;

	const int next = max(i, j) + 1;
	// base case
	if (next == n)
		return ret = dist(arr[i], arr[j]);

	ret = 1e9;
	// recursion (taking care of the special case)
	if (next == b2)
	{
		if (!k)
			// b1 has been put on the first track!
			return ret = dp(i, next, k) + dist(arr[j], arr[next]);
		else
			// b1 has been put on the second
			return ret = dp(next, j, k) + dist(arr[i], arr[next]);
	}

	return ret = min(dp(next, j, k) + dist(arr[i], arr[next]), dp(i, next, k || next == b1) + dist(arr[j], arr[next]));
}
inline void init_memo(void)
{
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			memo[i][j][0] = memo[i][j][1] = -1.0;
}
inline void read(void)
{
	if (b1 > b2) swap(b1, b2);
	for (int i = 0, x, y; i < n; ++i)
	{
		scanf("%d%d", &x, &y);
		arr[i] = point(x, y);
	}
}
vector<int>p[2];
inline void path(const int i, const int j, const int k)
{
	const int next = max(i, j) + 1;
	if (next == n)
	{
		p[i == n - 1].push_back(n - 1);
		return;
	}
	if (next == b2)
	{
		if (!k)
		{
			// has to be assigned to group 2
			p[1].push_back(next);
			path(i, next, k);
			return;
		}
		else
		{
			p[0].push_back(next);
			path(next, j, k);
			return;
		}
	}
	const double ans = dp(i, j, k);

	if (ans == dp(next, j, k) + dist(arr[i], arr[next]))
	{
		p[0].push_back(next);
		path(next, j, k);
	}
	else
	{
		p[1].push_back(next);
		path(i, next, k || next == b1);
	}
}
int main(void)
{
	for(int tc = 1; scanf("%d%d%d", &n, &b1, &b2), n || b1 || b2; ++tc)
	{
		init_memo();
		read();
		printf("Case %d: %.2lf\n", tc, dp(0, 0, 0));
		p[0].clear(); p[1].clear();
		p[0].push_back(0);
		p[1].push_back(0);
		path(0, 0, 0);
		for (int i = 0; i < p[0].size(); ++i)
			printf("%d ", p[0][i]);
		for (int i = p[1].size() - 2; i >= 0; --i)
			printf("%d%c", p[1][i], i ? ' ' : '\n');
	}
	return 0;
}

