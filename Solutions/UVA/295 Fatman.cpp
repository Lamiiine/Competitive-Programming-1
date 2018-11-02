#include<bits/stdc++.h>
#define MAX (1 << 7)
#define eps (1e-9)
#define X real()
#define Y imag()
#define dist(a, b) (hypot((a).X - (b).X, (a).Y - (b).Y))
using namespace std;
typedef complex<int> point;
int p[MAX];
inline void init_p()
{
	for (int i = 0; i < MAX; ++i)
		p[i] = i;
}
inline int get_p(const int i)
{
	return p[i] == i ? i : p[i] = get_p(p[i]);
}
inline void unite(const int i, const int j)
{
	p[get_p(j)] = get_p(i);
}
inline bool same(const int i, const int j)
{
	return get_p(i) == get_p(j);
}

point arr[MAX];
int l, w;
int n;
inline void read(void)
{
	scanf("%d%d", &l, &w);
	scanf("%d", &n);
	for (int x, y, i = 0; i < n; ++i)
		scanf("%d%d", &x, &y), arr[i] = point(x, y);
}
inline bool can(const double diam)
{
	if (double(w) < diam) return false;
	init_p();
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (dist(arr[i], arr[j]) < diam)
				unite(i, j);
	for (int i = 0; i < n; ++i)
	{
		const double dist_below = arr[i].Y;
		const double dist_above = w - dist_below;
		if (dist_below < diam)
			unite(i, n);
		if (dist_above < diam)
			unite(i, n + 1);
	}
	return !same(n, n + 1);
}
inline double solve(void)
{
	double lo = 0.0, hi = 100.0;
	while(hi - lo > eps)
	{
		const double mid = (lo + hi) * 0.5;
		if (can(mid))
			lo = mid;
		else hi = mid;
	}
	return lo;
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	int TC; scanf("%d", &TC);
	for(int tc = 1; tc <= TC; ++tc)
	{
		read();
		printf("Maximum size in test case %d is %.4lf.\n", tc, solve());
	}
	return 0;
}

