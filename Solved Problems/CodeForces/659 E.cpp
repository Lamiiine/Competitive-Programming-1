// COMPLEX STATEMENT; VERY EASY IMPLEMENTATION;
#include<stdio.h>
#include<string>
#include<string.h>
#define MAX 100005
using namespace std;
typedef pair<int, int>ii;
int p[MAX];
inline void init(int n){
	for (int i = 1; i <= n; ++i) p[i] = i;
}
inline int parent(int i){
	return (p[i] == i) ? i : p[i] = parent(p[i]);
}
inline void unite(int i, int j){
	p[parent(i)] = parent(j);
}
int V[MAX];	// number of vertices in component i
int E[MAX]; // number of edges in component i
int main(){
	// freopen("Input.txt", "r", stdin);
	ii e[MAX];
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	int x, y;
	memset(V, 0, sizeof V);
	memset(E, 0, sizeof E);
	for (int i = 0; i < m; ++i){
		scanf("%d%d", &x, &y);
		e[i] = ii(x, y);
		unite(x, y);
	}
	for (int i = 1; i <= n; ++i) ++V[parent(i)];
	for (int i = 0; i < m; ++i) ++E[parent(e[i].first)];
	int ans = 0;
	for (int i = 1; i <= n; ++i) { ans += (E[i] == V[i] - 1); }
	printf("%d", ans);
	return 0;
}