#include<stdio.h>
#include<algorithm>
#define MAX 45000000LL
using namespace std;
typedef long long int ll;
ll memo[MAX];
void init(void){
	memo[0] = memo[1] = memo[2] = -1;
	for (ll i = 3LL; i < MAX; ++i)
		memo[i] = ((i - 3LL)*i)/2LL;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	init();
	ll N;
	int tc = 0;
	while(scanf("%lld", &N), N)
		printf("Case %d: %d\n", ++tc, lower_bound(memo, memo + MAX, N) - memo);
	return 0;
}

