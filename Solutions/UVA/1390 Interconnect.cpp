#include<bits/stdc++.h>
#define MAX 32
#define rep(i) ((i) == p[(i)])
using namespace std;
int n, m;
double tot;
int p[MAX];
int sz[MAX];

map<vector<int>, double> memo;

inline vector<int> update(const vector<int> & v, const int i, const int j)
{
	vector<int> u(v);
	u[i] += u[j];
	swap(u[j], u.back());
	u.pop_back();
	sort(u.begin(), u.end());
	return u;
}

inline double dp(vector<int> v)
{
	if (v.size() == 1)
		return 0.0;
	if (memo.find(v) != memo.end()) return memo[v];
	double tmp = 0.0;
	for (int i = 0; i < v.size(); ++i)
		for (int j = i + 1; j < v.size(); ++j)
			tmp += (double) v[i] * v[j] * (1.0 + dp(update(v, i, j))) / tot;
	double x = 0.0;
	for (int i = 0; i < v.size(); ++i)
		x += v[i] * (v[i] - 1) * 0.5;
	/*
	 * ans = tmp + x/ tot * (1 + ans)
	 * ans = tmp + x / tot + x * ans / tot;
	 * ans (1 - x / tot) = tmp + x / tot
	 */
	return memo[v] = (tmp + x / tot) / (1.0 - x / tot);
}
inline int parent(const int i)
{
	return rep(i) ? i : parent(p[i]);
}
inline bool same(const int i, const int j)
{
	return parent(i) == parent(j);
}
inline void init()
{
	for (int i = 0; i < MAX; ++i)
		p[i] = i, sz[i] = 1;
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
inline void read()
{
	for (int a, b, i = 0; i < m; ++i)
		scanf("%d%d", &a, &b), unite(--a, --b);
}
inline vector<int> encode()
{
	vector<int> ans;
	for (int i = 0; i < n; ++i)
		if (rep(i))
			ans.push_back(sz[i]);
	sort(ans.begin(), ans.end());
	return ans;
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		init();
		read();
		tot = (double) (n * (n - 1)) * 0.5;
		printf("%lf\n", dp(encode()));
	}
	return 0;
}

