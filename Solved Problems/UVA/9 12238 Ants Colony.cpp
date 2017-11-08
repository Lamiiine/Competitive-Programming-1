#include<bits/stdc++.h>
#define MAX 100100
using namespace std;
typedef long long int ll;
int n;
int head[MAX], nxt[MAX << 1], to[MAX << 1], cost[MAX << 1], en;
ll dist[MAX];
/* Storing:
 * - First occurence of node i
 * - idx of node visited at time i
 * - depth of node visited at time i
 * */
int occur[MAX], node[MAX << 1], depth[MAX << 1];
ll cur_dist;
int cur_depth;
int idx;
inline void dfs(int i, int parent){
	occur[i] = idx;
	node[idx] = i;
	dist[i] = cur_dist;
	depth[idx++] = cur_depth;
	for (int j = head[i]; ~j; j = nxt[j]){
		int k = to[j];
		if (k == parent) continue;
		int c = cost[j];
		cur_dist += c; ++cur_depth;
		dfs(k, i);
		cur_dist -= c; --cur_depth;
		node[idx] = i;
		depth[idx++] = cur_depth;
	}
}
int spt[MAX << 1][18];
inline void build(void){
	for (int i = 0; i < idx; ++i)
		*spt[i] = i;
	for (int j = 1, a, b; (1 << j) <= idx; ++j)
		for (int i = 0; i + (1 << j)<= idx; ++i)
		{
			a = spt[i][j-1];
			b = spt[i + (1 << (j - 1))][j-1];
			spt[i][j] = depth[a] < depth[b] ? a : b;
		}
}
inline int log_2(int i){
	int ans = -1;
	for(;i; i >>= 1)
		++ans;
	return ans;
}
inline int rmq(int i, int j){
	if (i > j) swap(i, j);
	int k = log_2(j - i + 1);
	int a = spt[i][k];
	int b = spt[j - (1 << k) + 1][k];
	return depth[a] < depth[b] ? a : b;
}
inline void addEdge(const int i, const int j, const int k){
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	cost[en] = k;
	++en;
}
inline void addBiEdge(const int i, const int j, const int k){
	addEdge(i, j, k);
	addEdge(j, i, k);
}
inline void init(void){
	cur_dist = 0LL;
	en = idx = cur_depth = 0;
	memset(head, 0xFF, sizeof head);
}
inline void read(void){
	for (int i = 1, x, y; i < n; ++i){
		scanf("%d%d", &x, &y);
		addBiEdge(i, x, y);
	}
}
inline void solve(void){
	int q; scanf("%d", &q);
	for (int x, y, i = 1; i <= q; ++i){
		scanf("%d%d", &x, &y);
		int lowest_common_ancestor = node[rmq(occur[x], occur[y])];
		printf("%lld%c", dist[x] + dist[y] - (dist[lowest_common_ancestor] << 1LL), " \n"[i == q]);
	}
}
int main(void){
	while(scanf("%d", &n), n)
	{
		init();
		read();
		dfs(0, -1);
		build();
		solve();
	}
	return 0;
}

