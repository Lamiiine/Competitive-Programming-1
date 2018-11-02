#include<bits/stdc++.h>
#define MAX 128
#define X real()
#define Y imag()
using namespace std;
typedef long long int ll;
typedef complex<ll> point;
int p, k;	// total number of points, and number of chains required
int n, m;	// sizes of partite sets
point v[MAX];	// partite set of size n
point u[MAX];	// partite set of size m
ll dist[MAX][MAX];	// distances!
inline void init_dist(void)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			const ll dx = v[i].X - u[j].X;
			const ll dy = v[i].Y - u[j].Y;
			dist[i][j] = dx * dx + dy * dy;
		}
}
inline void read(void)
{
	scanf("%d%d", &p, &k);
	char s[8];
	n = m = 0;	// two empty partite sets
	for (int x, y, i = 0; i < p; ++i)
	{
		scanf("%d%d%s", &x, &y, s);
		if (*s == 'r')
			v[n++] = point(x, y);
		else
			u[m++] = point(x, y);
	}
}
ll d;
int vis[MAX] = { 0 }, vis_id = 0;
int match[MAX];
inline int dfs(const int i)
{
	if (vis[i] == vis_id)
		return 0;
	vis[i] = vis_id;
	for (int j = 0; j < m; ++j)
		if (dist[i][j] <= d && (match[j] == -1 || dfs(match[j])))
		{
			match[j] = i;
			return 1;
		}
	return 0;
}
inline int can()
{
	memset(match, -1, sizeof match);
	int ans = 0;
	++vis_id;
	for (int i = 0; i < n; ++i, ++vis_id)
		ans += dfs(i);
	return (ans >= k);
}
inline ll solve(void)
{
	ll lo = 0, hi = 1000000000;
	while(lo != hi)
	{
		const ll mid = (lo + hi) >> 1;
		d = mid * mid;
		if (can())
			hi = mid;
		else lo = mid + 1;
	}

	return lo;
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		init_dist();
		if (min(n, m) < k)
			printf("Impossible");
		else
			printf("%lld", solve());
		printf("\n");
	}
}

