#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

#define MAX 20000
#define MAXM 50000

using namespace std;

typedef pair<int, int> ii;
int tc;
int n, m, s, t;

int dist[MAX];
int head[MAX];
int nxt[MAXM * 2];
int to[MAXM * 2];
int cost[MAXM * 2];

int dij(){
	priority_queue<ii> q;
	q.push(ii(dist[s] = 0, s));
	while (!q.empty()){
		ii x = q.top();
		q.pop();
		x.first = -x.first;
		if (x.first > dist[x.second]) continue;
		int index = head[x.second];
		while (index != -1){
			int To = to[index];
			int Cost = cost[index];
			if (dist[To] > x.first + Cost){
				dist[To] = x.first + Cost;
				q.push(ii(-dist[To], To));
			}
			index = nxt[index];
		}
	}
	return dist[t];
}

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	int x, y, z;
	for (tc = 1; tc <= TC; ++tc){
		memset(head, 0xFF, sizeof head);
		memset(dist, 0x7F, sizeof dist);
		int en = 0;
		scanf("%d%d%d%d", &n, &m, &s, &t);
		while(m--){
			scanf("%d%d%d", &x, &y, &z);
			nxt[en] = head[x];
			head[x] = en;
			to[en] = y;
			cost[en++] = z;
			nxt[en] = head[y];
			head[y] = en;
			to[en] = x;
			cost[en++] = z;
		}
		int distance;
		if ((distance = dij()) == 0x7F7F7F7F) printf("Case #%d: unreachable\n", tc);
		else printf("Case #%d: %d\n", tc, distance);
	}
	return 0;
}