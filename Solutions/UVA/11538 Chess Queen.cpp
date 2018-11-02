#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll solve(const ll n, const ll m){
	ll rows = m*n*(m - 1);
	ll cols = m*n*(n - 1);
	ll mn = min(n, m);
	ll diags = mn*(mn + 1)*(2LL*mn + 1LL)/3LL - mn*(mn + 1LL) + (n + m - 1 - 2LL*mn)*mn*(mn - 1);
	return rows + cols + 2LL*diags;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int n, m;
	while(scanf("%d%d", &n, &m), n || m)
		printf("%lld\n", solve(ll(n), ll(m)));
	return 0;
}

