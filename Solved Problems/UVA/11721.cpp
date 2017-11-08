#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define MAX 1005
// TO FIND VERTICES THAT YOU CAN REACH A NEGATIVE CYCLE FROM, USE A REVERSE GRAPH
using namespace std;
int n, m;
int head[MAX];
int to[MAX << 1];
int cost[MAX << 1];
int nxt[MAX << 1];
int en;
inline void addEdge(const int x, const int y, const int z){
	nxt[en] = head[x];
	head[x] = en;
	to[en] = y;
	cost[en++] = z;
}
//int p[MAX];
//inline int parent(const int i){
//	return p[i] == i ? i : p[i] = parent(p[i]);
//}
//inline void unite(const int i, const int j){
//	p[parent(i)] = parent(j);
//}
int dist[MAX];
bool neg[MAX];	// vertices lying on a negative cycle
inline void dij(){
	bool flag = false;
	// relax n-1 times
	for (int blah = 0; blah < n; ++blah)
	for (int i = 0; i < n; ++i){
		int cur_dist = dist[i];
		for (int j = head[i]; j != -1; j = nxt[j]){
			int To = to[j];
			int Cost = cost[j];
			dist[To] = min(dist[To], Cost + cur_dist);
		}
	}
	// DURING LAST RELAXATION PHASE, ALL TOUCHED EDGES LIE ON A NEGATIVE CYCLE
	for (int i = 0; i < n; ++i)
	{
		int cur_dist = dist[i];
		for (int j = head[i]; j != -1; j = nxt[j]){
			int To = to[j];
			int Cost = cost[j] + cur_dist;
			// YOU WROTE '<' INSTEAD OF '>'
			if (dist[To] > Cost){
				dist[To] = Cost;
				neg[i] = neg[To] = true;
			}
		}
	}
}
bool vis[MAX];
inline bool dfs(){
	bool flag = false;
	queue<int>q;
	for (int i = 0; i < n; ++i)
	if (neg[i]) flag = vis[i] = true, q.push(i);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int j = head[v]; j != -1; j = nxt[j]){
			int u = to[j];
			if (!vis[u]) vis[u] = neg[u] = true, q.push(u);
		}
	}
	return flag;
}
inline void init(){
	en = 0;
	memset(head, 0xFF, sizeof head);
	memset(dist, 0x0F, sizeof dist);
	memset(neg, 0, sizeof neg);
	memset(vis, 0, sizeof vis);
	// for (int i = 0; i < n; ++i) p[i] = i;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		init();
		scanf("%d%d", &n, &m);
		int x, y, z;
		// store reverse graph
		while (m--) { scanf("%d%d%d", &x, &y, &z); addEdge(y, x, z); }
		dij();
		printf("Case %d:", tc);
		if (!dfs()) printf(" impossible");
		else for (int i = 0; i < n; ++i) if (neg[i]) printf(" %d", i);
		printf("\n");
	}
}