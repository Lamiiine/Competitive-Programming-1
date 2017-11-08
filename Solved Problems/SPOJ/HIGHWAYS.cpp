// My first Dijkstra			:D
// yeah!!!!!!!!!!
#define MaxN 100005
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
int head[MaxN];
int to[2*MaxN];
int nxt[2*MaxN];
int cost[2*MaxN];

int dist[MaxN];		// distance
char vis[MaxN];		// visited flag
int n;			// order of the graph
int start, End;	// starting and edning city
char tc;

int DIJ(){
	priority_queue<ii> q;
	q.push(ii(dist[start] = 0, start));
	int dist_cur;
	int To, Cost;
	while (!q.empty()){
		ii x = q.top();
		q.pop();
		if ((-(x.first))> (dist_cur = dist[x.second])) continue;
		vis[x.second] = tc;	// mark current node as visited
		int index = head[x.second];
		while(index != -1)
		{
			if (dist[ To = to[index] ] > dist_cur + (Cost = cost[index]))
				dist[To] = dist_cur + Cost;
			if (vis[To] != tc) q.push(ii(-dist[To], To));
			index = nxt[index];
		}
	}
	return dist[End];
}

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	int m;	// number of high ways
	int roadStart, roadEnd, roadTime;
	long long distance;
	for (tc = 1; tc <= TC; ++tc){
		memset(head, 0xFF, sizeof head);
		memset(dist, 0x7F, sizeof dist);
		scanf("%d %d %d %d\n", &n, &m, &start, &End);	// size of graph, number of highways, starting and ending city
		for (int i = 0; i < (m << 1); i+= 2){	// store all highways
			scanf("%d %d %d", &roadStart, &roadEnd, &roadTime);
			to[i] = roadEnd;
			cost[i] = roadTime;
			nxt[i] = head[roadStart];
			head[roadStart] = i;
			int j = i + 1;
			to[j] = roadStart;
			cost[j] = roadTime;
			nxt[j] = head[roadEnd];
			head[roadEnd] = j;
		}
		if ((distance = DIJ()) == 0x7F7F7F7F) printf("NONE\n");
		else printf("%d\n", distance);
	}
	return 0;
}