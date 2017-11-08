#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>len;
vector<int>wid;
vector<vector<int>>memo;
inline void read(void){
	scanf("%d", &n);
	len.resize(n);
	wid.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &len[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &wid[i]);
}
inline int dp_inc(const int i, const int j){
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	if (len[j] > len[i]) return ret = max(dp_inc(i, j + 1), wid[j] + dp_inc(j, j + 1));
	return ret = dp_inc(i, j + 1);
}
inline int dp_dec(const int i, const int j){
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	if (len[j] < len[i]) return ret = max(dp_dec(i, j + 1), wid[j] + dp_dec(j, j + 1));
	return ret = dp_dec(i, j + 1);
}
inline void init_memo(void){
	memo.resize(n);
	for (int i = 0; i < n; ++i){
		memo[i].assign(n + 1, -1);
		memo[i][n] = 0;
	}
}
int main(void){
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		read();
		int ans_inc = 0, ans_dec = 0;
		init_memo();
		for (int i = 0; i < n; ++i)
			ans_inc = max(ans_inc, wid[i] + dp_inc(i, i + 1));
		init_memo();
		for (int i = 0; i < n; ++i)
			ans_dec = max(ans_dec, wid[i] + dp_dec(i, i + 1));
		printf("Case %d. ", tc);
		if (ans_inc >= ans_dec)
			printf("Increasing (%d). Decreasing (%d).", ans_inc, ans_dec);
		else printf("Decreasing (%d). Increasing (%d).", ans_dec, ans_inc);
		printf("\n");
	}
	return 0;
}

