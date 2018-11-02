#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> primes;
vector<ll> t_primes;
inline void sieve()
{
	const int bound = 1000000;
	bitset<bound + 1> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= bound; ++i)
	{
		if (bs[i])
		{
			primes.push_back(i);
			if ((ll) 1LL * i * i <= bound)
			for (int j = i * i; j <= bound; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}
int main()
{
	sieve();
	for (int p : primes)
	{
		t_primes.push_back((ll) p * p);
	}
	int n; cin >> n;
	for(ll x; n--; )
	{
		cin >> x;
		cout << (binary_search(t_primes.begin(), t_primes.end(), x) ? "YES" : "NO") << endl;
	}
	return 0;
}
