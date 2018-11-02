#include<bits/stdc++.h>
#define X real()
#define Y imag()
#define dist(a, b) (hypot((double)(a).X - (b).X, (double)(a).Y - (b).Y))
#define MAX 205
#define eps 1e-7
using namespace std;
typedef complex<int> point;
point cat[MAX], rat[MAX];
double mid;
int n, k;
int match[MAX];
int vis[MAX] = { 0 }, vis_id;
inline void print_dist(void)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			printf("%d - %d: %lf\n", i, j, dist(cat[i], rat[j]));
}
inline bool eq(const double a, const double b)
{
	return fabs(a - b) < eps;
}
inline void read(void)
{
	int a, b;
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a, &b), cat[i] = point(a, b);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a, &b), rat[i] = point(a, b);
}
// augment cat #i
inline int aug(const int i)
{
	if (vis[i] == vis_id) return 0;
	vis[i] = vis_id;
	for (int j = 0; j < n; ++j)
		if (dist(rat[j], cat[i]) >= mid && (match[j] == -1 || aug(match[j])))
		{
			match[j] = i;
			return 1;
		}
	return 0;
}
inline int max_match(void)
{
	memset(match, -1, sizeof match);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		++vis_id, ans += aug(i);
	return ans;
}
inline double solve(void)
{
	double lo = 0.0, hi = 141500.0;
	while(!eq(lo, hi))
	{
		mid = (lo + hi) * 0.5;
		if (((n << 1) - max_match()) >= k)
			hi = mid;
		else lo = mid;
	}
	return lo;
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	while(~scanf("%d%d", &n, &k))
	{
		read();
		printf("%.7lf\n", solve());
	}
	return 0;
}

