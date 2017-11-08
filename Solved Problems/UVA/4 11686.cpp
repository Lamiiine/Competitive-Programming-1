#include<stdio.h>
#include<stack>
#include<algorithm>
#include<string.h>
#define MAX (int)1e6+6
using namespace std;
int head[MAX];
int to[MAX];
int nxt[MAX];
int en;
int ans[MAX];
int counter;
int inDeg[MAX];
inline void addEdge(const int x, const int y){
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
int n, m;
// YOU KEPT THINKING OVER AND OVER AGAIN OF HOW YOU CAN DO TOPOLOGICAL SORT WITH RECRUSIVE DFS, BUT IT IS MUCH EASIER WITH A QUEUE
void init(){
	en = counter = 0;
	memset(inDeg, 0, sizeof (int) *(n+4));
	memset(head, 0xFF, sizeof (int)*(n + 4));
}
int main(){
	// freopen("Input.txt", "r", stdin);
	while (scanf("%d%d", &n, &m), n || m){
		init();
		int x, y;
		while (m--)scanf("%d%d", &x, &y), addEdge(x, y), ++inDeg[y];	// x is a prereq for y
		stack<int>s;
		for (int i = 1; i <= n; ++i) if (!inDeg[i]) s.push(i);
		while (!s.empty()){
			int i = s.top(); s.pop();
			// printf("s: %d\n", i);
			ans[counter++] = i;
			for (int j = head[i]; j != -1; j = nxt[j]){
				int To = to[j];
				if (!--inDeg[To]) s.push(To);
			}
		}
		if (counter != n) printf("IMPOSSIBLE\n");
		else for (int i = 0; i < n; ++i) printf("%d\n", ans[i]);
	}
	return 0;
}