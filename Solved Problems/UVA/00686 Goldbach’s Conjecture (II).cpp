#include<bits/stdc++.h>
#define MAX (1 << 15)
using namespace std;
int memo[MAX] = { 0 };
vector<int> primes;
inline void sieve(void)
{
	primes.reserve(MAX / log(MAX));
	bitset<MAX + 10> bs;
	bs.set();
	for (int i = 2; i <= MAX; ++i)
	{
		if (bs[i])
		{
			primes.push_back(i);
			for (int j = i * i; j <= MAX; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}
inline void init_memo(void)
{
	for (int i = 0; i < primes.size(); ++i)
	{
		const int p = primes[i];
		for (int j = i; j < primes.size(); ++j)
		{
			const int sum = p + primes[j];
			if (sum >= MAX)
			{
				break;
			}
			++memo[sum];
		}
	}
}
int main(void)
{
	sieve();
	init_memo();
	for (int x; scanf("%d", &x), x; printf("%d\n", memo[x]));
	return 0;
}

