#include<bits/stdc++.h>
#define MAX (1 << 10)
using namespace std;
typedef long long int ll;
struct rational{
	ll a;
	ll b;
	rational(ll _a, ll _b)
	{
		const ll d = __gcd(_a, _b);
		a = _a / d;
		b = _b / d;
	}

	rational()
	{
		a = 0LL;
		b = 1LL;
	}
};
inline void normalize(rational & r)
{
	ll d = __gcd(r.a, r.b);
	r.a /= d;
	r.b /= d;
}
inline rational operator + (const rational & x, const rational & y)
{
	rational ans(x.a * y.b + y.a * x.b, x.b * y.b);
	normalize(ans);
	return ans;
}
inline rational operator * (const rational & x, const rational & y)
{
	rational ans(x.a * y.a, x.b * y.b);
	normalize(ans);
	return ans;
}
inline rational operator / (const rational & x, const ll d)
{
	rational ans(x.a, x.b * d);
	normalize(ans);
	return ans;
}
inline rational operator / (const rational & x, const rational & y)
{
	rational ans(x.a * y.b, x.b * y.a);
	normalize(ans);
	return ans;
}
inline rational operator - (const rational & x, const rational & y)
{
	rational t(-y.a, -y.b);
	return x + t;
}

ll n;
rational memo[MAX];
inline void init_memo(void)
{
	memo[1] = rational(0, 1);
	memo[2] = rational(1, 2);
	for (ll i = 3; i <= 1010; ++i)
	{
		const rational p = rational(1, i);
		memo[i] = rational(1, 1);
		for (int j = i - 1; j >= 2; --j)
		{
			memo[i] = memo[i] + memo[j];
		}

		memo[i] = memo[i] * p;
	}
}

int main(void)
{
	init_memo();

	while(scanf("%d", &n), n)
	{
		printf("%lld/%lld\n", memo[n].a, memo[n].b);
	}

	return 0;
}
/*

 */

