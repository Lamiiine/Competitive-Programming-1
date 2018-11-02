#include <bits/stdc++.h>
#define MAX 100000000
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
				for (int j = i * i; j < MAX; j += i)
					bs[j] = 0;
		}
}
int main()
{
	sieve();
	// freopen("tmp.txt", "w", stdout);
	for (int n; scanf("%d", &n) != EOF; )
	{
		ii ans = ii(-1, -1);
		if (n & 1)
		{
			// An odd number!
			if (n >= 5 && bs[n - 2])
				ans = ii(2, n - 2);
		}
		else {
			// Loop over all primes to find an answer!
			for (
					auto iter = lower_bound(primes.begin(), primes.end(), (n >> 1) + 1);
					*iter < n;
					++iter)
			{
				const int p2 = *iter;
				const int p1 = n - p2;
				if (bs[p1])
				{
					ans = ii(p1, p2);
					break;
				}
			}
		}
		if (ans == ii(-1, -1))
		{
			printf("%d is not the sum of two primes!\n", n);;
		}
		else
		{
			printf("%d is the sum of %d and %d.\n", n, ans.first, ans.second);;
		}
	}
	return 0;
}

