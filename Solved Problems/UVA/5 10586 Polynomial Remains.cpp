#include<bits/stdc++.h>
#define MAX 10010
using namespace std;
int n, k;
int c[MAX];
inline void read(void){
	for (int i = 0; i <= n; ++i)
		scanf("%d", c + i);
}
inline void solve(void){
	while(n >= k){
		// subtract (ax^n + ax^(n-k))
		c[n-k] -= c[n];
		--n;
	}
}
inline void print(void){
	n = max(n, 0);
	while(n > 0 && !c[n])--n;
	for (int i = 0; i <= n; ++i)
		printf("%d%c", c[i], " \n"[i == n]);
}
int main(void){
	while(scanf("%d%d", &n, &k), n != -1 || k != -1){
		read();
		solve();
		print();
	}
	return 0;
}

