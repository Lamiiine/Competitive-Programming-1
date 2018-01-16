#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
typedef long long int ll;
int memo[MAX + 10];
inline int sum_digits(int x)
{
	int ans = 0;
	while(x)
	{
		ans += (x % 10);
		x /= 10;
	}
	return ans;
}
inline void sieve(void)
{
	memset(memo, 0, sizeof memo);
	bitset<MAX + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= MAX; ++i)
	{
		if (bs[i])
		{
			for (ll j = i * i; j <= MAX; j += i)
			{
				bs[j] = 0;
			}
		}
	}
	for (int i = 2; i <= MAX; ++i)
	{
		if ((bs[i] && bs[sum_digits(i)]))
		{
			memo[i] = 1;
		}
	}
	for (int i = 1; i <= MAX; ++i)
	{
		memo[i] += memo[i - 1];
	}
}
int main(void)
{
	sieve();
	int TC; scanf("%d", &TC);
	for(int x, y; TC--; printf("%d\n", memo[y] - memo[--x]))
	{
		scanf("%d%d", &x, &y);
	}
	return 0;
}

