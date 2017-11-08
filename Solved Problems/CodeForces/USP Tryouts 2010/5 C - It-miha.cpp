#include<bits/stdc++.h>
#define MAX 1000000LL
#define END 40000000000LL
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
vector<ll> primes;
vector<ll> perfect_squares;
inline void sieve(void)
{
	primes.reserve(MAX / log(MAX));
	bitset<MAX + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= MAX; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j <= MAX; j += i)
				bs[j] = 0;
		}
}
inline void gen_perfect_squares()
{
	perfect_squares.reserve(primes.size());
	for (auto p : primes)
		perfect_squares.push_back(p * p);
}

ull x, ans;
inline void rec(int i, const ull val, const int counter)
{
	// printf("%d %lld %d\n", i, val, counter);
	if (val > x || val < 0ULL)
		return;
	if (counter & 1)
		ans -= x / val;
	else ans += x / val;
	for(;i < perfect_squares.size() && val * ull(perfect_squares[i]) <= x; ++i)
		rec(i + 1, val * ull(perfect_squares[i]), counter + 1);
}
inline ll solve(ll n)
{
	// return the n^th itmiha number
	ll s = 1, e = END;
	while(s != e)
	{
		ans = 0ULL;
		x = (s + e) >> 1LL;
		rec(0, 1LL, 0);
		if (ans < n)
			s = x + 1;
		else e = x;
	}
	return s;
}
int main(void)
{
	sieve();
	gen_perfect_squares();
	int q; cin >> q;
	for (ll n; q--; )
	{
		cin >> n;
		cout << solve(n) << '\n';
	}
}
