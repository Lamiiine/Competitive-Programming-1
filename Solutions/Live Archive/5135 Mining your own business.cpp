#include<bits/stdc++.h>
#define MAX 65536
using namespace std;
typedef long long int ll;
int head[MAX], nxt[MAX << 1], to[MAX << 1], en;
int n;
inline void addEdge(const int i, const int j){
	nxt[en] = head[i]; head[i] = en; to[en] = j; ++en;
}
inline void addBiEdge(const int i, const int j){
	addEdge(i, j); addEdge(j, i);
}
bool used[MAX];
int dfs_num[MAX], dfs_low[MAX], dfs_count;
bool art[MAX]; // bool bridge[MAX << 1];
int root, children;
void dfs(const int i, const int p){
	dfs_num[i] = dfs_low[i] = dfs_count++;
	for (int j = head[i]; j != -1; j = nxt[j]){
		int k = to[j];
		if (dfs_num[k] == -1){
			dfs(k, i);
			children += (i == root);
			// if (dfs_low[k] > dfs_num[i]) bridge[j] = bridge[j^1] = 1;
			if (dfs_low[k] >= dfs_num[i])
				art[i] = true;
			dfs_low[i] = min(dfs_low[i], dfs_low[k]);
		}
		else
			if (k != p) dfs_low[i] = min(dfs_low[i], dfs_num[k]);
	}
}
inline void Tarjan(){
	for (int i = 1; i <= n; ++i)
		if (dfs_num[i] == -1 && used[i]) {
			children = 0;
			root = i;
			dfs(i, -1);
			art[i] = children > 1;
		}
}
set<int> adj_art;
bool vis[MAX];
inline int dfs(const int i){
	vis[i] = true;
	int ans = 1;
	for (int j = head[i]; j != -1; j = nxt[j])
	{
		int k = to[j];
		if (art[k]) adj_art.insert(k);
		else if (!vis[k])
			ans += dfs(k);
	}
	return ans;
}
ll num_ways;
int num_leaves;
inline void solve(){
	num_ways = 1LL;
	num_leaves = 0;
	for (int i = 1; i <= n; ++i)
		if (!vis[i] && !art[i])
		{
			adj_art.clear();
			int comp_size = dfs(i);
			if (adj_art.size() == 1)
				++num_leaves, num_ways *= (ll)comp_size;
		}
	if (num_leaves == 0)
	{
		int count_used = 0;
		for (int i = 1; i <= n; ++i)
			count_used += used[i];
		num_leaves = 2, num_ways = (ll)count_used*(count_used-1)/2LL;
	}
}
inline void read(int q){
	for (int x, y; q--;){
		scanf("%d%d", &x, &y);
		used[x] = used[y] = true;
		n = max(n, max(x, y));
		addBiEdge(x, y);
	}
}
inline void init(void){
	memset(dfs_num, 0xFF, sizeof dfs_num); dfs_count = 0;
	memset(head, 0xFF, sizeof head); en = 0;
	memset(art, 0, sizeof art);
	memset(vis, 0, sizeof vis);
	memset(used, 0, sizeof used);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	for (int q, tc = 1; scanf("%d", &q), q; ++tc){
		init();
		read(q);
		Tarjan();
		solve();
		printf("Case %d: %d %lld\n", tc, num_leaves, num_ways);
	}
	return 0;
}

