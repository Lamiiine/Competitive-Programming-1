#include<bits/stdc++.h>
#define MAX 64
using namespace std;
typedef long long int ll;
ll adj[MAX];
ll n, m;
ll num_set;
ll max_set;
inline void rec(const ll mask, const ll i)
{
	if (i == n)
	{
		// is mask maximal?
		bool flag = true;
		ll counter = 0LL;
		for (ll j = 0LL; j < n; ++j)
			if ((ll)mask & (1LL << j))
				++counter;
			else if ((adj[j] & mask) == 0LL)
			{
				flag = false;
				break;
			}

		if (flag)
		{
			++num_set;
			max_set = max(max_set, counter);
		}
		return;
	}

	bool flag = true;
	for (ll j = 0; j < i; ++j)
		if ((mask & (1LL << j)) && (adj[j] & (1LL << i)))
		{
			flag = false;
			break;
		}
	if (flag) rec(mask | (1LL << i), i + 1LL);
	rec(mask, i + 1);
}
inline void init(void)
{
	num_set = max_set = 0LL;
	memset(adj, 0, sizeof adj);
}
inline void read(void)
{
	scanf("%lld%lld", &n, &m);
	for (ll a, b, i = 0; i < m; ++i)
	{
		scanf("%lld%lld", &a, &b);
		adj[a] |= ((ll)1LL << b);
		adj[b] |= ((ll)1LL << a);
	}
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		rec(0, 0);
		printf("%lld\n%lld\n", num_set, max_set);
	}
	return 0;
}

