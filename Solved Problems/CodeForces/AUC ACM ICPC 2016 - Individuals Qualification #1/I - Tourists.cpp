#include<bits/stdc++.h>
#define MAX 200100
using namespace std;
int n;
int occur[MAX], dep[MAX * 2], node[MAX * 2], idx = 0;
int head[MAX], to[MAX * 2], nxt[MAX * 2], en = 0;
inline void dfs(const int i, const int depth, const int parent)
{
	occur[i] = idx;
	node[idx] = i;
	dep[idx] = depth;
	++idx;
	for (int j = head[i]; ~j; j = nxt[j])
	{
		const int k = to[j];
		if (k == parent)
		{
			continue;
		}
		dfs(k, depth + 1, i);
		node[idx] = i;
		dep[idx] = depth;
		++idx;
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
	idx = en = 0;
	memset(head, -1, sizeof head);
}
int spt[MAX * 2][20];
inline void build_spt(void)
{
	for (int i = 0; i < idx; ++i)
	{
		*spt[i] = i;
	}

	for (int j = 1, a, b; (1 << j) <= idx; ++j)
	{
		for (int i = 0; i + (1 << j) <= idx; ++i)
		{
			a = spt[i][j - 1];
			b = spt[i + (1 << (j - 1))][j - 1];
			spt[i][j] = dep[a] < dep[b] ? a : b;
		}
	}
}
inline int log_2(int i)
{
	int ans = -1;
	for(;i; i>>= 1)
	{
		++ans;
	}
	return ans;
}
inline int rmq(const int i, const int j)
{
	const int k = log_2(j - i + 1);
	const int a = spt[i][k], b = spt[j - (1 << k) + 1][k];
	return dep[a] < dep[b] ? a : b;
}

inline int lowest_depth(const int i, const int j)
{
	int a = occur[i], b = occur[j];
	if (a > b) swap(a, b);
	return dep[rmq(a, b)];
}
inline int get_dist(const int i, const int j)
{
	return dep[occur[i]] + dep[occur[j]] - (lowest_depth(i, j) << 1);
}
int main(void)
{
	init();
	scanf("%d", &n);
	for (int u, v, i = 1; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		add_bi_edge(u, v);
	}

	dfs(1, 0, -1);
	build_spt();
	long long int ans = 0LL;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i * 2; j <= n; j += i)
		{
			ans = (long long int) ans + get_dist(i, j) + 1LL;
			// printf("%d -> %d: %d\n", i, j, get_dist(i, j));
		}
	}
	cout << ans;
	return 0;
}

