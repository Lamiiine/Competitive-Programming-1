#include<bits/stdc++.h>
#define MAX 200010
using namespace std;
int head[MAX], to[MAX << 2], nxt[MAX << 2], en;
inline void addEdge(int i, int j){
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	++en;
}
int n;
int dist[MAX];
int INF;
inline void init(void){
	memset(head, 0xFF, sizeof head);
	en = 0;
	memset(dist, 0x3F, sizeof dist);
	memset(&INF, 0x3F, sizeof INF);
}
inline void read(void){
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
		addEdge(i, i + 1), addEdge(i + 1, i);
	for (int x, i = 1; i <= n; ++i)
		scanf("%d", &x), addEdge(i, x);
}
typedef pair<int, int> ii;
inline void dij(void){
	queue<int>q;
	q.push(1);dist[1] = 0;
	while(!q.empty()){
		int i = q.front(); q.pop();
		int cur_dist = dist[i] + 1;
		for (int j = head[i]; ~j; j = nxt[j]){
			int k = to[j];
			if (dist[k] == INF)
				q.push(k), dist[k] = cur_dist;
		}
	}
}
int main(void){
	init();
	read();
	dij();
	for (int i = 1; i <= n; ++i)
		printf("%d ", dist[i]);
}

