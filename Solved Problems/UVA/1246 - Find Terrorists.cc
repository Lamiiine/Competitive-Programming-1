#include <bits/stdc++.h>
#define bound 1000
#define MAX 10005
using namespace std;
vector<int> primes;
vector<int> valid;
inline void sieve()
{
	bitset<bound> bs;
	bs.set(); bs[0] = bs[1] = 0;
	for (int i = 2; i < bound; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			for (int j = i * i; j < bound; j += i)
				bs[i] = 0;
		}
}
inline int num_factors(int x)
{
	int ans = 1;
	for (int i = 0, p = primes[i]; p * p <= x; p = primes[++i])
	{
		int power = 0;
		while (x % p == 0) x /= p, ++power;
		if (power) ans *= (power + 1);
	}
	if (x != 1)
		ans *= 2;
	return ans;
}
inline bool is_prime(const int x)
{
	if (x == 1) return false;
	for (int i = 0, p = primes[i]; p * p <= x; p = primes[++i])
		if (x % p == 0) return false;
	return true;
}
inline void preprocess()
{
	for (int i = 2; i < MAX; ++i)
		if(is_prime(num_factors(i)))
			valid.push_back(i);
}
int main()
{
	sieve();
	preprocess();
	int TC; scanf("%d", &TC);
	// for (const auto x : valid) printf("%d\n", x);
	for (int l, h; TC--; )
	{
		scanf("%d%d", &l, &h);
		bool flag = false;
		for (auto iter = lower_bound(valid.begin(), valid.end(), l); iter != valid.end() && *iter <= h; ++iter)
			printf("%s%d", flag ? " " : "", *iter), flag = true;
		if (!flag) printf("-1");
		printf("\n");
	}
	return 0;
}

