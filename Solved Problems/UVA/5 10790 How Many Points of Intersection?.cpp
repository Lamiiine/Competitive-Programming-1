#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(void)
{
	for (int a, b, tc = 1; scanf("%d%d", &a, &b), a || b; ++tc)
	{
		ll ans = 0;
		/*
		for (int j = 1; j < a; ++j)
		for (int i = 1; i < b; ++i)
		{
			ans += (ll) i * j;
		}
		*/
		ans = (ll) ((a * (a - 1LL)) / 2LL) * ((b * (b - 1LL)) / 2LL);
		printf("Case %d: %lld\n", tc, ans);
	}
	return 0;
}

