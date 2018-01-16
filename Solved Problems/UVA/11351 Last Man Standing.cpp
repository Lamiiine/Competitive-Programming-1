#include<bits/stdc++.h>
using namespace std;
// add one at the end
inline int f(int n, int k){
	if (n == 1)	// only one man left
		return 0;
	return (f(n-1, k) + k) % n;
}
int main(void){
	int TC; scanf("%d", &TC);
	for (int tc = 1, n, k; tc <= TC; ++tc)
		scanf("%d%d", &n, &k), printf("Case %d: %d\n", tc, f(n, k) + 1);
	return 0;
}

