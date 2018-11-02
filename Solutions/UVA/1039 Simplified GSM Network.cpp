#include<bits/stdc++.h>
#define MAX 64
#define OO 100000000
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define dot(a, b) ((a).X * (b).X + (a).Y * (b).Y)
#define get_dist(a, b) (hypot((a).X - (b).X, (a).Y - (b).Y))
using namespace std;
typedef complex<double> point;
vector<int> adj[MAX];
point city[MAX];
point bts[MAX];
int b, c, r, q;
int dist[MAX][MAX];	// number of switches from city i to city j

point closest_line(const point & p, const point & a, const point & b)
{
	// point on line ab closest to p
	// if (a == b) return a;
	// a AND b MUST BE DISTINCT
	point ap = vec(a, p), ab = vec(a, b);
	return a + ab * dot(ap, ab) / dot(ab, ab);
}
point closest_segment(const point & p, const point & a, const point & b)
{
	// point on segment ab closest to p
	point ap = vec(a, p), ab = vec(a, b);
	double u = dot(ap, ab) / dot(ab, ab);
	if (u < 0.0) return a;
	if (u > 1.0) return b;
	return closest_line(p, a, b);
}
inline void init(void)
{
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			dist[i][j] = OO;
	for (int i = 0; i < MAX; ++i)
		adj[i].clear();
}
inline void floyd_warshall(void)
{
	for (int k = 0; k < c; ++k)
		for (int i = 0; i < c; ++i)
			for (int j = 0; j < c; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
inline void read(void)
{
	double x, y;
	for (int i = 0; i < b; ++i)
	{
		scanf("%lf%lf", &x, &y);
		bts[i] = point(x, y);
	}
	for (int i = 0; i < c; ++i)
	{
		scanf("%lf%lf", &x, &y);
		city[i] = point(x, y);
	}
	for (int a, b, i = 0; i < r; ++i)
	{
		scanf("%d%d", &a, &b);
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}
inline void set_dist(void)
{
	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j < adj[i].size(); ++j)
		{
			const int k = adj[i][j];
			// we have a road from i to k, and we need to find the number of switches on it!
			int counter = 0;
			// we need to count the number of towers claiming posession of this road
			for (int t = 0; t < b; ++t)
			{
				const point t_closest = closest_segment(bts[t], city[i], city[k]);
				const double t_dist = get_dist(t_closest, bts[t]);
				// does it claim possession of this road at some point?
				bool flag = true;
				for (int u = 0; u < b && flag; ++u)
					if (u != t && get_dist(bts[u], t_closest) < t_dist)
						flag = false;
				counter += flag;
			}
			dist[i][k] = counter - 1;
		}
	}
}
inline void solve(void)
{
	for (int a, b; q--;)
	{
		scanf("%d%d", &a, &b);
		--a; --b;
		const int ans = dist[a][b];
		if (ans == OO) printf("Impossible");
		else printf("%d", ans);
		printf("\n");
	}
}
int main(void)
{
	for(int tc = 1; scanf("%d%d%d%d", &b, &c, &r, &q), b || c || r || q; ++tc)
	{
		init();
		read();
		set_dist();
		floyd_warshall();
		printf("Case %d:\n", tc);
		solve();
	}
	return 0;
}

