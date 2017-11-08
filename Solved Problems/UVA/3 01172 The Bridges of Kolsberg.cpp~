#include<bits/stdc++.h>
#define MAX 1010
using namespace std;
int V_os[MAX], U_os[MAX];	// my 2 partite sets
vector<int>occur[MAX];
int V_trade[MAX], U_trade[MAX];
int n, m;			// cardinalities of the 2 partite sets
// Dynamic Programming
int memo[MAX][MAX];
inline int dp(const int i, const int j){
	// start matching knowing that the first free cities are indexed by i and j
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	int ans = dp(i + 1, j);	// don't match i
	vector<int> & v = occur[V_os[i]];
	int my_trade = V_trade[i];
	for (vector<int>::iterator iter = lower_bound(v.begin(), v.end(), j); iter != v.end(); ++iter){
		int k = *iter;
		ans = max(ans, my_trade + U_trade[k] + dp(i + 1, k + 1));
	}
	return ret = ans;
}
// OS id
map<string, int>os_id;
inline int get_os_id(const string & a){
	map<string, int>::iterator x = os_id.find(a);
	if (x == os_id.end()) return os_id[a] = os_id.size();
	return x->second;
}
inline void read(const int n, int * os, int * trade){
	char tmp[15], s[15];
	for (int i = 0; i < n; ++i){
		scanf("%s%s%d", tmp, s, trade + i);
		os[i] = get_os_id(s);
	}
}
inline void read(void){
	scanf("%d", &n);
	read(n, V_os, V_trade);
	scanf("%d", &m);
	read(m, U_os, U_trade);
	for (int i = 0; i < m; ++i)
		occur[U_os[i]].push_back(i);
}
/*
 * Starting at city i, what is the minimum number of cities
 * that you can dp(i, j) with?
 * */
int path_memo[MAX][MAX];
inline void init_memo(void){
	memset(memo, 0xFF, sizeof memo);
	for (int i = 0; i <= n; ++i)
		memo[i][m] = 0;	// no more cities in U
	for (int i = 0; i <= m; ++i)
		memo[n][i] = 0;	// no more cities in V
	memset(path_memo, 0xFF, sizeof path_memo);
	for (int i = 0; i <= n; ++i)
		path_memo[i][m] = 0;	// no more cities in U
	for (int i = 0; i <= m; ++i)
		path_memo[n][i] = 0;	// no more cities in V
}
inline int path(int i, int j){
	int & ret = path_memo[i][j];
	if (ret != -1) return ret;
	const int max_trade = dp(i, j);
	// if you can skip this city, skip it
	int ans = INT_MAX;
	if (dp(i + 1, j) == max_trade) ans = path(i + 1, j);
	vector<int>&v = occur[V_os[i]];
	const int my_trade = V_trade[i];
	for (vector<int>::iterator iter = lower_bound(v.begin(), v.end(), j); iter != v.end(); ++iter)
	{
		int k = *iter;
		if (dp(i + 1, k + 1) + my_trade + U_trade[k] == max_trade)
			ans = min(ans, path(i + 1, k + 1) + 1);
	}
	return ret = ans;
}
inline void init_os(void){
	os_id.clear();
	for (int i = 0; i < MAX; ++i)
		occur[i].clear();
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		init_os();
		read();
		init_memo();
		int max_trade = dp(0, 0);
		printf("%d %d\n", max_trade, path(0, 0));
	}
	return 0;
}

