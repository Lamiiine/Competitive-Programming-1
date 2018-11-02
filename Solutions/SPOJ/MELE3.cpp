#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>

#define MAX 1005
#define MAX2 50005
using namespace std;
typedef pair<int, int> ii;
int k, n;

int head[MAX];
int to[MAX2 << 1];		// don't forget to multiply by 2
int nxt[MAX2 << 1];
int dist[MAX];

int dij(){
	priority_queue<ii> q;
	dist[1] = 0;
	q.push(ii(0, 1));
	while (!q.empty()){
		int dist_cur = -q.top().first;	// current distance
		int v = q.top().second;	// current floor
		q.pop();
		if (dist[v] < dist_cur) continue;
		int index = head[v];
		while (index != -1){
			int To = to[index];
			index = nxt[index];
			int temp;
			if (v > To){
				if (dist[To] > (temp = dist_cur + v - To + (((((-dist_cur) % ((v - To) << 1))) + ((v - To)*3)) % ((v - To) << 1))))
					q.push(ii(-(dist[To] = temp), To));
			}
			else {	// To > v
				if (dist[To] > (temp = dist_cur + To - v + (((((-dist_cur) % ((To - v) << 1))) + ((To - v) << 1)) % ((To - v) << 1))))
					q.push(ii(-(dist[To] = temp), To));
			}
		}
	}
	return dist[k];
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	scanf("%d%d", &k, &n);
	memset(head, 0xFF, sizeof head);
	memset(dist, 0x3F, sizeof dist);
	int x, y;
	int en = -1;
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &x, &y);
		nxt[++en] = head[x];
		head[x] = en;
		to[en] = y;

		nxt[++en] = head[y];
		head[y] = en;
		to[en] = x;
	}
	printf("%d\n", 5*dij());
	return 0;
}