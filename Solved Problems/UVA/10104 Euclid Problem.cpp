#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll x, y, d;
void euclid(ll a, ll b){
	if (b){
		euclid(b, a %b);
		ll x1 = y;
		ll y1 = x - (a/b)*y;
		x = x1; y = y1;
	}
	else {
		d = a;
		x = 1;
		y = 0;
	}
}
int main(void){
	for (int a, b;~scanf("%d%d", &a, &b);)
	{
		euclid(a, b);
		printf("%d %d %d\n", x, y, d);
	}
	return 0;
}

