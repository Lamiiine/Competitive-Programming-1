#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
vector<int> primes;
inline void sieve(void)
{
	primes.reserve(MAX / log(MAX));
	primes.push_back(1);
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
inline void print(const int start, const int end)
{
	for (int i = start; i < end; ++i)
	{
		printf(" %d", primes[i]);
	}
	printf("\n");
}
int main(void)
{
	sieve();
	for (int n, c; ~scanf("%d%d", &n, &c);)
	{
		printf("%d %d:", n, c);
		const int num = (upper_bound(primes.begin(), primes.end(), n) - primes.begin());
		c = (c << 1) - (num & 1);
		if (c >= num)
		{
			print(0, num);
		}
		else
		{
			const int start = (num - c) >> 1;
			print(start, start + c);
		}
		printf("\n");
	}
	return 0;
}

