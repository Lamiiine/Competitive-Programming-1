#include <bits/stdc++.h>
#define MAX 40000
using namespace std;
typedef long long ll;
vector<int> primes;
inline void sieve()
{
	bitset<MAX> bs;
	bs.set(); bs[0] = bs[1] = 0;
	for (int i = 2; i < MAX; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			if (1LL * i * i < MAX)
				for (int j = i * i; j < MAX; j += i)
					bs[i] = 0;
		}
}
inline int euler_phi(int x)
{
	int ans = x;
	for (int i = 0, p = primes[0]; p * p <= x; p = primes[++i])
		if (x % p == 0)
		{
			ans -= ans / p;
			while (x % p == 0) x /= p;
		}
	if (x != 1) ans -= ans/x;
	return ans;
}
int main()
{
	sieve();
	for (int n; scanf("%d", &n), n; )
	{
		printf("%d\n", n == 1 ? 0 : euler_phi(n));
	}
	return 0;
}

