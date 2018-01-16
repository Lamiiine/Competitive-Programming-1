#include<bits/stdc++.h>
#define MAX 1010
#define X real()
#define Y imag()
using namespace std;
typedef complex<double> point;
point p[MAX];
double penalty[MAX];
int n;
double memo[MAX][MAX];
inline double dist(const point & a, const point & b)
{
	return hypot(a.X - b.X, a.Y - b.Y);
}
inline void read(void)
{
	for (int x, y, i = 1; i <= n; ++i)
	{
		scanf("%d%d%lf", &x, &y, penalty + i);
		p[i] = point(x, y);
	}
	++n;
	p[0] = point(0.0, 0.0);
	p[n] = point(100.0, 100.0);
}
inline void init_memo(void)
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			memo[i][j] = -1.0;
		}
	}
}
/*
 * return the minimum score incured started at target #j
 * knowing that the last target you stood on was #i
 */
inline double dp(const int i, const int j)
{
	// memory
	double & ret = memo[i][j];
	if (ret != -1.0)
	{
		return ret;
	}
	// base case
	if (j == n)
	{
		return ret = 1.0 + dist(p[i], p[j]);
	}
	// recurse
	return ret = min(dist(p[i], p[j]) + 1.0 + dp(j, j + 1), penalty[j] + dp(i, j + 1));
}
int main(void)
{
	while(scanf("%d", &n), n)
	{
		read();
		// init_memo();
		for (int i = 0; i < n; ++i)
		{
			memo[i][n] = 1.0 + dist(p[i], p[n]);
		}
		for (int j = n - 1; j >= 0; --j)
		{
			for (int i = j - 1; i >= 0; --i)
			{
				memo[i][j] = min(dist(p[i], p[j]) + 1.0 + memo[j][j + 1], penalty[j] + memo[i][j + 1]);
			}
		}

		printf("%.3lf\n", memo[0][1]);
	}
	return 0;
}

