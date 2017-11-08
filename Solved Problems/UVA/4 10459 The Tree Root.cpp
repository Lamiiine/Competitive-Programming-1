#include<stdio.h>
#include<set>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<vector>
#include<queue>
#define MAX 5005
using namespace std;
int head[MAX], to[MAX << 1], nxt[MAX << 1], en;
enum color
	:char {white = 0, gray, black
} vis[MAX];
int dist[MAX];
void init(void) {
	memset(head, 0xFF, sizeof head);
	en = 0;
}
void addEdge(int x, int y) {
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
int n;
void bfs(int s) {
	memset(vis, 0, sizeof vis);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	vis[s] = gray;
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		int cur_dist = dist[i] + 1;
		for (int j = head[i]; j != -1; j = nxt[j]) {
			int k = to[j];
			if (!vis[k])
				vis[k] = gray, dist[k] = cur_dist, q.push(k);
		}
		vis[i] = black;
	}
}
int max_dist(){
	int ans = INT_MIN;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, dist[i]);
	return ans;
}
int main(void) {
	while (scanf("%d", &n) != EOF) {
		init();
		for (int i = 1, k, j; i <= n; ++i) {
			scanf("%d", &k);
			while (k--)
				scanf("%d", &j), addEdge(i, j);
		}
		bfs(1);
		int ans = max_dist();
		int source;
		set<int>c;	// center
		set<int>p;	// periphery
		for (int i = 1; i <= n; ++i)
			if (dist[i] == ans)
				p.insert(source = i);
		bfs(source);
		ans = max_dist();
		for (int i = 1; i <= n; ++i) {
			int temp = dist[i];
			if (temp == ans)
				p.insert(i);
			if (temp == (ans >> 1) || temp == ((ans >> 1) + (ans & 1)))
				c.insert(i);
		}
		for (set<int>::iterator iter = c.begin(); iter != c.end(); ++iter){
			int j = *iter;
			bfs(j);
			if (max_dist() > ((ans >> 1) + (ans & 1)))
				c.erase(j);
		}
		printf("Best Roots  :");
		for (set<int>::iterator iter = c.begin(); iter != c.end(); ++iter)
			printf(" %d", *iter);
		printf("\nWorst Roots :");
		for (set<int>::iterator iter = p.begin(); iter != p.end(); ++iter)
			printf(" %d", *iter);
		printf("\n");
	}
	return 0;
}

