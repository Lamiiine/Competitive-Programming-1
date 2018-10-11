#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef long long ll;
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
inline int solve(const int n)
{
	int ans_p, ans = 0;
	for (int i = 0, p = primes[0]; i < primes.size() && p <= n; p = primes[++i])
	{
		int x = n / p;
		int cur = n - p * x;
		if (cur > ans)
			ans = cur, ans_p = p;
	}
	return ans_p;
}
int main()
{
	sieve();
	int TC; scanf("%d", &TC);
	for (int n; TC--; )
	{
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
	return 0;
}

