#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef long long ll;
int n;
int p[MAX], sz[MAX];
inline int parent(const int i)
{
	return (i == p[i]) ? i : (p[i] = parent(p[i]));
}
inline void unite(const int i, const int j)
{
	const int I = parent(i), J = parent(j);
	p[J] = I;
	sz[I] += sz[J];
}
inline bool is_lucky(int w)
{
	for(int x; w; w /= 10)
	{
		x = w % 10;
		if (x != 4 && x != 7)
			return false;
	}
	return true;
}
inline void init()
{
	for (int i = 0; i < MAX; ++i)
		p[i] = i, sz[i] = 1;
}
inline void read()
{
	cin >> n;
	for (int i = 0, u, v, w; i < n - 1; ++i)
	{
		cin >> u >> v >> w;
		if (!is_lucky(w))
			unite(u, v);
	}
}
inline ll solve()
{
	ll ans = 0LL;
	for (int i = 1; i <= n; ++i)
	{
		if (i == p[i])
		{
			const ll s = sz[i];
			ans += s * (n - s) * (n - s - 1LL);
		}
	}
	return ans;
}
int main()
{
	init();
	read();
	cout << solve();
	return 0;
}
/*

4
1 2 4
3 1 2
1 4 7

4
1 2 4
1 3 47
1 4 7447
 */

