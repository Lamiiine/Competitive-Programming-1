#include<bits/stdc++.h>
#define MAX 2005
using namespace std;
int memo[MAX][MAX];
int arr[MAX];
int a, n;
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
}
inline int dp(const int i, const int j){
	if (j < i) return 0;
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	// len(i, j) == n -> pow = 1
	return ret = max((n - (j - i))*arr[i] + dp(i + 1, j), (n - (j - i))*arr[j] + dp(i, j - 1));
}
inline void read(void){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
}
int main(void){
	read();
	init();
	printf("%d\n", dp(0, n - 1));
	return 0;
}

