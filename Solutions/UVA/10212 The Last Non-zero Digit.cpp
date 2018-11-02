#include<bits/stdc++.h>
#define MAX 20000000
using namespace std;
int rem[MAX + 1];
int inv[10];
inline int normalize(int x){
	while (x % 5 == 0) x /= 5;
	while(!(x & 1)) x >>= 1;
	return x;
}
inline int power(int p, int n){
	int ans = 0;
	int temp = p;
	while (temp <= n)
		ans += n/temp, temp *= p;
	return ans;
}
inline void init(void){
	inv[1] = 1, inv[3] = 7, inv[7] = 3, inv[9] = 9;
	rem[0] = rem[1] = 1;
	for (int i = 2; i <= MAX; ++i)
		rem[i] = (normalize(i) * rem[i - 1]) % 10;
}
inline int solve(int n, int m){
	if (!m) return 1;
	m = n - m;
	int ans = (rem[n]*inv[rem[m]]) % 10;
	int power_2 = power(2, n) - power(2, m);
	int power_5 = power(5, n) - power(5, m);
	int j = min(power_2, power_5);
	power_2 -= j, power_5 -= j;
	while(power_2--) ans = (ans << 1) % 10;
	while(power_5--) ans = (ans * 5) % 10;
	return ans;
}
int main(void){
	init();
	for (int n, m; scanf("%d%d", &n, &m) != EOF;)
		printf("%d\n", solve(n, m));
	return 0;
}

