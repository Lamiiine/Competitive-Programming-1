#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define MAX 35
using namespace std;
int n, m;
struct node{
	int n;	// couple number
	bool h;	// husband?
	bool t;	// taken?
};
inline bool operator == (const node & a, const node & b){
	return (a.n == b.n)&(a.h == b.h)&(a.t == b.t);
}
inline bool operator !=(const node & a, const node & b){
	return !(a == b);
}
int head[MAX][2][2];
node to[MAX << 4];
int nxt[MAX << 4];
int en;
inline void addEdge(const node & a, const node & b){
	nxt[en] = head[a.n][a.h][a.t];
	head[a.n][a.h][a.t] = en;
	to[en++] = b;
}
node p[MAX][2][2];
inline node parent(const node & i){ return p[i.n][i.h][i.t] == i ? i : p[i.n][i.h][i.t] = parent(p[i.n][i.h][i.t]); }
inline void unite(const node & i, const node & j){ node J = parent(j); p[J.n][J.h][J.t] = parent(i); }


int dfs_count, dfs_num[MAX][2][2], dfs_low[MAX][2][2];
vector<node>dfs_v;
enum color{white = 0, grey, black} vis[MAX][2][2];
inline void dfs(const node & a){
	dfs_num[a.n][a.h][a.t] = dfs_low[a.n][a.h][a.t] = dfs_count++;
	vis[a.n][a.h][a.t] = grey;
	dfs_v.push_back(a);
	for (int j = head[a.n][a.h][a.t]; j != -1; j = nxt[j]){
		node k = to[j];
		if (!vis[k.n][k.h][k.t]) dfs(k);
		if (vis[k.n][k.h][k.t] == grey) dfs_low[a.n][a.h][a.t] = min(dfs_low[a.n][a.h][a.t], dfs_low[k.n][k.h][k.t]);
	}
	if (dfs_low[a.n][a.h][a.t] == dfs_num[a.n][a.h][a.t]){
		node j = node{ 0, 0, 0 };
		while (j != a){
			j = dfs_v.back();
			dfs_v.pop_back();
			unite(a, j);
		}
	}
}
inline void init(){
	dfs_count = en = 0;
	memset(head, 0xFF, sizeof head);
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < MAX; ++i)
	for (int j = 0; j < 2; ++j)
	for (int k = 0; k < 2; ++k)
		p[i][j][k] = node{ i, j, k };
}
int main(){
	freopen("Input.txt", "r", stdin);
	while (scanf("%d%d", &n, &m), n || m){
		init();
		// store couples
		for (int i = 1; i <= n; ++i){
			addEdge(node{ i, 1, 1 }, node{ i, 0, 0 });
			addEdge(node{ i, 0, 1 }, node{i, 1, 0});
		}
		// store adulterous relationships
		char a[5], b[5];
		while (m--){
			scanf("%s%s", a, b);
			char l1, l2;
			bool h1 = (a[l1 = strlen(a) - 1] == 'h'), h2 = (a[l2 = strlen(b) - 1] == 'h');
			a[l1] = b[l2] = 0;
			int n1 = atoi(a), n2 = atoi(b);
			addEdge(node{ n1, h1, 1 }, node{ n2, h2, 0 });
			addEdge(node{ n2, h2, 1 }, node{n1, h1, 0});
		}
		for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 2; ++j)
		for (int k = 0; k < 2; ++k)
		if (!vis[i][j][k])dfs(node{ i, j, k });
		bool flag = true;
		for (int i = 1; i <= n && flag; ++i)
		for (int j = 0; j < 2; ++j)
		if (parent(node{i, j, 0}) == parent(node{i, j, 1})) flag = false;
		if (!flag) printf("bad luck\n");
		else{
			printf("hehehe\n");
		}
	}
	return 0;
}