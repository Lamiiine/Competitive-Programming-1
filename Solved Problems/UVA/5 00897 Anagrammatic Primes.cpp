#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;
vector<int> anagram_primes;
inline void sieve(void)
{
	bitset<MAX + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= MAX; ++i)
	{
		if (bs[i])
		{
			if ((long long int) i * i <= MAX)
			{
				for (int j = i * i; j <= MAX; j += i)
				{
					bs[j] = 0;
				}
			}
		}
	}
	for (int i = 2; i <= MAX; ++i)
	{
		if (bs[i])
		{
			vector<int> digits;
			{
				int x = i;
				while(x)
				{
					digits.push_back(x % 10);
					x /= 10;
				}
			}
			sort(digits.begin(), digits.end());
			bool flag = true;
			do
			{
				int cur_value = 0;
				for (int i = 0; i < digits.size(); ++i)
				{
					cur_value = cur_value * 10 + digits[i];
				}
				if (!bs[cur_value])
				{
					flag = false;
					bs[i] = 0;
					break;
				}
			} while(next_permutation(digits.begin(), digits.end()));
			if (flag)
			{
				anagram_primes.push_back(i);
			}
		}
	}
}
int primes[22] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};
inline int power_10(const int x)
{
	int ans = 1;
	for (int i = 0; i < x; ++i)
		ans *= 10;
	return ans;
}
inline int next_power_10(const int x)
{
	return power_10((int)floor(1 + log10((double) x)));
}
int main(void)
{
	/*
	 * Note that I only used sieve before submitting the problem
	 */
	for (int n; scanf("%d", &n), n;)
	{
		int x = *upper_bound(primes, primes + 22, n);
		printf("%d\n", x < next_power_10(n) ? x : 0);
	}
	return 0;
}

