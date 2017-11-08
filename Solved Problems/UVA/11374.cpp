#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#define MAX 505		// num nodes
#define MAX2 1005	// num routes
using namespace std;
typedef pair<int, int> ii;
int n;
int en;
int head[MAX];
int to[MAX2 << 1];
int cost[MAX2 << 1];
int nxt[MAX2 << 1];
inline void dij(int s, int* via, int* dist){
	priority_queue<ii> q;
	dist[s] = 0;
	q.push(ii(0, s));
	via[s] = -1;
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
			if (dist[To] > dist_cur + Cost) {
				dist[To] = dist_cur + Cost;
				via[To] = v;
				q.push(ii(-dist[To], To));
			}
		}
	}
}
inline void addEdge(int x, int y, int z){
	nxt[en] = head[x];
	head[x] = en;
	to[en] = y;
	cost[en++] = z;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int s, e;
	int dist[MAX];
	int via[MAX];
	int via2[MAX];
	int dist2[MAX];
	int arr[MAX];
	bool first = 1;
	while (scanf("%d%d%d", &n, &s, &e) != EOF){
		if (!first) printf("\n");	// Don't print line after last case
		first = 0;
		int inf;
		memset(&inf, 0x3F, sizeof inf);
		en = 0;
		memset(head, 0xFF, sizeof head);
		memset(dist, 0x3F, sizeof dist);
		memset(dist2, 0x3F, sizeof dist2);		// you forgot to initialize dist2
		int x, y, z;
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i){
			scanf("%d%d%d", &x, &y, &z);
			addEdge(x, y, z);
			addEdge(y, x, z);
		}
		dij(s, via, dist);
		dij(e, via2, dist2);
		int distance = dist[e];
		int k;
		scanf("%d", &k);
		int a, b, c;
		int temp;
		int f = -1, t = -1;	// ticket used from... to...
		for (int i = 0; i < k; ++i){
			scanf("%d%d%d", &a, &b, &c);
			for (int j = 0; j < 2; ++j){
				if (distance >(temp = c + dist[a] + dist2[b])){
					distance = temp;
					f = a;
					t = b;
				}
				swap(a, b);
			}
		}
		int arrCount = 0;
		if (f == -1){
			x = e;
			while (x != -1){
				arr[arrCount++] = x;
				x = via[x];
			}
			for (int i = arrCount-1; i > 0; --i) printf("%d ", arr[i]);
			printf("%d\n", arr[0]);
			printf("Ticket Not Used\n");
		}
		else {
			int x = f;
			while (x != -1){
				arr[arrCount++] = x;
				x = via[x];
			}
			for (int i = arrCount-1; i >= 0; --i) printf("%d ", arr[i]);
			x = t;
			while (x != e){
				printf("%d ", x);
				x = via2[x];
			}
			printf("%d\n%d\n", e, f);
		}
		printf("%d\n", distance);
	}
	return 0;
}