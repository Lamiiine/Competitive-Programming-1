#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>

#define MAX 10005
#define MAX2 100005
using namespace std;
typedef pair<int, int> ii;
int m, n, k, s, t;	// source, target

int head[MAX];
int to[MAX2];
int cost[MAX2];
int nxt[MAX2];
int dist[MAX];

int head2[MAX];
int to2[MAX2];
int nxt2[MAX2];
int dist2[MAX];

void dij(){
	priority_queue<ii> q;
	dist[s] = 0;
	q.push(ii(0, s));
	while (!q.empty()){
		int dist_cur = -q.top().first;
		int v = q.top().second;
		q.pop();
		if (dist[v] < dist_cur) continue;
		int index = head[v];
		while (index != -1){
			int To = to[index];
			int Cost = cost[index];
			index = nxt[index];
			if (dist[To] > dist_cur + Cost) { dist[To] = dist_cur + Cost; q.push(ii(-dist[To], To)); }
		}
	}
}
void dij2(){
	priority_queue<ii> q;
	dist[t] = 0;
	q.push(ii(0, t));
	while (!q.empty()){
		int dist_cur = -q.top().first;
		int v = q.top().second;
		q.pop();
		if (dist2[v] < dist_cur) continue;
		int index = head2[v];
		while (index != -1){
			int To = to2[index];
			int Cost = cost[index];
			index = nxt2[index];
			if (dist2[To] > dist_cur + Cost) { dist2[To] = dist_cur + Cost; q.push(ii(-dist2[To], To)); }
		}
	}
}
int main(){
	int TC;
	scanf("%d", &TC);
	int x, y, z;
	int roadF[305];
	int roadT[305];
	int roadC[305];
	while(TC--){
		int en = 0;
		scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);

		memset(head, 0xFF, sizeof head);
		memset(head2, 0xFF, sizeof head2);

		for (int i = 0; i < m; ++i){
			scanf("%d%d%d", &x,&y, &z);
			nxt[en] = head[x];
			head[x] = en;
			to[en] = y;

			nxt2[en] = head2[y];
			head2[y] = en;
			to2[en] = x;

			cost[en++] = z;
		}
		memset(dist, 0x3F, sizeof dist);
		memset(dist2, 0x3F, sizeof dist2);

		dij();
		dij2();
		for (int i = 0; i < k; ++i)
			scanf("%d%d%d", &roadF[i], &roadT[i], &roadC[i]);
		int init;
		memset(&init, 0x3F, sizeof init);
		int distance = dist[t];
		for (int i = 0; i < k; ++i)
			distance = min(distance, roadC[i] + min(dist[roadF[i]] + dist2[roadT[i]], dist[roadT[i]] + dist2[roadF[i]]));
		if (distance == init) printf("-1\n");
		else printf("%d\n", distance);
	}
	return 0;
}