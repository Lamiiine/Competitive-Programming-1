#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
typedef long long ll;
vector<int> primes;
inline void sieve()
{
	primes.reserve(MAX / log(MAX));
	bitset<MAX> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i < MAX; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			if (1LL * i * i < MAX)
				for (int j = i * i; j < MAX; j += i)
					bs[j] = 0;
		}
}
ll sum_div, num_div;
inline ll raise(ll x, ll n)
{
	ll ans = 1;
	for (; n; n >>= 1, x *= x)
		if (n & 1LL)
			ans *= x;
	return ans;
}
inline void answer(ll x)
{
	sum_div = 1LL, num_div = 1LL;
	for (int i = 0, p = primes[0]; p * p <= x; p = primes[++i])
	{
		int counter = 0;
		while (x % p == 0) ++counter, x /= p;
		if (counter)
		{
			num_div *= (counter + 1LL);
			sum_div *= (raise(p, counter + 1LL) - 1LL)/ (p - 1LL);
		}
	}
	if (x != 1LL)
	{
		num_div *= 2;
		sum_div *= (raise(x, 2) - 1) / (x - 1);
	}
}
int main()
{
	sieve();
	int TC; scanf("%d", &TC);
	for (int a, b, k; TC--; )
	{
		scanf("%d%d%d", &a, &b, &k);
		ll tot_sum_div = 0LL, tot_num_div = 0LL;
		for (int i = k * ((a / k) + bool(a % k)); i <= b; i += k)
		{
			answer(i);
			tot_sum_div += sum_div;
			tot_num_div += num_div;
		}
		printf("%lld %lld\n", tot_num_div, tot_sum_div);
	}
	return 0;
}

