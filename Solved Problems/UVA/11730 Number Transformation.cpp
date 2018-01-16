#include<bits/stdc++.h>
#define MAX 1024
#define OO (1 << 15)
using namespace std;
vector<int> primes;
int memo[MAX];
int s, t;
inline void sieve(void)
{
	primes.reserve(MAX / log(MAX));
	bitset<MAX + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= MAX; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			for (int j = i * i; j <= MAX; j += i)
				bs[j] = 0;
		}
}
inline vector<int> factorize(int x)
{
	vector<int> ans;
	for (int i = 0, p = 2; p * p <= x; p = primes[++i])
		if (x % p == 0)
		{
			ans.push_back(p);
			while(x % p == 0) x /= p;
		}
	if (x != 1 && !ans.empty())
		ans.push_back(x);
	return ans;
}
vector<int> factors[MAX];
inline void factorize_all(void)
{
	for (int i = 1; i < MAX; ++i)
		factors[i] = factorize(i);
}
inline void init(void)
{
	memset(memo, -1, sizeof memo);
}
inline int dp(const int i)
{
	// memory
	int & ret = memo[i];
	if (ret != -1) return ret;
	// base
	if (i == t) return ret = 0;
	// recursion
	ret = OO;
	for (int j = 0; j < factors[i].size(); ++j)
		if (i + factors[i][j] <= t)
			ret = min(ret, 1 + dp(i + factors[i][j]));
	return ret;
}
int main(void)
{
	sieve();
	factorize_all();
	for(int tc = 1; scanf("%d%d", &s, &t), s || t; ++tc)
	{
		init();
		const int ans = dp(s);
		printf("Case %d: %d\n", tc, ans >= OO ? -1 : ans);
	}
	return 0;
}
