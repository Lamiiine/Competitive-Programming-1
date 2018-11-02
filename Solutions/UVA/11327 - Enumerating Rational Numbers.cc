#include <bits/stdc++.h>
#define MAX 500
#define MAX_K 12158598919LL
using namespace std;
typedef long long ll;
vector<int> primes;
vector<ll> acc;
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
inline int euler_phi(int x)
{
	int ans = x;
	for (int i = 0, p = primes[i]; p * p <= x; p = primes[++i])
		if (x % p == 0)
		{
			ans -= ans / p;
			while (x % p == 0) x /= p;
		}
	if (x != 1)
		ans -= ans / x;
	return ans;
}
inline void preprocess()
{
	acc.push_back(0);
	acc.push_back(2);
	for (int i = 2; acc.back() < MAX_K; ++i)
		acc.push_back((ll) acc.back() + euler_phi(i));
}
int main()
{
	sieve();
	preprocess();
	for (ll k; scanf("%lld", &k), k; )
	{
		if (k == 1LL)
			printf("0/1\n");
		else if (k == 2LL)
			printf("1/1\n");
		else
		{
			const int d = lower_bound(acc.begin(), acc.end(), k) - acc.begin();
			ll missing = k - acc[d - 1];
			int n = 1;
			for (; true; ++n)
				if (__gcd(n, d) == 1 && !--missing)
						break;
			printf("%d/%d\n", n, d);
		}
	}
	return 0;
}

