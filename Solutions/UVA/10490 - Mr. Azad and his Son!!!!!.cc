#include <bits/stdc++.h>
#define MAX (1 << 16)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<int> primes;

inline void sieve()
{
	bitset<MAX> bs;
	primes.reserve(MAX / log(MAX));
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i < MAX; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			if (1LL * i * i < MAX)
				for (int j = i * i; j < MAX && j > 0; j += i)
					bs[j] = 0;
		}
}
inline bool is_prime(const ll x)
{
	for (ll i = 0, p = primes[0]; p * p <= x; p = primes[++i])
		if (x % p == 0)
			return false;
	return true;
}
inline bool is_perfect(const int n)
{
	return is_prime(n) && is_prime((1LL << n) - 1LL);
}
inline ll compute_perfect(const int n)
{
	return (1LL << (n - 1LL)) * ((1LL << n) - 1LL);
}
int main()
{
	sieve();
	for (int n; scanf("%d", &n), n; )
	{
		if (is_perfect(n))
		{
			// Perfect!
			printf("Perfect: %lld!\n", compute_perfect(n));
		}
		else if (is_prime(n))
			printf("Given number is prime. But, NO perfect number is available.\n");
		else
			printf("Given number is NOT prime! NO perfect number is available.\n");
	}
	return 0;
}

