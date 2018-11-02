#include<bits/stdc++.h>
#define MAX 100100
using namespace std;
int last[MAX];
int memo[MAX];
int arr[MAX];
inline void init(void){
	memset(last, 0xFF, sizeof last);
}
int n;
inline void read(void){
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
}
inline void solve(void){
	memo[0] = 0;
	last[arr[0]] = 0;
	for (int i = 1; i < n; ++i){
		int x = arr[i];
		if (last[x] == -1) memo[i] = memo[i-1];
		else memo[i] = max(memo[i-1], memo[last[x]] + (x == 999 ? 3 : 1));
		last[x] = i;
	}
}
int main(void){
	while(scanf("%d", &n), n){
		read();
		init();
		solve();
		printf("%d\n", memo[n-1]);
	}
	return 0;
}

