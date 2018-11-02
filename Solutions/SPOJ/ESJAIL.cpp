#include<stdio.h>
#include<queue>
#include<string.h>
#include<string>
#define MAX 100005
using namespace std;
enum visit :char{ unvisited = 0, visited = 1, exploered = 2 };
bool hasKey[MAX];	// I have obtained the key of the door in champer i
int key[MAX];		// location of door opened by the key in champer i
int n, m, k;
int en;
int head[MAX];
int to[MAX << 1];
int nxt[MAX << 1];
visit vis[MAX];
inline void addEdge(const int x, const int y){
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
// BFS WHEN YOU GRADUALLY ACQUIRE ACCESS TO NODES AS YOU VISIT MORE NODES!
bool bfs(){
	queue<int>q;
	q.push(1);	// you have reached this
	vis[1] = visited;
	while (!q.empty()){
		int s = q.front();
		q.pop();
		for (int i = head[s]; i != -1; i = nxt[i]){
			int To = to[i];
			if (To == n) return true;
			// if it has a blocked door, mark it as explored
			if (!hasKey[To]) vis[To] = exploered;
			else if (!vis[To]){
				vis[To] = visited;
				q.push(To);
				int x;
				if (x = key[To]){
					hasKey[x] = true;
					if (vis[x] == exploered) q.push(x);
				}
			}
		}
	}
	return false;
}
void init(){
	// initially, you can go into all champers
	memset(hasKey, 1, sizeof hasKey);
	// champers contain no keys
	memset(key, 0, sizeof key);
	// you have not visited any
	memset(vis, 0, sizeof vis);
	en = 0;
	memset(head, 0xFF, sizeof head);
}
int main(){
	// YOU WERE READING INPUT IN WRONG ORDER!
	while (scanf("%d%d%d", &n, &k, &m), n != -1){
		init();
		int x, y;
		while (k--){
			scanf("%d%d", &x, &y);
			key[x] = y;		// x has key to y
			hasKey[y] = 0;	// for now, you don't have access to y
		}
		while (m--){
			scanf("%d%d", &x, &y); addEdge(x, y); addEdge(y, x);
		}
		char yes[2] = "Y", no[2] = "N";
		printf("%s\n", bfs() ? yes : no);
	}
	return 0;
}