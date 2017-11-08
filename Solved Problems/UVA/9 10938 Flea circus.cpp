#include<bits/stdc++.h>
#define MAX 5010
using namespace std;
typedef long long int ll;
int n;
int head[MAX], nxt[MAX << 1], to[MAX << 1], en;
int p[MAX];
/* Storing:
 * - First occurence of node i
 * - idx of node visited at time i
 * - depth of node visited at time i
 * */
int occur[MAX], node[MAX << 1], depth[MAX << 1];
int cur_depth;
int idx;
inline void dfs(int i){
	occur[i] = idx;
	node[idx] = i;
	int my_parent = p[i];
	depth[idx++] = cur_depth;
	for (int j = head[i]; ~j; j = nxt[j]){
		int k = to[j];
		if (k == my_parent) continue;
		++cur_depth;
		p[k] = i; dfs(k);
		--cur_depth;
		node[idx] = i;
		depth[idx++] = cur_depth;
	}
}
int spt[MAX << 1][14];
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
inline void addEdge(const int i, const int j){
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	++en;
}
inline void addBiEdge(const int i, const int j){
	addEdge(i, j);
	addEdge(j, i);
}
inline void init(void){
	en = idx = cur_depth = 0;
	memset(head, 0xFF, sizeof head);
}
inline void read(void){
	for (int i = 1, x, y; i < n; ++i){
		scanf("%d%d", &x, &y);
		addBiEdge(x, y);
	}
}
inline int climb(int i, int k){
	while(k--) i = p[i];
	return i;
}
inline void solve(void){
	int q; scanf("%d", &q);
	for (int x, y, i = 0; i < q; ++i){
		scanf("%d%d", &x, &y);
		int lowest_common_ancestor = node[rmq(occur[x], occur[y])];
		int dep_x = depth[occur[x]], dep_y = depth[occur[y]], dep_l = depth[occur[lowest_common_ancestor]];
		int ans = dep_x + dep_y - (dep_l << 1);
		if (ans & 1){
			int middle = ans >> 1, a, b;
			if (dep_x - dep_l >= middle + 1)
				a = climb(x, middle);
			else a = climb(y, middle);
			b = p[a];
			if (a > b) swap(a, b);
			printf("The fleas jump forever between %d and %d.\n", a, b);
		}
		else {
			int middle = ans >> 1;
			printf("The fleas meet at %d.\n", dep_x - dep_l >= middle ? climb(x, middle) : climb(y, middle));
		}
	}
}
int main(void){
	while(scanf("%d", &n), n)
	{
		init();
		read();
		p[1] = -1; dfs(1);
		build();
		solve();
	}
	return 0;
}

