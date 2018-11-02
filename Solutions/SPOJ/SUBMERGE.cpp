// STRAIGHT FORWARD ARTICULATION POINTS
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAX 10005
#define MAXX 100005
using namespace std;
int head[MAX];
int nxt[MAXX << 1];
int to[MAXX << 1];
int en;
int n, m;
inline void addEdge(const int x, const int y){
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
int root, children, counter;
int dfs_num[MAX];
int dfs_low[MAX];
int dfs_p[MAX];
bool art[MAX];
inline void init(){
	memset(head, 0xFF, sizeof head);
	en = 0;
	memset(art, 0, sizeof art);
	memset(dfs_low, 0x3F, sizeof dfs_low);
	memset(dfs_num, 0xFF, sizeof dfs_num);
}
inline void dfs(const int i){
	dfs_low[i] = dfs_num[i] = counter++;
	for (int j = head[i]; j != -1; j = nxt[j]){
		int x = to[j];
		if (dfs_num[x] == -1){
			dfs_p[x] = i;
			if (i == root) ++children;
			dfs(x);
			if (dfs_low[x] >= dfs_num[i]) art[i] = true;
			dfs_low[i] = min(dfs_low[i], dfs_low[x]);
		}
		else if (dfs_p[i] != x) dfs_low[i] = min(dfs_low[i], dfs_num[x]);
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	while (scanf("%d%d", &n, &m), n || m){
		init();
		int x, y;
		while (m--)scanf("%d%d", &x, &y), addEdge(x, y), addEdge(y, x);
		for (int i = 1; i <= n; ++i)
		if (dfs_num[i] == -1)
		{
			root = i;
			children = counter = 0;
			dfs_p[i] = -1;
			dfs(i);
			art[i] = children > 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) ans += art[i];
		printf("%d\n", ans);
	}
	return 0;
}