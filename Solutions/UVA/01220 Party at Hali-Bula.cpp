#include <bits/stdc++.h>
#define MAX 205
using namespace std;
map<string, int> m;
char a[110], b[110];
int head[MAX], to[MAX], nxt[MAX], en;
inline void add_edge(const int i, const int j){
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	++en;
}
int get_index(const string str){
	auto x = m.find(str);
	if (x == m.end()) {int v = m.size(); return m[str] = v;}
	else return x->second;
}
int n;
int memo[MAX][2];
inline int dp(const int i, const int j){
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	// 1. do not count in employee i
	int ans = 0;
	for (int k = head[i]; ~k; k = nxt[k])
		ans += dp(to[k], 0);
	if (j)	// you have no other options
		return ret = ans;
	// 2. count int employee i
	int ans_2 = 0;
	for (int k = head[i]; ~k; k = nxt[k])
		ans_2 += dp(to[k], 1);
	return ret = max(ans, ans_2 + 1);
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	memset(head, 0xFF, sizeof head);
	en = 0;
	m.clear();
}
inline void read(void){
	scanf("%s", a);
	get_index(a);
	for (int i = 1; i < n; ++i){
		scanf("%s%s", a, b);
		add_edge(get_index(b), get_index(a));
	}
}
inline bool is_unique(const int i, const int j){
	int ans = dp(i, j);
	int ans_1 = 0, ans_2 = 1;
	for (int k = head[i]; ~k; k = nxt[k]){
		ans_1 += dp(to[k], 0);
		ans_2 += dp(to[k], 1);
	}
	if (!j){
		// we have two options!
		if (ans_1 == ans_2) return false;
		if (ans_1 > ans_2){
			// validate answer 1
			for (int k = head[i]; ~k; k = nxt[k])
				if (!is_unique(to[k], 0)) return false;
			return true;
		}
		else {
			// validate answer 2
			for (int k = head[i]; ~k; k = nxt[k])
				if (!is_unique(to[k], 1)) return false;
			return true;
		}
	}
	// validate answer 1
	for (int k = head[i]; ~k; k = nxt[k])
		if (!is_unique(to[k], 0)) return false;
	return true;
}
int main() {
	while(scanf("%d", &n), n){
		init();
		read();
		printf("%d %s\n", dp(0, 0), is_unique(0, 0) ? "Yes" : "No");
	}
	return 0;
}
