#include<bits/stdc++.h>
using namespace std;
long double memo[105][10];
int n, k;
inline void init_memo(void){
	for (int i = 0; i < 105; ++i)
		for (int j = 0; j < 10; ++j)
			memo[i][j] = (i) ? -1.0 : 1.0;
}
inline long double dp(const int i, const int j){
	long double & ret = memo[i][j];
	if (ret != -1.0) return ret;
	long double ans = 0.0;
	for (int t = 0; t < k; ++t)
		if (abs(j - t) <= 1)
			ans += dp(i - 1, t);
	return ret = (long double) ans / k;
}
int main(void){
	while(~scanf("%d%d", &k, &n)){
		++k;
		init_memo();
		long double ans = 0.0;
		for (int i = 0; i < k; ++i)
			ans += dp(n-1, i);
		ans /= (long double) k;
		printf("%.5llf\n", (long double)ans * 100.0);
	}
	return 0;
}

