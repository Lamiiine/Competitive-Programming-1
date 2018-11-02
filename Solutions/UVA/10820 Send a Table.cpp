#define MAX 50005
#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
inline void sieve(void)
{
	const int N = 500;
	bitset<N + 10> bs;
	bs.set();
	for (int i = 2; i <= N; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			for (int j = i * i; j <= N; j += i)
				bs[j] = 0;
		}
}
int n;
int memo[MAX];
inline int euler_phi(int x)
{
	int ans = x;
	for (int i = 0, p = 2; p * p <= x; p = primes[++i])
		if (x % p == 0)
		{
			ans -= ans / p;
			while(x % p == 0) x /= p;
		}
	if (x != 1)
		ans -= ans / x;
	return ans;
}
inline void init(void)
{
	memo[1] = 1;
	for (int i = 2; i < MAX; ++i)
		memo[i] = memo[i - 1] + 2 * euler_phi(i);
}
int main()
{
	sieve();
	init();
	while(scanf("%d", &n), n)
		printf("%d\n", memo[n]);
	return 0;
}

