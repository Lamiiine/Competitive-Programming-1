#include<bits/stdc++.h>
#define MAX (1 << 10)
using namespace std;
typedef pair<int, int> ii;
int head[MAX], to[MAX << 1], nxt[MAX << 1], en;
int dist[MAX], color[MAX];
int v_color[MAX], v_dist[MAX];
int n, m;
vector<int> v[MAX], r[MAX];
inline void dfs(void)
{
	memset(dist, -1, sizeof dist);
	dist[1] = 0;
	vector<int> v;
	v.push_back(1);
	while(!v.empty())
	{
		const int i = v.back();
		v.pop_back();
		const int cur_dist = dist[i] + 1;
		for (int j = head[i]; ~j; j = nxt[j])
		{
			const int k = to[j];
			if (dist[k] != -1)
			{
				continue;
			}

			dist[k] = cur_dist;
			v.push_back(k);
		}
	}
}
inline void add_edge(const int f, const int t)
{
	nxt[en] = head[f];
	head[f] = en;
	to[en] = t;
	++en;
}
inline void add_bi_edge(const int f, const int t)
{
	add_edge(f, t);
	add_edge(t, f);
}
inline void init(void)
{
	memset(head, -1, sizeof head);
	en = 0;
	for (int i = 0; i < MAX; ++i)
	{
		v[i].clear();
		r[i].clear();
	}
}
inline void read(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 1, f, t; i < n; ++i)
	{
		scanf("%d%d", &f, &t);
		add_bi_edge(f, t);
	}

	for (int i = 2; i <= n; ++i)
	{
		scanf("%d", color + i);
	}

	for (int i = 0; i < m; ++i)
	{
		scanf("%d", v_color + i);
	}

	for (int i = 0; i < m; ++i)
	{
		scanf("%d", v_dist + i);
	}
}
inline void normalize(void)
{
	for (int i = 2; i <= n; ++i)
	{
		// color of room i needs a volunteer to walk a distance of dist[i]
		r[color[i]].push_back(dist[i]);
	}

	for (int i = 0; i < m; ++i)
	{
		v[v_color[i]].push_back(v_dist[i]);
	}

	for (int i = 0; i < MAX; ++i)
	{
		sort(v[i].begin(), v[i].end());
		sort(r[i].begin(), r[i].end());
	}
}
inline int solve(void)
{
	int ans = 0;
	for (int i = 0; i < MAX; ++i)
	{
		const vector<int> & volunteers = v[i];
		const vector<int> & rooms = r[i];
		for (int v = 0, r = 0; r < rooms.size() && v < volunteers.size(); ++v)
		{
			if (volunteers[v] >= rooms[r])
			{
				++ans;
				++r;
			}
		}
	}

	return ans;
}

int main(void)
{
	freopen("give.in", "r", stdin);
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		dfs();
		normalize();
		printf("%d\n", solve());
	}

	return 0;
}

