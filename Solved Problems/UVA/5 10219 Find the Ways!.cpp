#include<stdio.h>
#include<math.h>
#include<algorithm>
typedef double ld;
int n, k;
int solve(void){
	k = std::max(k, n - k);
	ld ans = 0.0;
	for (int i = k + 1; i <= n; ++i)
		ans += log10((ld)i);
	for (int i = 2; i <= n - k; ++i)
		ans -= log10((ld)i);
	return (int) floor(1 + ans);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d%d", &n, &k) != EOF)
		printf("%d\n", solve());
}

