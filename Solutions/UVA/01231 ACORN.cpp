#include<bits/stdc++.h>
#define MAX 2005
using namespace std;
inline int dp_1(const int i);
inline int dp(const int i, const int j);
int memo[MAX][MAX];
int memo_1[MAX];
int acron[MAX][MAX];
int t, f, h;
inline int dp_1(const int i){
	if (i < 0) return 0;
	int & ret = memo_1[i];
	if (ret != -1) return ret;
	int ans = 0;
	for (int j = 0; j < t; ++j)
		ans = max(ans, dp(j, i));
	return ret = ans;
}
inline int dp(const int i, const int j){
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	return ret = acron[i][j] + max(dp(i, j-1), dp_1(j - f));
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	memset(memo_1, 0xFF, sizeof memo_1);
	for (int i = 0; i < t; ++i)
		memo[i][0] = acron[i][0];
}
inline void read(void){
	scanf("%d%d%d", &t, &h, &f);
	for (int i = 0; i < t; ++i){
		int * cur_tree = acron[i];
		memset(cur_tree, 0, sizeof acron[0]);
		int a; scanf("%d", &a);
		for (int x; a--;){
			scanf("%d", &x);
			++cur_tree[x];
		}
	}
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		read();
		init();
		printf("%d\n", dp_1(h));
	}
	return 0;
}

