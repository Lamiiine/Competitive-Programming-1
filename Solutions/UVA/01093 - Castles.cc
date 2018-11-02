#include <bits/stdc++.h>
#define OO 100000000
#define MAX 105
#define MAX_E (MAX * 2)

using namespace std;

int n;
struct castle {
	int a, m, g;
} castles[MAX];
struct battle {
	int needed, surviving;
} battles[MAX];
int head[MAX], nxt[MAX_E], to[MAX_E], en;


inline bool cmp(const battle & a, const battle & b)
{
	return a.surviving < b.surviving;
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
	add_edge(f, t); add_edge(t, f);
}
inline void init()
{
	memset(head, -1, sizeof head); en = 0;
}
inline void read()
{
	for (int i = 0, a, m, g; i < n; ++i)
		scanf("%d%d%d", &a, &m, &g), castles[i] = castle{a, m, g};
	for (int i = 1, a, b; i < n; ++i)
		scanf("%d%d", &a, &b), --a, --b, add_bi_edge(a, b);
}
// Return number of surviving soldiers!
// Return something negative on failure!
inline void attack(const int i, const int parent)
{
	// Populate battles[i].
	const castle & cur_castle = castles[i];
	int needed = max(cur_castle.a, cur_castle.m + cur_castle.g);
	int surviving = needed - cur_castle.m - cur_castle.g;
	for (int j = head[i]; ~j; j = nxt[j])
	{
		const int k = to[j];
		if (k == parent) continue;
		attack(k, i);
	}
	vector<battle> children;
	for (int j = head[i]; ~j; j = nxt[j])
	{
		const int k = to[j];
		if (k == parent) continue;
		children.push_back(battles[k]);
	}
	// Sort by the number of surviving soldiers!
	sort(children.begin(), children.end(), cmp);
	for (auto iter = children.rbegin(); iter != children.rend(); ++iter)
	{
		const battle & cur_child = *iter;
		// Do the ones surviving so far enough?
		if (surviving < cur_child.needed)
			// An amry expansion is required!
			needed += (cur_child.needed - surviving),
			surviving = cur_child.surviving;
		else
			// No army expansion!
			surviving = (surviving - cur_child.needed)
			+ cur_child.surviving;
	}
	battles[i] = battle{needed, surviving};
}
inline int solve()
{
	int ans = OO;
	for (int i = 0; i < n; ++i)
		// Try attacking castle i first!.
		attack(i, -1), ans = min(ans, battles[i].needed);
	return ans;
}
int main()
{
	for (int tc = 1; scanf("%d", &n), n; ++tc)
	{
		init();
		read();
		printf("Case %d: %d\n", tc, solve());
	}
	return 0;
}

