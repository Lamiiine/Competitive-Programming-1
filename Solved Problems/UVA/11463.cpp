#include<stdio.h>
#include<queue>
#include<vector>
#define MAX 105
using namespace std;
typedef pair<int, int>ii;
int n, r;
vector<int>adj[MAX];
int distS[MAX];

int distD[MAX];

void dij(int s, int *dist){
	priority_queue<ii> q;
	dist[s] = 0;
	q.push(ii(dist[s], s));
	while (!q.empty()){
		int v = q.top().second;
		int cur_dist = -q.top().first;
		q.pop();
		if (dist[v] < cur_dist) continue;
		++cur_dist;
		for (int u : adj[v])
		if (dist[u] > cur_dist)
			q.push(ii(-(dist[u] = cur_dist), u));
	}
}
int main(){
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		memset(distS, 0x3F, sizeof distS);
		memset(distD, 0x3F, sizeof distD);
		scanf("%d%d", &n, &r);
		int x, y;
		while (r--) {
			scanf("%d%d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int s, d;
		scanf("%d%d", &s, &d);
		dij(s, distS);
		dij(d, distD);
		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans = max(ans, distS[i] + distD[i]);
		printf("Case %d: %d\n", ans);
		for (int i = 0; i < n; ++i) adj[i].clear();
	}
	return 0;
}