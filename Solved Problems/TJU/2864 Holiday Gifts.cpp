#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define MAX 1005
using namespace std;
typedef short int us;
typedef pair<short int, char> sc;
us head[MAX], to[MAX], nxt[MAX], en;
us counter[2];
void addEdge(us x, us y){
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
bool vis[MAX];
void init(void){
	memset(head, 0xFF, sizeof head);
	en = 0;
	memset(vis, 0, sizeof vis);
	memset(counter, 0, sizeof counter);
}
int u, v, n;
void bfs(){
	queue<sc>q;
	q.push(sc(0, 0));
	while(!q.empty()){
		us i = q.front().first, cell = q.front().second; q.pop();
		++counter[cell];
		for (int j = head[i]; j != -1; j = nxt[j]){
			us k = to[j];
			q.push(sc(k, cell ^ 1));
		}
	}
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		printf("Scenario #%d:\n", tc);
		init();
		scanf("%d%d%d", &u, &v, &n);
		for (int i = 1, x; i < n; ++i)
			scanf("%d", &x), addEdge(x, i);
		bfs();
		int mn1 = min(u, v), mx1 = max(u, v);
		int mn2 = min(counter[0], counter[1]), mx2 = max(counter[0], counter[1]);
		// printf("%d %d %d %d\n", mn1, mx1, mn2, mx2);
		printf("%d\n\n", mn1*mx2 + mn2*mx1);
	}
	return 0;
}

