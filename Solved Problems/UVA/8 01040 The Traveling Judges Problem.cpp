#include<bits/stdc++.h>
#define MAX 23
#define OO 100000000
using namespace std;
int p[MAX];	// disjoint sets (for mst)
inline void init_p(void)
{
	for (int i = 0; i < MAX; ++i) p[i] = i;
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


struct edge
{
	int f, t, c;
	edge(const int _f, const int _t, const int _c):f(_f), t(_t), c(_c) {}
	edge(){f = t = c = 0; }
} e[MAX * MAX];		// the edges of my graph


bool e_taken[MAX * MAX];	// is edge #i in the mst?

bool optimal_route[MAX * MAX];	// mst of optimal route

bool taken[MAX];	// is city #i included?

int n, m;	// number of nodes and edges

int dc;		// destination city

int J;		// number of judges
vector<int> judges;
bool has_judge[MAX];	// does city #i has a judge?
int optimal;		// optimal route
int optimal_num_taken;
inline int mst(void)
{
	init_p();
	memset(e_taken, 0, sizeof e_taken);
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		const edge & cur = e[i];
		if (taken[cur.f] && taken[cur.t] && !same(cur.f, cur.t))
			ans += cur.c, unite(cur.f, cur.t), e_taken[i] = true;
	}
	return ans;
}
inline bool valid_mst(void)
{
	const int parent = get_p(dc);
	for (int i = 1; i <= n; ++i)
		if (has_judge[i] && parent != get_p(i))
			return false;
	return true;
}
inline int count_taken()
{
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += taken[i];
	return ans;
}
inline void rec(const int i)
{
	if (i > n)
	{
		int cur = mst();
		if (valid_mst())
			if (cur < optimal)
			{
				optimal = cur;
				optimal_num_taken = count_taken();
				memcpy(optimal_route, e_taken, sizeof e_taken);
			}
			else if (cur == optimal)
			{
				const int cur_num_taken = count_taken();
				if (cur_num_taken < optimal_num_taken)
				{
					optimal_num_taken = cur_num_taken;
					memcpy(optimal_route, e_taken, sizeof e_taken);
				}
			}
	}
	else
	{
		taken[i] = true;
		rec(i + 1);
		if (!has_judge[i])
		{
			taken[i] = false;
			rec(i + 1);
		}
	}
}
inline void read()
{
	judges.clear();
	scanf("%d", &dc);
	scanf("%d", &m);
	for (int a, b, c, i = 0; i < m; ++i)
		scanf("%d%d%d", &a, &b, &c), e[i] = edge(a, b, c);
	memset(has_judge, 0, sizeof has_judge);
	scanf("%d", &J);
	for (int i = 0, a; i < J; ++i)
		scanf("%d", &a), has_judge[a] = true, judges.push_back(a);
}

inline bool cmp(const edge & x, const edge & y)
{
	return x.c < y.c;
}
int from[MAX];
inline void dfs(const int i)
{
	for (int j = 0; j < m; ++j)
		if (optimal_route[j])
		{
			const edge & cur = e[j];
			if (i == cur.f && from[cur.t] == -1)
				from[cur.t] = i, dfs(cur.t);
			if (i == cur.t && from[cur.f] == -1)
				from[cur.f] = i, dfs(cur.f);
		}
}
inline void path(int i)
{
	printf("   %d", i);
	i = from[i];
	while(i != -1)
	{
		printf("-%d", i);
		i = from[i];
	}
	printf("\n");
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	for(int tc = 1; scanf("%d", &n), n != -1; ++tc)
	{
		read();
		sort(e, e + m, cmp);
		optimal_num_taken = optimal = OO;
		rec(1);
		printf("Case %d: distance = %d\n", tc, optimal);
		memset(from, -1, sizeof from);
		from[dc] = OO;
		dfs(dc);
		from[dc] = -1;
		for (int i = 0; i < judges.size(); ++i)
			path(judges[i]);
		printf("\n");
	}
	return 0;
}

