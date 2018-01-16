#include<bits/stdc++.h>
#define MAX (1 << 5)
using namespace std;
typedef long long int ll;
ll memo[MAX];
inline void preprocess(void)
{
	memo[0] = 1LL;
	memo[1] = 0LL;
	for (int i = 2; i < MAX; ++i)
	{
		ll & cur = memo[i];
		// you can close at 2 in 3 different ways
		// afterwards, you can close at 4 in 2 different ways
		cur = 3 * memo[i - 2];
		for (int j = i - 4; j >= 0; j -= 2)
			cur += memo[j] << 1LL;
	}
}
int main(void)
{
	preprocess();
	for (int n; scanf("%d", &n), ~n; )
		printf("%lld\n", memo[n]);
	return 0;
}

