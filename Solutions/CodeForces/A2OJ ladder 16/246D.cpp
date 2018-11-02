#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, m;
int color[MAX];
set<int> adj[MAX];
int ans_idx = MAX, ans_val = 0;
inline void read()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> color[i];
		ans_idx = min(ans_idx, color[i]);
	}
	for (int a, b; m--; )
	{
		cin >> a >> b;
		--a; --b;
		a = color[a];
		b = color[b];
		if (a != b)
		{
			adj[a].insert(b);
			adj[b].insert(a);
		}
	}
}
int main()
{
	read();
	for (int i = 0; i < MAX; ++i)
	{
		if (adj[i].size() > ans_val)
		{
			ans_val = adj[i].size();
			ans_idx = i;
		}
	}
	cout << ans_idx;
}

