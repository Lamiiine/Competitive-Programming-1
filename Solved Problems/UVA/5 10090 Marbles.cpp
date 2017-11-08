#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll x, y, d;
void euclid(ll a, ll b){
	if (b){
		euclid(b, a % b);
		ll x1 = y;
		ll y1 = x - (a/b)*y;
		x = x1; y = y1;
	}
	else {
		d = a;
		x = 1; y = 0;
	}
}
int main(void){
	ll n;
	while(scanf("%lld", &n), n){
		ll c1, n1, c2, n2;
		scanf("%lld%lld%lld%lld", &c1, &n1, &c2, &n2);
		euclid(n1, n2);
		if (n % d){
			printf("failed\n");
			continue;
		}
		else {
			ll tmp = n/d;
			x *= tmp; y *= tmp;
		}
		ll x_factor = n2/d;
		ll y_factor = n1/d;
		ll upper = y/y_factor;
		if (y < 0 && y % y_factor)--upper;
		ll lower = (-x)/x_factor;
		if (x < 0 && x%x_factor) ++lower;
		if (lower > upper) {
			printf("failed\n");
			continue;
		}
		ll k = lower;
		if ( double((double)c1/n1) < double((double)c2/n2)){
			// maximize x
			k = upper;
		}
		else {
			// minimize x
			k = lower;
		}
		x += k*x_factor;
		y -= k*y_factor;
		printf("%lld %lld\n", x, y);
	}
	return 0;
}

