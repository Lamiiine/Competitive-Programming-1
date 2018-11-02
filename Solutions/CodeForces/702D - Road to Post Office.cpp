#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long int ll;
ll d,	// total distance
k,		// distance before car breaks down
a,		// time to drive 1 kilo
b,		// time to walk 1 kilo
t;		// time to fix the car
inline ll solve(void)
{
	ll ans = 0;
	if (b < a)
		// you will walk the whole distance
		return b * d;
	// you will drive a bit first
	if (d <= k)
		return d * a;
	d -= k;
	ans += k * a;
	// what is the minimal time to go for k kilometers
	if (a * k + t > b * k)
		return ans + d * b;
	ans += (a * k + t) * (d / k);
	d %= k;
	return ans + min(t + a * d, b * d);
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
#endif
	cin >> d >> k >> a >> b >> t;
	cout << solve();
	return 0;
}