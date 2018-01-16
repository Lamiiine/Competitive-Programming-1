#include<bits/stdc++.h>
#define MAX (1 << 20)
using namespace std;
typedef long long int ll;
ll memo[MAX];
inline ll sum(const ll n)
{
	return n * (n + 1LL) / 2LL;
}
inline void init_memo(void)
{
	memo[0] = memo[1] = memo[2] = memo[3] = 0LL;
	for (int i = 4; i < MAX; ++i)
	{
		memo[i] = memo[i - 1] + (3 - i + 2LL * sum(i - 2) - 1LL)/4LL;
	}
}
int main(void)
{
	init_memo();
	int TC; scanf("%d", &TC);
	for(ll n; TC--;)
	{
		scanf("%lld", &n);
		printf("%lld\n", memo[n]);
	}
	return 0;
}

