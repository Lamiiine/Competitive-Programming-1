#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
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
	int TC; scanf("%d", &TC);
	for(int l, u; TC--;)
	{
		scanf("%d%d", &l, &u);
		const int start = lower_bound(primes.begin(), primes.end(), l) - primes.begin();
		const int end = upper_bound(primes.begin(), primes.end(), u) - primes.begin();
		map<int, int> m;
		if (end < start + 2)
		{
			printf("No jumping champion\n");
			continue;
		}
		for (int i = start; i < end - 1; ++i)
		{
			int x = primes[i + 1] - primes[i];
			if (m.find(x) == m.end())
			{
				m[x] = 0;
			}
			++m[x];
		}
		int ans, ans_freq = 0;
		bool flag = true;
		for(map<int, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			if (iter->second > ans_freq)
			{
				ans_freq = iter->second;
				ans = iter->first;
			}
		}
		int counter = 0;
		for(map<int, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			if (iter->second == ans_freq)
			{
				++counter;
			}
		}
		if (counter == 1)
		{
			printf("The jumping champion is %d\n", ans);
		}
		else
		{
			printf("No jumping champion\n");
		}
	}
	return 0;
}

