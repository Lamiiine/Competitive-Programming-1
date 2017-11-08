#include<bits/stdc++.h>
#define MAX (1 << 10)
#define X real()
#define Y imag()
using namespace std;
typedef complex<double> point;
const double eps = 1e-9;
int n;
double d;
point p[MAX];
int parent[MAX];
inline int get_parent(const int i)
{
	return parent[i] == i ? i : parent[i] = get_parent(parent[i]);
}
inline void read(void)
{
	scanf("%d%lf", &n, &d);
	double x, y;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf%lf", &x, &y);
		p[i] = point(x, y);
	}
}
inline void init_parent(void)
{
	for (int i = 0; i < MAX; ++i)
	{
		parent[i] = i;
	}
}
inline void unite(const int i, const int j)
{
	parent[get_parent(i)] = get_parent(j);
}
inline double get_dist(const point & a, const point & b)
{
	return hypot(a.X - b.X, a.Y - b.Y);
}
inline void connect(void)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (get_dist(p[i], p[j]) - eps <= d)
			{
				unite(i, j);
			}
		}
	}
}
inline int solve(void)
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += (parent[i] == i);
	}
	return ans;
}
int main(void)
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		read();
		init_parent();
		connect();
		printf("Case %d: %d\n", tc, solve());
	}
	return 0;
}

