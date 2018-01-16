#include <bits/stdc++.h>
#define MAX 100005
#define K 505
const int OO = 1e9;
using namespace std;
int head[MAX], nxt[MAX * 2], to[MAX * 2], cst[MAX * 2], en;
int p[MAX];
int dist[K][K];
int n, m, k;
vector<int> start;
inline void add_edge(const int i, const int j, const int k)
{
	nxt[en] = head[i];
	to[en] = j;
	cst[en] = k;
	head[i] = en++;
}
inline void add_bi_edge(const int i, const int j, const int k)
{
	add_edge(i, j, k); add_edge(j, i, k);
}
inline int parent(const int i)
{
	return (p[i] == i) ? i : (p[i] = parent(p[i]));
}
inline void unite(const int i, const int j)
{
	p[parent(j)] = parent(i);
}
inline void init()
{
	memset(head, -1, sizeof head); en = 0;
	for (int i = 0; i < MAX; ++i)
		p[i] = i;
	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			dist[i][j] = (i == j) ? 0 : OO;
		}
	}
}
inline int map_node(const int i)
{
	return upper_bound(start.begin(), start.end(), i) - start.begin() - 1;
}
int main()
{
	init();
	scanf("%d%d%d", &n, &m, &k);
	start.push_back(1);
	for (int i = 0, c; i < k; ++i)
		scanf("%d", &c), start.push_back(start.back() + c);
	for (int u, v, x; m--; )
	{
		scanf("%d%d%d", &u, &v, &x);
		add_bi_edge(u, v, x);
		if (!x) unite(u, v);
	}
	for (int i = 0; i < k; ++i)
	{
		for (int j = start[i] + 1; j < start[i + 1]; ++j)
		{
			if (parent(j) != parent(j - 1))
			{
				printf("No"); return 0;
			}
		}
	}
	for (int v = 1; v <= n; ++v)
	{
		for (int j = head[v]; ~j; j = nxt[j])
		{
			int & cur = dist[map_node(v)][map_node(to[j])];
			cur = min(cur, cst[j]);
		}
	}
	for (int q = 0; q < k; ++q)
	{
		for (int i = 0; i < k; ++i)
		{
			for (int j = 0; j < k; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][q] + dist[q][j]);
			}
		}
	}
	printf("Yes\n");
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			printf("%d%c", dist[i][j] == OO ? -1 : dist[i][j], j == k - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
/*
input
4 4 2
1 3
2 3 0
3 4 0
2 4 1
2 1 2
output
Yes
0 2
2 0
input
3 1 2
2 1
1 2 0
output
Yes
0 -1
-1 0
input
3 2 2
2 1
1 2 0
2 3 1
output
Yes
0 1
1 0
input
3 0 2
1 2
output
No
 */

