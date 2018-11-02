#include<bits/stdc++.h>
#define X real()
#define Y imag()
#define cross(a, b) ((a).X * (b).Y - (a).Y * (b).X)
#define vec(a, b) ((b) - (a))
#define MAX 305
using namespace std;
int V, U;
typedef complex<int> point;
typedef pair<point, int> tower;
int n, r;
vector<tower> g[2];
tower arr[MAX];
point a, b;	// separation line
inline void read(void)
{
	for (int x, y, p, i = 0; i < n; ++i)
	{
		scanf("%d%d%d", &x, &y, &p);
		arr[i] = tower(point(x, y), p);
		// arr[i].first = point(x, y);
		// arr[i].second = p;
	}

	int x, y;
	scanf("%d%d", &x, &y);
	--x; --y;
	a = arr[x].first;
	b = arr[y].first;

	scanf("%d", &r);
	r *= r;
}
inline void separate(void)
{
	for (int i = 0; i < n; ++i)
	{
		const tower & cur = arr[i];
		const int c = cross(vec(a, b), vec(a, cur.first));
		if (c > 0 && cur.second)
		{
			g[0].push_back(cur);
		}
		else if (c < 0 && cur.second)
		{
			g[1].push_back(cur);
		}
	}
}
int head[MAX], to[MAX*MAX], nxt[MAX*MAX], en, match[MAX];
inline void init(void)
{
	g[0].clear(); g[1].clear();
	memset(head, -1, sizeof head);
	en = 0;
}
inline void add_edge(const int f, const int t)
{
	nxt[en] = head[f];
	head[f] = en;
	to[en] = t;
	++en;
}
inline int sqr_dist(const point & a, const point & b)
{
	const int dx = a.X - b.X;
	const int dy = a.Y - b.Y;
	return dx * dx + dy * dy;
}
inline void construct_graph(void)
{
	const vector<tower> & small = (g[0].size() < g[1].size()) ? g[0] : g[1];
	const vector<tower> & large = (g[0].size() > g[1].size()) ? g[0] : g[1];
	V = small.size();
	U = large.size();
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < U; ++j)
		{
			if (sqr_dist(small[i].first, large[j].first) <= r
					&& small[i].second > large[j].second
					&& small[i].second != 0 && large[j].second != 0)
			{
				add_edge(i, j);
			}
		}
	}
}
int vis[MAX], visId;
inline int aug(const int i)
{
	if (vis[i] == visId)
	{
		return 0;
	}
	vis[i] = visId;
	for (int j = head[i]; ~j; j = nxt[j])
	{
		const int k = to[j];
		if (match[k] == -1 || aug(match[k]))
		{
			match[k] = i;
			return 1;
		}
	}
	return 0;
}
inline int max_bipartite_match(void)
{
	memset(match, -1, sizeof match);
	memset(vis, -1, sizeof vis);
	visId = 0;
	int ans = 0;
	for (int i = 0; i < V; ++i, ++visId)
	{
		ans += aug(i);
	}
	return ans;
}
int main(void)
{
	for(int tc = 1; scanf("%d", &n), n; ++tc)
	{
		init();
		read();
		separate();
		construct_graph();
		printf("Case %d: %d\n", tc, max_bipartite_match());
	}
	return 0;
}

