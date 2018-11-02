#include<stdio.h>
#include <string.h>
#include<vector>
#include<algorithm>
#define MAX 2005
using namespace std;
int p[MAX];
inline int parent(const int i){ return p[i] == i ? i : p[i] = parent(p[i]); }
inline void unite(const int i, const int j){ p[parent(j)] = parent(i); }


int n, m;
int head[MAX], to[MAX*MAX * 2], nxt[MAX*MAX * 2], en;
inline void addEdge(const int x, const int y){
	nxt[en] = head[x]; head[x] = en; to[en++] = y;
}
int dfs_low[MAX], dfs_num[MAX], dfs_count;
enum color :char{ white = 0, grey, black }vis[MAX];
vector<int>dfs_v;
void dfs(int i){
	dfs_low[i] = dfs_num[i] = dfs_count++;
	dfs_v.push_back(i);
	vis[i] = grey;
	for (int j = head[i]; j != -1; j = nxt[j]){
		int k = to[j];
		if (!vis[k]) dfs(k);
		if (vis[k] == grey) dfs_low[i] = min(dfs_low[i], dfs_low[k]);
	}
	if (dfs_low[i] == dfs_num[i]) {
		int j = -1;
		while (j != i){
			j = dfs_v.back();
			dfs_v.pop_back();
			unite(i, j);
			vis[j] = black;
		}
	}
}
void init(){
	dfs_count = en = 0;
	memset(head, 0xFF, sizeof head);
	memset(vis, 0, sizeof vis);
	// YOU FORGOT TO CLEAR YOUR VECTOR!!!
	dfs_v.clear();
	for (int i = 1; i <= n; ++i) p[i] = i;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	while (scanf("%d%d", &n, &m), n || m){
		init();
		int x, y, z;
		while (m--){
			scanf("%d%d%d", &x, &y, &z);
			addEdge(x, y);
			if (z == 2) addEdge(y, x);
		}
		for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
		bool flag = true;
		int geddo = parent(1);
		for (int i = 2; i <= n && flag; ++i) if (parent(i) != geddo) flag = false;
		printf("%d\n", flag);
	}
	return 0;
}