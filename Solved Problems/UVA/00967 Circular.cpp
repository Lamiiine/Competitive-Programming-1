#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
vector<int>circ_primes;
inline void sieve(void)
{
	bitset<MAX + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= MAX; ++i)
	{
		if (bs[i] && (long long int) i * i <= MAX)
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				bs[j] = 0;
			}
		}
	}
	for (int i = 2; i <= MAX; ++i)
	{
		if (bs[i])
		{
			bool flag = true;
			vector<int>d;
			int x = i;
			while(x)
			{
				d.push_back(x % 10);
				x /= 10;
			}
			for (int j = 0; j < (d.size() >> 1); ++j)
			{
				swap(d[j], d[d.size() - 1 - j]);
			}
			for (int start = 0; start < d.size(); ++start)
			{
				int cur_value = 0;
				for (int j = 0; j < d.size(); ++j)
				{
					cur_value = (cur_value * 10) + d[(j + start) % d.size()];
				}
				if (!bs[cur_value])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				circ_primes.push_back(i);
			}
		}
	}
}
int main(void)
{
	sieve();
	for (int x, y; scanf("%d", &x), x != -1;)
	{
		scanf("%d", &y);
		const int ans = upper_bound(circ_primes.begin(), circ_primes.end(), y) - lower_bound(circ_primes.begin(), circ_primes.end(), x);
		if (ans == 0)
		{
			printf("No Circular Primes.");
		}
		else if (ans == 1)
		{
			printf("1 Circular Prime.");
		}
		else
		{
			printf("%d Circular Primes.", ans);
		}
		printf("\n");
	}
	return 0;
}

