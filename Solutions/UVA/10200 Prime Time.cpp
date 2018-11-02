#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
vector<int> primes;
inline void sieve(void)
{
	const int N = MAX << 1;
	primes.reserve(N / log(N));
	bitset<N + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= N; ++i)
	{
		if (bs[i])
		{
			primes.push_back(i);
			for (int j = i * i; j <= N; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}
inline bool is_prime(const int x)
{
	if (x <= MAX)
	{
		return binary_search(primes.begin(), primes.end(), x);
	}
	for (int i = 0; i < primes.size(); ++i)
	{
		const int p = primes[i];
		if (p * p > x)
		{
			break;
		}
		if (x % p == 0)
		{
			return false;
		}
	}
	return true;
}
int memo[MAX + 10];
inline void init_memo(void)
{
	memo[0] = 1;
	for (int i = 1; i <= MAX; ++i)
	{
		memo[i] = memo[i - 1] + is_prime(i * i + i + 41);
	}
}
int main(void)
{
	sieve();
	init_memo();
	for (int a, b; ~scanf("%d%d", &a, &b);)
	{
		printf("%.2lf\n", (double) 100.0 * (memo[b] - (a ? memo[a - 1] : 0)) / (b - a + 1) + 1e-9);
	}
	return 0;
}

