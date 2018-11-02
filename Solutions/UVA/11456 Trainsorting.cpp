#include<bits/stdc++.h>
#define MAX 2010
using namespace std;
int n;
int arr[MAX];
int memo1[MAX][MAX];
int memo2[MAX][MAX];
inline int dp1(const int i, const int j){
	int & ret = memo1[i][j];
	if (ret != -1) return ret;
	if (arr[j] < arr[i]) return ret = dp1(i, j + 1);
	return ret = max(dp1(i, j + 1), 1 + dp1(j, j + 1));
}
inline int dp2(const int i, const int j){
	int & ret = memo2[i][j];
	if (ret != -1) return ret;
	if (arr[j] > arr[i]) return ret = dp2(i, j + 1);
	return ret = max(dp2(i, j + 1), 1 + dp2(j, j + 1));
}
inline void read(void){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
}
inline void init(void){
	memset(memo1, 0xFF, sizeof memo1);
	memset(memo2, 0xFF, sizeof memo2);
	for (int i = 0; i < MAX; ++i)
		memo1[i][n] = memo2[i][n] = 0;
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		read();
		init();
		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans = max(ans, 1 + dp1(i, i + 1) + dp2(i, i + 1));
		printf("%d\n", ans);
	}
	return 0;
}

