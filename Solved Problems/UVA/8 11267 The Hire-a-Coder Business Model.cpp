#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define OO 0x3F3F3F3F
#define MAX 202
using namespace std;
bool error_flag;
int n, m;
struct edge{
	int f, t, c;
	edge(int _f, int _t, int _c) : f(_f), t(_t), c(_c) {}
	edge(){}
};
inline bool operator < (const edge & x, const edge & y)
{
	return x.c < y.c;
}
int group[MAX];
vector<edge> v;
int p[MAX];
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
int adj[MAX][MAX];
int ans;
inline void init(void)
{
	error_flag = false;
	memset(adj, 0x3F, sizeof adj);
	memset(group, 0, sizeof group);
	for (int i = 0; i < MAX; ++i)
		p[i] = i;
	v.clear();
}

inline void read(void)
{
	scanf("%d", &m);
	for (int a, b, c, i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		adj[a][b] = adj[b][a] = min(adj[a][b], c);
		v.push_back(edge(a, b, c));
		if (group[a] == 2 || group[b] == 1) error_flag = true;
		group[a] = 1; group[b] = 2;
	}
}
inline void combine_negative(void)
{
	for (int i = 1; i <= n; ++i)
	for (int j = i + 1; j <= n; ++j)
	if (adj[i][j] <= 0)
	{
		unite(i, j);
		ans += adj[i][j];
	}
}
inline void combine_positive(void)
{
	for (int i = 0; i < v.size(); ++i)
		// negatives have already been considered!
	if (v[i].c > 0 && !same(v[i].f, v[i].t))
	{
		unite(v[i].f, v[i].t);
		ans += v[i].c;
	}
}
inline bool connected(void)
{
	const int parent = get_p(1);
	for (int i = 2; i <= n; ++i)
	if (parent != get_p(i)) return false;
	return true;
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
#endif
	while (scanf("%d", &n), n)
	{
		init();
		read();
		ans = 0;
		combine_negative();
		sort(v.begin(), v.end());
		combine_positive();
		if (error_flag || !connected()) printf("Invalid data, Idiot!");
		else printf("%d", ans);
		printf("\n");
	}
	return 0;
}