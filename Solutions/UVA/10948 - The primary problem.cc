#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<int> primes;
bitset<MAX> bs;

inline void sieve()
{
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
int main()
{
	sieve();
	for (int n; scanf("%d", &n), n; )
	{
		int ans = -1;
		for (int i = 0, p = primes[0]; i < primes.size() && p <= n/2; p = primes[++i])
			if (bs[n - p])
			{
				ans = p; break;
			}
		printf("%d:\n", n);
		if (ans == -1)
			printf("NO WAY!");
		else
			printf("%d+%d", ans, n - ans);
		printf("\n");
	}
	return 0;
}

