#include <iostream>
using namespace std;
typedef long long int ll;
inline ll sum(ll n){
	return (n*(n + 1LL)) >> 1LL;
}
int main() {
	int TC; scanf("%d", &TC);
	for (int tc = 1, n; tc <= TC; ++tc)
	{
		printf("Case %d: ", tc);
		scanf("%d", &n);
		ll a = sum(n - 1);
		if (a & 1LL) printf("%lld/%d\n", a, 2);
		else printf("%lld\n", a >> 1LL);
	}
	return 0;
}