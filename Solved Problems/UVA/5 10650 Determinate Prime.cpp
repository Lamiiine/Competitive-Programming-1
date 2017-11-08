#include<bits/stdc++.h>
#define MAX (1 << 16)
using namespace std;
vector<int> primes;
int a, b;
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
			if ((long long int) i * i <= MAX)
			for (int j = i * i; j <= MAX; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}
inline void solve(void)
{
	const int s = lower_bound(primes.begin(), primes.end(), a) - primes.begin();
	const int e = upper_bound(primes.begin(), primes.end(), b) - primes.begin();
	for (int i = s; i < e;++i)
	{
		// search for a set starting here!
		int j = i + 1;
		const int d = primes[j] - primes[i];
		while(primes[j] - primes[j - 1] == d)
		{
			++j;
		}
		if (j - i >= 3 && j - 1 < e)
		{
			// print
			if (!(i == s && i > 0 && primes[i] - primes[i - 1] == d))
			{
				for (int k = i; k < j; ++k)
				{
					printf("%d%c", primes[k], k == j - 1 ? '\n' : ' ');
				}
			}
			i = j - 2;
		}
	}
}
int main(void)
{
	sieve();
	for(int x, y; scanf("%d%d", &x, &y), x || y;)
	{
		a = min(x, y); b = max(x, y);
		solve();
	}
	return 0;
}

