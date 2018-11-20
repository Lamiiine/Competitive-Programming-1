#include<bits/stdc++.h>
#define MAX 100100
using namespace std;
int n;
int occur[MAX], depth[MAX << 1], node[MAX << 1], idx;
int head[MAX], nxt[MAX << 1], to[MAX << 1], en;
int spt[MAX << 1][18];
void dfs(const int i, const int cur_depth, const int parent){
	occur[i] = idx;
	depth[idx] = cur_depth;
	node[idx++] = i;
	for (int j = head[i]; ~j; j = nxt[j]){
		const int k = to[j];
		if (k == parent) continue;
		dfs(k, cur_depth + 1, i);
		depth[idx] = cur_depth;
		node[idx++] = i;
	}
}
inline void build_spt(void){
	for (int i = 0; i < idx; ++i)
		*spt[i] = i;
	for (int j = 1, a, b; (1 << j) <= idx; ++j)
		for (int i = 0; i + (1 << j) <= idx; ++i)
		{
			a = spt[i][j - 1];
			b = spt[i + (1 << (j - 1))][j-1];
			spt[i][j] = depth[a] < depth[b] ? a : b;
		}
}
inline int log_2(int i){
	int ans = -1;
	for(;i; i >>= 1) ++ans;
	return ans;
}
inline int rmq(const int i, const int j){
	int k = log_2(j - i + 1);
	int a = spt[i][k];
	int b = spt[j - (1 << k) + 1][k];
	return depth[a] < depth[b] ? a : b;
}
inline void add_edge(const int i, const int j){
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	++en;
}
inline void add_bi_edge(const int i, const int j){
	add_edge(i, j);
	add_edge(j, i);
}
inline void init(void){
	idx = en = 0;
	memset(head, 0xFF, sizeof head);
}
inline void read(void){
	int x, y;
	for (int i = 1; i < n; ++i){
		scanf("%d%d", &x, &y);
		add_bi_edge(x, y);
	}
}
inline int lca(const int i, const int j){
	return node[rmq(i, j)];
}
inline void solve(void){
	int q; scanf("%d", &q);
	char s[2]; int x;
	set<int> my_nodes;
	while(q--){
		scanf("%s", s);
		if (strlen(s) == 1) scanf("%d", &x);
		else x = atoi(s + 1);
		if (*s == '+')my_nodes.insert(occur[x]);
		else my_nodes.erase(occur[x]);
		printf("%d\n", my_nodes.empty() ? -1 : lca(*my_nodes.begin(), *my_nodes.rbegin()));
	}
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		scanf("%d", &n);
		init();
		read();
		dfs(0, 0, -1);
		build_spt();
		solve();
	}
	return 0;
}

