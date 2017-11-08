#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(void)
{
	for (int n; scanf("%d", &n), n >= 0; )
	{
		printf("%lld\n", (ll) (n * (n + 1LL) >> 1LL) + 1LL);
	}
	return 0;
}

