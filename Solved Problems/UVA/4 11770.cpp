#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define MAX 10005
#define MAXX 100005
using namespace std;
int head[MAX], nxt[MAXX], to[MAXX], en;
inline void addEdge(const int i, const int j){
	nxt[en] = head[i]; head[i] = en; to[en++] = j;
}
enum color:char{white = 0, grey, black}vis[MAX];
int n, m;

int p[MAX];
inline int parent(const int i){ return p[i] == i ? i : p[i] = parent(p[i]); }
inline void unite(const int i, const int j){ p[parent(j)] = parent(i); }

bool need[MAX];
vector<int>v;
int dfs_low[MAX], dfs_num[MAX], dfs_count;
inline void dfs(int i){
	dfs_low[i] = dfs_num[i] = dfs_count++;
	vis[i] = grey;
	v.push_back(i);
	for (int j = head[i]; j != -1; j = nxt[j]){
		int k = to[j];
		if (!vis[k]) dfs(k);
		if (vis[k] == grey) dfs_low[i] = min(dfs_low[i], dfs_low[k]);
	}
	if (dfs_low[i] == dfs_num[i]){
		int j = -1;
		while (j != i){
			j = v.back();
			v.pop_back();
			unite(i, j);
			vis[j] = black;
		}
	}
}
void init(){
	dfs_count = en = 0;
	memset(head, 0xFF, sizeof head);
	memset(vis, 0, sizeof vis);
	// initalize all to not needed
	memset(need, 0, sizeof need);
	for (int i = 1; i <= n; ++i) p[i] = i;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		scanf("%d%d", &n, &m);
		// call init() after reading 'n' and 'm'!
		init();
		int x, y;
		while (m--) scanf("%d%d", &x, &y), addEdge(x, y);
		for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
		for (int i = 1; i <= n; ++i) need[parent(i)] = true;
		for (int i = 1; i <= n; ++i)
		for (int j = head[i]; j != -1; j = nxt[j]){
			int k = to[j];
			int I = parent(i), K = parent(k);
			// YOU WROTE SMALL 'k' INSTEAD OF CAPITAL 'K'
			if (I != K) need[K] = false;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) ans += need[i];
		printf("Case %d: %d\n", tc, ans);
	}
	return 0;
}