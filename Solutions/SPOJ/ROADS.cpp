#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <queue>
#define MAX 105
#define MAXX 10005
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
int dist[MAX][MAXX];	// distance to node i in time x
int k, n, r;
int head[MAX];
int nxt[MAXX];
int to[MAXX];
int cost[MAXX];
int time[MAXX];
int en;
void dij(){
	dist[1][0] = 0;
	priority_queue<iii> q;
	q.push(iii(ii(0, 0), 1));
	while(!q.empty()){
		int v = q.top().second;
		int cur_cost = -q.top().first.first;
		int cur_time = -q.top().first.second;
		q.pop();
		if(dist[v][cur_time] < cur_cost) continue;
		int index = head[v];
		while(index != -1){
			int To = to[index];
			int Cost = cur_cost + cost[index];
			int Time = cur_time + time[index];
			index = nxt[index];
			if (Time <= k && dist[To][Time] > Cost){
				dist[To][Time] = Cost;
				q.push(iii(ii(-Cost, -Time), To));
			}
		}
	}
}
int main() {
	int TC;
	scanf("%d", &TC);	// don't forget to scanf TC
	while(TC--){
		en = 0;
		scanf("%d%d%d", &k, &n, &r);
		memset(head, 0xFF, sizeof head);
		memset(dist, 0x7F, sizeof dist);
		int x, y, z, w;
		for (int i = 0; i < r; ++i){	// YOU TYPED 4 INSTEAD OF r!!!!!
			scanf("%d%d%d%d", &x, &y, &z, &w);
			nxt[en] = head[x];
			head[x] = en;
			to[en] = y;
			cost[en] = z;
			time[en] = w;
			++en;
		}
		dij();
		int ans;
		memset(&ans, 0x7F, sizeof ans);
		int total = -1;
		// --n; // IT'S 1-BASED INDEXING!!!!!
		for (int i = 0; i <= k; ++i)
			if (dist[n][i] < ans) ans = dist[n][i], total = i;
		if (total == -1) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}