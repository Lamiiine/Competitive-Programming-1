#include <bits/stdc++.h>
#define MAX 100100
#define OO 10000000
using namespace std;
typedef pair<int, int> ii;
struct edge {
	int a, b, c;
	inline edge(const int _a, const int _b, const int _c):a(_a), b(_b), c(_c) {}
	inline bool operator < (const edge & other) const
	{
		return c < other.c;
	}
};
 
int n, k;
vector<edge> edges;
int p[MAX], rnk[MAX], p_c[MAX];
ii queries[MAX];
 
inline void get_parent_list(vector<int> & v, const int i)
{
	if (p[i] != i)
	{
		get_parent_list(v, p[i]);
	}
	v.push_back(i);
}
inline int parent(int i)
{
	while (p[i] != i)
		i = p[i];
	return i;
}
inline void unite(const int i, const int j, const int c)
{
	// Union by rank!
	const int I = parent(i), J = parent(j);
	const int RI = rnk[I], RJ = rnk[J];
	// We are assuming that I and J are distinct
	if (RI < RJ)
	{
		p[I] = J;
		p_c[I] = c;
	}
	else
	{
		p[J] = I;
		p_c[J] = c;
		rnk[I] += (RI == RJ);
	}
}
inline void init()
{
	for (int i = 0; i < MAX; ++i)
	{
		p[i] = i;
		rnk[i] = 1;
	}
}
inline void read()
{
	scanf("%d", &n);
	for (int i = 1, a, b, c; i < n; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		edges.push_back(edge(a, b, c));
	}
	scanf("%d", &k);
	for (int i = 0, d, e; i < k; ++i)
	{
		scanf("%d%d", &d, &e);
		queries[i] = ii(d, e);
	}
}
inline void preprocess()
{
	for (const edge & e : edges)
	{
		unite(e.a, e.b, e.c);
	}
}
 
inline vector<int> solve(const bool mx)
{
	vector<int> ans;
	for(int _ = 0; _ < k; ++_)
	{
		const ii & cur = queries[_];
		vector<int> a, b;
		get_parent_list(a, cur.first);
		get_parent_list(b, cur.second);
		int i = 0;
		while (i < a.size() && i < b.size() && a[i] == b[i]) ++i;
		ans.push_back(mx ? max(i < a.size() ? p_c[a[i]] : -OO, i < b.size() ? p_c[b[i]] : -OO)
				: min(i < a.size() ? p_c[a[i]] : OO, i < b.size() ? p_c[b[i]] : OO));
	}
	return ans;
}
int main()
{
	read();
	init();
	sort(edges.begin(), edges.end());
	preprocess();
	vector<int> mx = solve(true);
	init();
	reverse(edges.begin(), edges.end());
	preprocess();
	vector<int> mn = solve(false);
	for (int i = 0; i < k; ++i)
	{
		printf("%d %d\n", mn[i], mx[i]);
	}
	return 0;
}
