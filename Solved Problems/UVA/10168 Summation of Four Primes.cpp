#include<bits/stdc++.h>
#define MAX 10000010
#define is_prime(x) (binary_search(primes.begin(), primes.end(), (x)))
using namespace std;
vector<int> primes;
inline void sieve(void)
{
	primes.reserve(MAX / log(MAX));
	bitset<MAX + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= MAX; ++i)
	{
		if (bs[i])
		{
			primes.push_back(i);
			if ((long long int) i * i <= MAX)
			{
				for (int j = i * i; j <= MAX; j += i)
				{
					bs[j] = 0;
				}
			}
		}
	}
}
int main(void)
{
	sieve();
	for (int n; ~scanf("%d", &n);)
	{
		if (n < 8)
		{
			printf("Impossible.\n");
			continue;
		}
		if (n & 1)
		{
			printf("2 3 ");
			n -= 5;
		}
		else
		{
			printf("2 2 ");
			n -= 4;
		}
		for (int i = 0; i < primes.size(); ++i)
		{
			const int p = primes[i];
			if (is_prime(n - p))
			{
				printf("%d %d\n", p, n - p);
				break;
			}
		}
	}
	return 0;
}

