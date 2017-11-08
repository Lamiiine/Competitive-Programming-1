#include<bits/stdc++.h>
#define MAX 202
#define neg(x) (((x) + MAX) % (MAX * 2))
using namespace std;
typedef pair<int, int> ii;
// #. information
int n;
int dist[MAX][MAX];

// -1. edge definition
struct edge
{
	int f, t, c;
	edge(int _f, int _t, int _c)
	{
		f = _f;
		t = _t;
		c = _c;
	}
	edge(){f = t = c = 0;}
	inline bool operator < (const edge & other) const
	{
		return this->c < other.c;
	}
};

// 0. visited
enum visited: char {white = 0, gray, black} vis[MAX * 2];
inline void vis_init()
{
	memset(vis, 0, sizeof vis);
}
// 1. graph representation
int head[MAX * 2], to[MAX * MAX * 4], nxt[MAX * MAX * 4], en;
inline void add_edge(const int f, const int t)
{
	nxt[en] = head[f];
	head[f] = en;
	to[en] = t;
	++en;
}
inline void graph_init()
{
	memset(head, -1, sizeof head);
	en = 0;
}

// 2. disjoint-union sets
int dsu_p[MAX * 2];
inline int dsu_get_p(const int i)
{
	return (dsu_p[i] == i) ? i : (dsu_p[i] = dsu_get_p(dsu_p[i]));
}
inline void dsu_unite(const int i, const int j)
{
	dsu_p[dsu_get_p(j)] = dsu_get_p(i);
}
inline bool dsu_same(const int i, const int j)
{
	return dsu_get_p(i) == dsu_get_p(j);
}
inline void dsu_init()
{
	for (int i = 0; i < MAX * 2; ++i)
	{
		dsu_p[i] = i;
	}
}

// 3. Tarjan
vector<int> dfs_v;
int dfs_num[MAX * 2], dfs_low[MAX * 2], dfs_count;
inline void dfs(const int i)
{
	dfs_v.push_back(i);
	dfs_num[i] = dfs_low[i] = dfs_count++;
	vis[i] = gray;
	for (int j = head[i]; ~j; j = nxt[j])
	{
		const int k = to[j];
		if (vis[k] == white) dfs(k);
		if (vis[k] == gray) dfs_low[i] = min(dfs_low[i], dfs_low[k]);
	}

	if (dfs_low[i] == dfs_num[i])
	{
		for (int j = -1; j != i; )
		{
			j = dfs_v.back();
			dfs_v.pop_back();
			dsu_unite(i, j);
			vis[j] = black;
		}
	}
}

inline bool satisfiable()
{
	dsu_init();
	dfs_v.clear();
	vis_init();
	dfs_count = 0;

	for (int i = 0; i < n; ++i)
	{
		if (vis[i] == white)
		{
			dfs(i);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (dsu_same(i, neg(i)))
		{
			return false;
		}
	}
	return true;
}

// 4. maximum spanning tree
inline vector<edge> max_spanning_tree()
{
	vector<edge> ans;
	dsu_init();
	vector<edge> edges;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			edges.push_back(edge(i, j, dist[i][j]));
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = edges.size() - 1; i >= 0; --i)
	{
		const edge & e = edges[i];
		if (!dsu_same(e.f, e.t))
		{
			dsu_unite(e.f, e.t);
			ans.push_back(e);
		}
	}

	return ans;
}

// 5. bipartite coloring
inline void bipartite_coloring(const vector<edge> & tree)
{
	graph_init();
	for (edge e : tree)
	{
		add_edge(e.f, e.t);
		add_edge(e.t, e.f);
	}
	vis_init();
	queue<int> q;
	q.push(0);
	vis[0] = gray;
	while(!q.empty())
	{
		const int i = q.front();
		const visited opposite_color = (vis[i] == gray) ? black : gray;
		q.pop();
		for (int j = head[i]; ~j; j = nxt[j])
		{
			const int k = to[j];
			if (vis[k] == white)
			{
				q.push(k);
				vis[k] = opposite_color;
			}
		}
	}
}

// 6. solver
inline void add_or_constraint(const int i, const int j)
{
	add_edge(neg(i), j);
	add_edge(neg(j), i);
}
inline bool test(const int da, const int db)
{
	graph_init();
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			const int d = dist[i][j];
			if (da < d && d <= db)
			{
				// at least one of i and j need to be in b
				// bi || bj
				add_or_constraint(i, j);
			}
			else if (d > db)
			{
				// i and j have to be in separate sets
				add_or_constraint(i, j);
				add_or_constraint(neg(i), neg(j));
			}
		}
	}

	return satisfiable();
}
inline int get_max_dist_in_bipartite_set(const visited color)
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (vis[i] == color)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (vis[j] == color)
				{
					ans = max(ans, dist[i][j]);
				}
			}
		}
	}

	return ans;
}

inline vector<int> get_possible_db_values()
{
	vector<edge> tree = max_spanning_tree();
	vector<int> ans;
	for (edge e : tree)
	{
		ans.push_back(e.c);
	}
	bipartite_coloring(tree);
	ans.push_back(get_max_dist_in_bipartite_set(gray));
	ans.push_back(get_max_dist_in_bipartite_set(black));
	return ans;
}
inline int solve()
{
	int ans = INT_MAX;
	vector<int> possible_db = get_possible_db_values();
	vector<int> possible_da;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			possible_da.push_back(dist[i][j]);
		}
	}
	test(10, 10);
	sort(possible_da.begin(), possible_da.end());
	for (int db : possible_db)
	{
		int s = 0, e = possible_da.size();
		while (s != e)
		{
			const int m = (s + e) >> 1;
			const int da = possible_da[m];
			if (test(da, db))
			{
				e = m;
			}
			else
			{
				s = m + 1;
			}
		}

		if (s != possible_da.size())
		{
			ans = min(ans, db + possible_da[s]);
		}
	}

	return ans;
}

// 7. driver
inline void read()
{
	for (int i = 0, x; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			scanf("%d", &x);
			dist[i][j] = dist[j][i] = x;
		}
	}
}
int main()
{
	while(~scanf("%d", &n))
	{
		read();
		printf("%d\n", solve());
	}
	return 0;
}
/*
5
4 5 0 2
1 3 7
2 0
4
7
1 10 5 5 5 5
5 10 5 5 5
100 100 5 5
10 5 5
98 99
3
 */

