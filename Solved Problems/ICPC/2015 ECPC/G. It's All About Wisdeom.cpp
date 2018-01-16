#include <stdio.h>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <string.h>
#define MAX 100005

using namespace std;
typedef pair<int, int> ii;

int n, m, k;
int mid;

int dist[MAX];
int head[MAX];
int nxt[MAX * 2];
int to[MAX * 2];
int cost[MAX * 2];
int wis[MAX * 2];

bool dij(){
	priority_queue<ii> q;
	q.push(ii(dist[1] = 0, 1));
	while (!q.empty()){
		ii x = q.top();
		q.pop();
		x.first = -x.first;
		if (x.first > dist[x.second]) continue;
		int index = head[x.second];
		while (index != -1){
			if (wis[index] > mid) { index = nxt[index]; continue; }
			int To = to[index];
			int Cost = cost[index];
			if (dist[To] > x.first + Cost){
				dist[To] = x.first + Cost;
				q.push(ii(-dist[To], To));
			}
			index = nxt[index];
		}
	}
	return dist[n] < k;
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	int x, y, z, w;
	int lo, hi;
	bool flag;
	while (TC--){
		lo = INT_MAX;
		hi = INT_MIN;
		flag = false;
		memset(head, 0xFF, sizeof head);
		scanf("%d%d%d", &n, &m, &k);
		int en = 0;
		for (int i = 0; i < m; ++i){
			scanf("%d%d%d%d", &x, &y, &z, &w);
			nxt[en] = head[x];
			head[x] = en;
			to[en] = y;
			cost[en] = z;
			wis[en++] = w;

			nxt[en] = head[y];
			head[y] = en;
			to[en] = x;
			cost[en] = z;
			wis[en++] = w;
			lo = min(lo, w);
			hi = max(hi, w);
		}
		int Hi = hi;
		while (lo != hi){
			mid = (hi + lo) >> 1;
			memset(dist, 0x7F, sizeof dist);
			if (dij())
				hi = mid, flag = true;
			else lo = max(lo + 1, mid);	// This is necessary
		}
		// This also is necessary
		if (lo == Hi) {
			memset(dist, 0x7F, sizeof dist);
			mid = lo; flag = dij();
		}
		if (!flag) printf("-1\n");
		else printf("%d\n", lo);
	}
	return 0;
}
