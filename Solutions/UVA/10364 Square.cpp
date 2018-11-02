#include<bits/stdc++.h>
#define MAX 20
#define lsone(i) ((i) & (-i))
using namespace std;
int seg_len;
int arr[MAX], n;
inline int count_ones(int i){
	int ans = 0;
	while(i)
		++ans, i >>= 1;
	return ans;
}
inline int sum(const int i){
	int ans = 0;
	for (int j = 0; j < n; ++j)
		if (i & (1 << j)) ans += arr[j];
	return ans;
}
char memo[1 << MAX];
inline char dp(const int i){
	char & ret = memo[i];
	if (ret != -1) return ret;
	int cur_sum = sum(i) % seg_len;
	if (cur_sum){
		for (int j = 0; j < n; ++j)
			if (!(i & (1 << j)) && arr[j] <= seg_len - cur_sum && dp(i | (1 << j)))
				return ret = 1;
		return ret = 0;
	}
	else {
		for (int j = 0; j < n; ++j)
			if (!(i & (1 << j)))
				return ret = dp(i | (1 << j));
		return ret = 0;
	}
}
inline void read(void){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	memo[(1 << n) - 1] = 1;
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		read();
		init();
		seg_len = sum((1 << n) - 1);
		bool flag = true;
		if (seg_len & 3)
			flag = false;
		seg_len >>= 2;
		for (int i = 0; i < n; ++i) if (arr[i] > seg_len) flag = false;
		printf("%s\n", flag && dp(0) ? "yes" : "no");
	}
	return 0;
}
/*
3
4 1 1 1 1
5 10 20 30 40 50
8 1 7 2 6 4 4 3 5
 */

