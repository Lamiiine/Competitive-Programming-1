#include<algorithm>
#include<stdio.h>
#include<vector>
#include<bitset>
#define MAX (1LL << 16LL)
using namespace std;
typedef long long int ll;
vector<ll> primes;
inline void sieve(void)
{
	bitset<MAX + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2LL; i <= MAX; ++i)
	if (bs[i])
	{
		primes.push_back(i);
		for (ll j = i * i; j <= MAX; j += i)
			bs[j] = 0;
	}
}
typedef pair<ll, int> lli;
inline vector<lli> factorize(ll x)
{
	vector<lli> ans;
	for (ll i = 0LL, p = 2LL; p * p <= x; p = primes[++i])
	{
		int counter = 0;
		while (x % p == 0LL) ++counter, x /= p;
		if (counter) ans.push_back(lli(p, counter));
	}
	if (x != 1LL) ans.push_back(lli(x, 1));
	return ans;
}
ll c,	// original number of cookies
r;		// remainder
vector<lli> factors;
vector<ll> divisors;
ll cur;
inline void gen_div(const int i)
{
	if (i == factors.size())
		divisors.push_back(cur);
	else
	{
		for (int j = 0; j <= factors[i].second; ++j)
		{
			gen_div(i + 1);
			cur *= factors[i].first;
		}
		for (int j = 0; j <= factors[i].second; ++j)
			cur /= factors[i].first;
	}
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
#endif
	sieve();
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		printf("Case #%d:", tc);
		scanf("%lld%lld", &c, &r);
		if (c - r <= 0LL)
			printf(" 0");
		else
		{
			factors = factorize(c - r);
			divisors.clear();
			cur = 1LL;
			gen_div(0);
			sort(divisors.begin(), divisors.end());
			for (int start = upper_bound(divisors.begin(), divisors.end(), r) - divisors.begin(); start < divisors.size(); ++start)
				printf(" %lld", divisors[start]);
		}
		printf("\n");
	}
	return 0;
}
