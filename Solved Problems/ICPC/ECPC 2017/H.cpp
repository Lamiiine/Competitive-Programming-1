#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> primes;
inline void sieve()
{
	const int upper_bound = 1000000;
	bitset<upper_bound + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
	{
		if (bs[i])
		{
			primes.push_back(i);
			if ((ll) 1LL * i * i <= upper_bound)
			{
				for (int j = i * i; j <= upper_bound; j += i)
				{
					bs[j] = 0;
				}
			}
		}
	}
}
inline bool is_prime(const int x)
{
	return binary_search(primes.begin(), primes.end(), x);
}
inline ll raise(ll base, ll power)
{
	ll ans = 1LL;
	for (; power; power >>= 1, base *= base)
		if (power & 1LL)
			ans *= base;
	return ans;
}

inline int log_10(ll x)
{
	int ans = 0;
	while (x)
	{
		x /= 10;
		++ans;
	}
	return ans;
}
inline ll solve(const ll lower, const ll upper)
{
	for (ll x = upper; x >= lower; )
	{
		const int x_len = log_10(x);
		const int a_len = x_len >> 1;
		const int b_len = x_len - a_len;
		const ll tens = raise(10, b_len);
		const ll a = x / tens, b = x % tens;
		if (a && b && __gcd(a, b) != 1LL)
		{
			return x;
		}
		// update x!
		if (is_prime(a))
		{
			if (b < a)
			{
				x = a * tens - 1;
			}
			else
			{
				x = a * tens + (b / a) * a;
			}
		}
		else
		{
			--x;
		}
	}
	return -1LL;
}

int main()
{
	freopen("halfnice.in", "r", stdin);
	sieve();
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		ll a, b; scanf("%lld%lld", &a, &b);
		const ll ans = solve(a, b);
		printf("Case %d: ", tc);
		if (ans != -1LL) printf("%lld", ans);
		else printf("impossible");
		printf("\n");
	}
	return 0;
}
/*
3
20 21
10 2019
4000 4005
1
10472988888 104729104728

 */

