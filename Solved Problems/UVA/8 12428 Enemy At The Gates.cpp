#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m;
inline bool can(const ll k)
{
	// k critical roads
	const ll nn = n - k;
	const ll mm = m - k;

	return ((ll)((ll)nn * (nn - 1LL)) >> 1LL) >= mm;
}

int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%lld%lld", &n, &m);
		ll lo = 0LL, hi = (ll) min(m, n - 1);
		while(lo < hi)
		{
			const ll mid = max((lo + hi) >> 1LL, lo + 1LL);
			if (can(mid))
			{
				lo = mid;
			}
			else
			{
				hi = mid - 1LL;
			}
		}

		printf("%lld\n", lo);
	}
	return 0;
}

