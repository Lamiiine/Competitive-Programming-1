// The moral of this problem is: Sometimes, you need to reverse edges in one-directional graphs before storing them
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define MAX 105
using namespace std;
typedef pair<int, int> ii;
int dist[MAX];
int n, e, t, m;
vector<ii> adj[MAX];
void dij(){
	dist[e] = 0;
	priority_queue<ii> q;
	q.push(ii(0, e));
	while(!q.empty()){
		int dist_cur = -q.top().first;
		int x = q.top().second;
		q.pop();	// don't forget to pop!
		if (dist[x] < dist_cur) continue;
		for (auto iter = adj[x].begin(); iter != adj[x].end(); ++iter)
		{
			int v = iter->first;
			int cost = iter->second;
			if (dist[v] > dist_cur + cost){
				dist[v] = dist_cur + cost;
				q.push(ii(-dist[v], v));
			}
		}
	}
}
int main(){
	memset(dist, 0x3F, sizeof dist);
	scanf("%d%d%d%d", &n, &e, &t, &m);
	int x, y, z;
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		adj[y].push_back(ii(x, z));	// reverse it!
	}
	dij();
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (dist[i] <= t) ++ans;
	printf("%d", ans);
	return 0;
}
