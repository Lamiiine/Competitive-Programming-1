// DOMINO PROBLEM!
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define MAX 100005
using namespace std;

int n, m;

int p[MAX];
inline int parent(const int i){ return p[i] == i ? i : p[i] = parent(p[i]); }
inline void unite(const int i, const int j){ p[parent(j)] = parent(i); }

vector<int>adj[MAX];

bool origin[MAX];
int dfs_num[MAX];
int dfs_low[MAX];
enum color :char{ white = 0, grey, black }vis[MAX];
int dfs_count;
vector<int> dfs_v;
inline void dfs(const int i){
	dfs_v.push_back(i);
	dfs_num[i] = dfs_low[i] = dfs_count++;
	vis[i] = grey;
	for (int j : adj[i]){
		if (!vis[j]) dfs(j);	// j is white
		if (vis[j] == grey) dfs_low[i] = min(dfs_low[i], dfs_low[j]);
	}
	if (dfs_low[i] == dfs_num[i]){
		// head of an SCC
		int j = -1;
		while (j != i){
			j = dfs_v.back();
			dfs_v.pop_back();
			vis[j] = black;
			unite(i, j);	// same component
		}
	}
}
inline void init(){
	dfs_count = 0;
	for (int i = 1; i <= n; ++i)p[i] = i, adj[i].clear();
	memset(vis, 0, (n + 1)*sizeof vis[0]);
	memset(origin, 1, (n + 1)*sizeof origin[0]);
	memset(dfs_num, 0xFF, (n + 1)*sizeof dfs_num[0]);
}
int main(){
	int TC;
	scanf("%d", &TC);
	while (TC--){
		scanf("%d%d", &n, &m);
		init();
		int x, y;
		while (m--) scanf("%d%d", &x, &y), adj[x].push_back(y);
		for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
		for (int i = 1; i <= n; ++i){
			int x = parent(i);
			for (auto j : adj[i]){
				int y = parent(j);
				if (x != y) origin[y] = false;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) ans += (parent(i) == i && origin[i]);
		printf("%d\n", ans);
	}
}