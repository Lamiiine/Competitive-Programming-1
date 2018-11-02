#include <bits/stdc++.h>
#define MAX 300005
using namespace std;
typedef pair<int, int> ii;
struct edge
{
	int f, t, c;
	inline bool operator < (const edge & other) const
	{
		return c < other.c;
	}
};
edge edges[MAX];
int n, m;
int memo[MAX];
inline void read()
{
	scanf("%d%d", &n, &m);
	for (int u, v, w, i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &u, &v, &w);
		edges[i] = edge{u, v, w};
	}
}
inline void init()
{
	memset(memo, 0, sizeof memo);
}
int main()
{
	init();
	read();
	sort(edges, edges + m);
	int ans = 0;
	for (int i = 0; i < m; )
	{
		vector<ii> buffer;
		const int cur_cost = edges[i].c;
		while (i < m && edges[i].c == cur_cost)
		{
			buffer.push_back(ii(
					edges[i].t,
					max(memo[edges[i].t], 1 + memo[edges[i].f])));
			++i;
		}
		for (const ii & update : buffer)
		{
			ans = max(ans, memo[update.first] = max(update.second, memo[update.first]));
		}
	}
	printf("%d", ans);
	return 0;
}

