#include <bits/stdc++.h>
#define MAX 500000
#define left(s) ((s) << 1)
#define right(s) (((s) << 1) + 1)
#define avg(a, b) (((a) + (b)) >> 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
ll sum_factors[MAX+1] = { 0 };

inline void sieve()
{
	for (int i = 2; i <= MAX; ++i)
		if (!sum_factors[i])
		{
			// Prime!
			for (ll prime = i; prime <= MAX; prime *= i)
				for (ll j = prime; j <= MAX; j += prime)
					sum_factors[j] += i;
		}
}
int memo[MAX+1] = { 0 };
inline int dp(const int i)
{
	int & ret = memo[i];
	if (ret) return ret;
	if (sum_factors[i] == i) return ret = 1;
	return ret = 1 + dp(sum_factors[i]);
}
int st[MAX*4 + 4];
inline void build(const int p, const int l, const int r)
{
	if (l == r)
		st[p] = l;
	else {
		build(left(p), l, avg(l, r));
		build(right(p), avg(l, r) + 1, r);
		const int p1 = st[left(p)], p2 = st[right(p)];
		st[p] = dp(p1) > dp(p2) ? p1 : p2;
	}
}
int n, m;
inline int rmq(const int p, const int l, const int r)
{
	if (n > r || m < l) return -1;
	if (l >= n && r <= m) return st[p];
	const int p1 = rmq(left(p), l, avg(l, r)), p2 = rmq(right(p), avg(l, r) + 1, r);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	return dp(p1) > dp(p2) ? p1 : p2;
}
int main()
{
	sieve();
	build(1, 1, MAX);
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		scanf("%d%d", &n, &m);
		if (n > m) swap(n, m);
		printf("Case #%d:\n%d\n", tc, dp(rmq(1, 1, MAX)));
	}
	return 0;
}

