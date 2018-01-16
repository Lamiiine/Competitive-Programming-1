#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n[2], f[2], d[2];

ll x, y, gcd;
void euclid(const ll a, const ll b)
{
	if (b)
	{
		euclid(b, a % b);
		const ll x1 = y;
		const ll y1 = x - (a/ b) * y;
		x = x1;
		y = y1;
	}
	else
	{
		x = 1; y = 0; gcd = a;
	}
}

int main()
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		for (int i = 0; i < 2; ++i)
		{
			cin >> n[i] >> f[i] >> d[i];
		}
		vector<ll> v[2];
		for (int i = 0; i < 2; ++i)
		{
			vector<ll> & cur = v[i];
			cur.push_back(f[i]);
			ll counter = 1LL;
			while(cur.back() < 1000000 && counter < n[i])
				cur.push_back(cur.back() + d[i]), ++counter;
		}
		ll first_meet;
		for (const ll p : v[0])
		{
			if (binary_search(v[1].begin(), v[1].end(), p))
			{
				first_meet = p;
				break;
			}
		}
		ll x[2];
		for (int i = 0; i < 2; ++i)
			x[i] = (first_meet - f[i]) / d[i] + 1;
		const ll lcm = d[1] * (d[0] / __gcd(d[1], d[0]));
		ll y[2];
		for (int i = 0; i < 2; ++i)
			y[i] = (n[i] - x[i]) / (lcm / d[i]);
		cout << 1 + min(y[0], y[1]) << endl;
	}
	return 0;
}
/*
3
5 3 4 15 3 1
10 2 2 7 3 3
100 1 1 100 1 2
 */

