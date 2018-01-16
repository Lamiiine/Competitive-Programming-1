#include<bits/stdc++.h>
#define MAX 30
using namespace std;
typedef long long int ll;
ll cat_memo[MAX];
ll sup_cat_memo[MAX];
inline void init(void){
	cat_memo[0] = 1;
	sup_cat_memo[1] = sup_cat_memo[2] = 1;
	for (int i = 1; i < MAX; ++i)
		cat_memo[i] = 2*(2*i - 1)*cat_memo[i-1]/(i + 1);
	for (int i = 3; i < MAX; ++i)
		sup_cat_memo[i] = ((6*i - 9)*sup_cat_memo[i-1] + (3 - i)*sup_cat_memo[i-2])/i;
}
int main(void){
	init();
	for (int n; scanf("%d", &n) != EOF; printf("%lld\n", sup_cat_memo[n] - cat_memo[n - 1]));
	return 0;
}

