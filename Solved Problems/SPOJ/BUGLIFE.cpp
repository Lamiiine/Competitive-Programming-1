#include <stdio.h>
#include <string.h>
#include <stack>
#define MAX 2005
#define MAX2 2000005
using namespace std;
char color[MAX];
int n, m;
int en;
int head[MAX];
int nxt[MAX2];
int to[MAX2];
bool valid(int i){
	if (color[i] != char(-1)) return true;	// use char(-1) instead of 0xFF
	color[i] = 0;	// 0 or 1
	stack<int> s;
	s.push(i);
	bool vis[MAX];	// BFS needs a visisted array
	memset(vis, 0, sizeof vis);
	while(!s.empty()){
		int x = s.top();
		vis[x] = true;
		char color_cur = color[x];
		s.pop();
		int index = head[x];
		while(index != -1){
			int To = to[index];
			if (color[To] == color_cur) return false;
			color[To] = 1 - (color_cur);
			if (!vis[To]) s.push(To);
			index = nxt[index];
		}
	}
	return true;
	// don't forget to return true at the end!
}
void addEdge(int x, int y){
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
int main(){
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		memset(color, 0xFF, sizeof color);
		printf("Scenario #%d:\n", tc);
		en = 0;
		memset(head, 0xFF, sizeof head);
		scanf("%d%d", &n, &m);
		int x, y;
		while(m--){
			scanf("%d%d", &x, &y);
			addEdge(x, y);
			addEdge(y, x);
		}
		bool flag = true;
		for (int i = 1; i <= n; ++i)
		if (!valid(i)){
			printf("Suspicious bugs found!\n");
			flag = false;
			break;
		}
		if (flag)
		printf("No suspicious bugs found!\n");
	}
	return 0;
}
