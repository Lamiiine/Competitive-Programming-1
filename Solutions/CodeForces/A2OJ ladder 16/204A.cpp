#include <bits/stdc++.h>
#define MAX 128
#define avg(a, b) (((a) + (b)) >> 1)
using namespace std;
typedef long long int ll;
ll l, r;
inline ll most_significant(ll x)
{
	while (x >= 10LL) x /= 10LL;
	return x;
}
inline ll least_significant(ll x)
{
	return x % 10LL;
}
inline bool is_nice(const ll x)
{
	return most_significant(x) == least_significant(x);
}
inline ll brute_force(const ll l, const ll r)
{
	ll ans = 0;
	for (ll x = l; x <= r; ++x)
	{
		ans += is_nice(x);
	}
	return ans;
}
inline int num_digits(ll x)
{
	int ans = 0;
	while(x) x /= 10, ++ans;
	return ans;
}
inline ll query(ll l, ll r)
{
	if (most_significant(l) == most_significant(r) && num_digits(l) == num_digits(r))
	{
		const int d = most_significant(l);
		while (least_significant(l) != d) ++l;
		while(least_significant(r) != d) --r;
		if (r < l) return 0LL;
		return (r - l) / 10LL + 1LL;
	}
	else
	{
		return query(l, avg(l, r)) + query(avg(l, r) + 1, r);
	}
}
inline void test()
{
	for (int l = 1; l <= 1000; ++l)
	{
		for (int r = l; r <= 1000; ++r)
		{
			if (query(l, r) != brute_force(l, r))
			{
				cout << "Error at " << l << ", " << r << endl;
			}
		}
	}
}
int main()
{
	// test();
	cin >> l >> r;
	cout << query(l, r);
	return 0;
}

