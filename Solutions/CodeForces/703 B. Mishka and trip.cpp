#include<bits/stdc++.h>
#define MAX 100100
using namespace std;
typedef long long int ll;
int val[MAX];
int acc[MAX];
char cap[MAX];
ll sum;
int n, k;
inline void read_val(void){
	for (int i = 0; i < n; ++i)
		scanf("%d", val + i);
}
inline void calc_sum(void){
	sum = 0LL;
	for (int i = 0; i < n; ++i)
		sum += val[i];
}
int main(void){
	memset(cap, 0, sizeof cap);
	ll ans = 0LL;
	scanf("%d%d", &n, &k);
	read_val();
	calc_sum();
	for (int i = 0; i < n - 1; ++i)
		ans += val[i]*val[i + 1];
	ans += val[n-1]*val[0];
	for (int i = 0, x; i < k; ++i){
		scanf("%d", &x); --x;
		int neighbor_1 = (x + 1) % n;
		int neighbor_2 = (x - 1 + n) % n;
		ll my_sum = sum - val[x];
		if (!cap[neighbor_1]) my_sum -= val[neighbor_1];
		if (!cap[neighbor_2]) my_sum -= val[neighbor_2];
		ans += my_sum*val[x];
		sum -= val[x];
		cap[x] = true;
	}
	cout << ans;
}

