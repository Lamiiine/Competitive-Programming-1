#include<bits/stdc++.h>
#define MAX 128
#define X real()
#define Y imag()
using namespace std;
typedef complex<long double> point;
const long double PI = 3.141592653589793;
const long double er = 6378;
const long double OO = 1e12;

long double dist[MAX][MAX];
map<string, int> city;
point arr[MAX];
int n, m, q;
inline long double get_dist(long double pLat, long double pLong, long double qLat, long double qLong)
{
	pLat *= PI / 180.0;
	pLong *= PI / 180.0;
	qLat *= PI / 180.0;
	qLong *= PI / 180.0;
	return er * acos(cos(pLat) * cos(pLong) * cos(qLat) * cos(qLong)
			+ cos(pLat) * sin(pLong) * cos(qLat) * sin(qLong)
			+ sin(pLat) * sin(qLat));
}
inline void init(void)
{
	city.clear();
	for (int i = 0; i < MAX; ++i)
	for (int j = 0; j < MAX; ++j)
		dist[i][j] = OO;
}
char s[32], ss[32];
inline void read(void)
{
	long double x, y;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%llf%llf", s, &x, &y);
		arr[i] = point(x, y);	// latitude and longitude!
		city[s] = i;
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%s%s", s, ss);
		const int a = city[s], b = city[ss];
		dist[a][b] = round(get_dist(arr[a].X, arr[a].Y, arr[b].X, arr[b].Y));
	}
}
inline void floyd_warshall(void)
{
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
inline void solve(void)
{
	while(q--)
	{
		scanf("%s%s", s, ss);
		const long double ans = dist[city[s]][city[ss]];
		if (ans == OO) printf("no route exists");
		else printf("%.0llf km", ans);
		printf("\n");
	}
}
int main(void)
{
	for(int tc = 1; scanf("%d%d%d", &n, &m, &q), n || m || q; ++tc)
	{
		if (tc > 1) printf("\n");
		init();
		read();
		floyd_warshall();
		printf("Case #%d\n", tc);
		solve();
	}
	return 0;
}

