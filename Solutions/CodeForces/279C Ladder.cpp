#include<bits/stdc++.h>
#define MAX 100100
using namespace std;
/* inc[i] = length of the longest increasing segment starting at i and onward
 * dec[i] = length of the longest decreasing segment starting at i and backward
 * */
int arr[MAX];
int l_dec[MAX], l_inc[MAX];
int n, m;
inline void init(void){
	l_inc[n-1] = 1;
	for (int i = n - 2; i >= 0; --i)
		l_inc[i] = 1 + (arr[i] <= arr[i + 1] ? l_inc[i + 1] : 0);
	l_dec[0] = 1;
	for (int i = 1; i < n; ++i)
		l_dec[i] = 1 + (arr[i] <= arr[i - 1] ? l_dec[i - 1] : 0);
}
inline void read(void){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
}
inline bool ladder(const int start, const int end){
	return l_inc[start] + l_dec[end] > (end - start + 1);
}
inline void solve(void){
	for(int x, y; m--;){
		scanf("%d%d", &x, &y);
		--x; --y;
		printf("%s\n", ladder(x, y) ? "Yes" : "No");
	}
}
int main(void){
	read();
	init();
	solve();
	return 0;
}

