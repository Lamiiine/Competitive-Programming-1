#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
short head[202], to[20004], nxt[20004], cost[20004], en;
typedef pair<int, short> is;
is dist[202];
void init(void){
	memset(head, 0xFF, sizeof head);
	en = 0;
	memset(dist, 0x3F, sizeof dist);
	for (short i = 0; i < 202; ++i)
		dist[i].second = i;
}
void addEdge(short i, short j, short k){
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	cost[en++] = k;
}
int n, m;
void dij(){
	priority_queue<is>q;
	q.push(is(0, 0));
	dist[0].first = 0;
	while(!q.empty()){
		short v = q.top().second;
		int cur_dist = -q.top().first;
		q.pop();
		if (dist[v].first < cur_dist) continue;
		int temp;
		for (short j = head[v]; j != -1; j = nxt[j]){
			short k = to[j];
			if (dist[k].first > (temp = cur_dist + cost[j]))
				q.push(is(-(dist[k].first = temp), k));
		}
	}
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d", &n), n){
		scanf("%d", &m);
		init();
		for (int i = 0, x, y, z; i < m; ++i)
			scanf("%d%d%d", &x, &y, &z), addEdge(x, y, z), addEdge(y, x, z);
		dij();
		sort(dist, dist + n);
		int k;
		scanf("%d", &k);
		printf("%d\n", dist[k].second);
	}
	return 0;
}

