#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define MAX 105
using namespace std;
typedef pair<int, int> ii;
int n;
// NUMBER OF EDGES IN A COMPLETE DIRECTED GRAPH IS n(n-1)
int eng[MAX];	// energy of vertex i
int dist[MAX];	// maximum enery value you can reach vertex i with
bool vis[MAX];	// for DFS
bool neg[MAX];	// does it lie on a negative cycle?

int head[MAX];
int to[MAX*MAX];
int nxt[MAX*MAX];
int en;
inline void addEdge(int x, int y){
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
// THIS IS HOW TO TRAVERSE A GRAPH WHERE NODES HAVE WEIGHTS, NOT EDGES
// NEGATIVE CYCLES ALGORITHM
inline bool dij(){
	// relax using all edges n-1 times
	for (int blah = 1; blah <= (n << 1); ++blah)
	for (int i = 1; i <= n; ++i){
		int cur_dist = dist[i];
		for (int j = head[i]; j != -1; j = nxt[j]){
			int To = to[j];
			int Eng = eng[To] + cur_dist;
			if (Eng > 0) dist[To] = max(dist[To], Eng);
		}
	}
	bool flag = false;
	for (int i = 1; i <= n; ++i){
		int cur_dist = dist[i];
		for (int j = head[i]; j != -1; j = nxt[j]){
			int To = to[j];
			int Eng = eng[To] + cur_dist;
			if (Eng > 0 && dist[To] < Eng){
				dist[To] = Eng;
				neg[To] = flag = true;
			}
		}
	}
	return flag;
}
// EDGES RELATEX DURING THE LAST RELAXATION CAN BE REACHED FROM A VERTEX ON A NEGATIVE CYCLE
bool dfs(){
	queue<int>q;
	for (int i = 1; i <= n; ++i)if (neg[i]) q.push(i), vis[i] = true;
	while (!q.empty()){
		int v = q.front();
		q.pop();
		// YOU WROTE '++j' INSTEAD OF 'j = nxt[j]'
		for (int j = head[v]; j != -1; j = nxt[j])
		{
			int To = to[j];
			if (!vis[To]) vis[To] = true, q.push(To);
		}
	}
	return vis[n];
}
inline void init(){
	 en = 0;
	 memset(dist, 0x80, sizeof dist);
	 memset(head, 0xFF, sizeof head);
	 memset(vis, 0, sizeof vis);
	 memset(neg, 0, sizeof neg);
	 dist[1] = 100;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	// freopen("Output.txt", "w", stdout);
	while (scanf("%d", &n), n != -1){
		init();
		int x, y;
		for (int i = 1; i <= n; ++i){
			scanf("%d%d", &x, &y);
			eng[i] = x;
			while (y--){
				scanf("%d", &x);
				addEdge(i, x);
			}
		}
		bool cyc = dij();
		if (dist[n] >= 0) { printf("winnable\n"); continue; }
		if (!cyc || !dfs()){ printf("hopeless\n"); continue; }
		printf("winnable\n");
	}
	return 0;
}