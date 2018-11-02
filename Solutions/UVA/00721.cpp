#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

#define MAX 1000005

using namespace std;

typedef pair<int, int> ii;
int n, m;

int dist[MAX];
int head[MAX];
int nxt[MAX];
int to[MAX];
int cost[MAX];

int dist2[MAX];
int head2[MAX];
int nxt2[MAX];
int to2[MAX];

void dij(){
	priority_queue<ii> q;
	q.push(ii(dist[1] = 0, 1));
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
}
void dij2(){
	priority_queue<ii> q;
	q.push(ii(dist2[1] = 0, 1));
	while (!q.empty()){
		ii x = q.top();
		q.pop();
		x.first = -x.first;
		if (x.first > dist2[x.second]) continue;
		int index = head2[x.second];
		while (index != -1){
			int To = to2[index];
			int Cost = cost[index];
			if (dist2[To] > x.first + Cost){
				dist2[To] = x.first + Cost;
				q.push(ii(-dist2[To], To));
			}
			index = nxt2[index];
		}
	}
}

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	int x, y, z;
	while(TC--){
		memset(head, 0xFF, sizeof head);
		memset(head2, 0xFF, sizeof head2);
		memset(dist, 0x7F, sizeof dist);
		memset(dist2, 0x7F, sizeof dist2);
		int en = 0;
		scanf("%d%d", &n, &m);
		while (m--){
			scanf("%d%d%d", &x, &y, &z);
			nxt[en] = head[x];
			head[x] = en;
			to[en] = y;
			
			nxt2[en] = head2[y];
			head2[y] = en;
			to2[en] = x;

			cost[en++] = z;
		}
		dij();
		int distance = 0;
		for (int i = 2; i <= n; ++i) distance += dist[i];
		dij2();
		for (int i = 2; i <= n; ++i) distance += dist2[i];
		printf("%d\n", distance);
	}
	return 0;
}