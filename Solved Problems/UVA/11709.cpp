#define MAX 1005
#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
// names
struct name{ char f[13], l[13]; }n[MAX];	// names
struct namePointer{ name * p; };
bool operator < (const namePointer a, const namePointer b){
	int i = strcmp(a.p->f, b.p->f);
	if (i) return i < 0;
	return strcmp(a.p->l, b.p->l) < 0;
}
map<namePointer, int>m;
#define MAXX 999005
// graph
int head[MAX];	// people
int to[MAXX];
int nxt[MAXX];
int en;
void addEdge(const int i, const int j){
	nxt[en] = head[i];
	head[i] = en;
	to[en++] = j;
}
// disjoint sets
int g[MAX];
inline int group(const int i){ return g[i] == i ? i : g[i] = group(g[i]); }
inline void unite(const int i, const int j){ g[group(j)] = group(i); }
bool parent[MAX];	// is 'i' parent of a group
// dfs
int dfs_count;
enum color:char{ white = 0, grey, black };
color vis[MAX];
int dfs_num[MAX];
int dfs_low[MAX];
int s[MAX];
int top;
void dfs(int i){
	s[top++] = i;
	dfs_num[i] = dfs_low[i] = dfs_count++;
	vis[i] = grey;
	for (int j = head[i]; j != -1; j = nxt[j]){
		int k = to[j];
		if (vis[k] == white) dfs(k);
		if (vis[k] == grey) dfs_low[i] = min(dfs_low[i], dfs_low[k]);
	}
	if (dfs_num[i] == dfs_low[i]){
		int j = -1;
		while (j != i){
			j = s[--top];
			unite(i, j);
			vis[j] = black;
		}
	}
}
void init(){
	top = dfs_count = en = 0;
	m.clear();
	memset(head, 0xFF, sizeof head);
	memset(parent, 0, sizeof parent);
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < MAX; ++i) g[i] = i;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int p, t;
	while (scanf("%d%d", &p, &t), p || t){
		init();
		for (int i = 0; i < p; ++i) scanf("%s%s", n[i].f, n[i].l), m[namePointer{n + i}] = i;
		name a, b;
		while (t--)
			scanf("%s%s%s%s", a.f, a.l, b.f, b.l), addEdge(m[namePointer{ &a }], m[namePointer{ &b }]);
		for (int i = 0; i < p; ++i) if (!vis[i]) dfs(i);
		for (int i = 0; i < p; ++i) parent[group(i)] = true;
		int ans = 0;
		for (int i = 0; i < p; ++i) ans += parent[i];
		printf("%d\n", ans);
	}
	return 0;
}