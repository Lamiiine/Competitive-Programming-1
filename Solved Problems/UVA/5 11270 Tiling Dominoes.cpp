#include<bits/stdc++.h>
#define MAX 11
using namespace std;
typedef long long int ll;
ll memo[MAX][MAX * MAX][1 << MAX];
set<int>temp;
set<int>reach[MAX][1 << MAX];
inline void dfs(const int r, const int mask)
{
	if (temp.find(mask) != temp.end()) return;
	temp.insert(mask);
	for (int i = 0; i < r - 1; ++i)
	{
		if ((mask & (1 << i)) && (mask & (1 << (i + 1))))
		{
			dfs(r, mask - (1 << i) - (1 << (i + 1)));
		}
	}
}
inline void gen(const int r, const int mask)
{
	if (reach[r - 1][mask].empty())
	{
		temp.clear();
		dfs(r, mask);
		reach[r - 1][mask] = temp;
	}
}
inline ll dp(const int r, const int c, const int mask)
{
	ll & ret = memo[r - 1][c][mask];
	// memorization
	if (ret != -1LL)
	{
		return ret;
	}
	// base case
	if (!c)
	{
		return ret = (mask == 0) ? 1LL : 0LL;
	}

	int rev_mask = ((1 << r) - 1) - mask;
	// recursion
	gen(r, rev_mask);
	ret = 0;
	for (set<int>::iterator i = reach[r - 1][rev_mask].begin(); i != reach[r - 1][rev_mask].end(); ++i)
	{
		ret += dp(r, c - 1, *i);
	}

	return ret;
}
int main(void)
{
	memset(memo, -1, sizeof memo);
	for (int n, m; ~scanf("%d%d", &n, &m);)
	{
		const int x = min(n, m), y = max(n, m);
		printf("%lld\n", dp(x, y, 0));
	}
	return 0;
}

