#include<bits/stdc++.h>
#define MAX 10010
using namespace std;
typedef long long int ll;

// my global variables!
int n;
ll ans;

// edges
struct edge
{
	int u, v, c;
	edge(const int _u, const int _v, const int _c)
	{
		u = _u;
		v = _v;
		c = _c;
	}
	edge(){}
} arr[MAX];
inline bool cmp(const edge & x, const edge & y)
{
	return x.c < y.c;
}


// disjoint sets data structure!
int p[MAX], sz[MAX];
inline void init_p()
{
	for (int i = 0; i < n + 5; ++i)
		p[i] = i, sz[i] = 1;
}
inline int parent(const int i)
{
	return (p[i] == i) ? i : (p[i] = parent(p[i]));
}
inline void unite(const int i, const int j)
{
	const int I = parent(i), J = parent(j);
	if (I != J)
	{
		p[J] = I;
		sz[I] += sz[J];
	}
}
inline int get_comp_size(const int i)
{
	return sz[parent(i)];
}

// read edges!
inline void read()
{
	scanf("%d", &n);
	for (int i = 0, u, v, c; i < n - 1; ++i)
	{
		// scanf("%d%d%d", &u, &v, &c);
		cin >> u >> v >> c;
		arr[i] = edge(u, v, c);
	}
}

// solving
inline void solve()
{
	init_p();
	for (int i = 0; i < n - 1; ++i)
	{
		const edge & cur = arr[i];
		ans += (ll) get_comp_size(cur.u) * get_comp_size(cur.v) * cur.c;
		unite(cur.u, cur.v);
	}
	init_p();
	for (int i = n - 2; i >= 0; --i)
	{
		const edge & cur = arr[i];
		ans -= (ll) get_comp_size(cur.u) * get_comp_size(cur.v) * cur.c;
		unite(cur.u, cur.v);
	}
}

int main(void)
{
	freopen("agalaxy.in", "r", stdin);
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		sort(arr, arr + n - 1, cmp);
		ans = 0LL;
		solve();
		printf("%lld\n", ans);
	}
	return 0;
}

