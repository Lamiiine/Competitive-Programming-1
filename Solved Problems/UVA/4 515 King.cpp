#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
int n, m;
int head[MAX], to[MAX], nxt[MAX], cost[MAX], en;
inline void addEdge(const int f, const int t, const int c){
	nxt[en] = head[f];
	head[f] = en;
	to[en] = t;
	cost[en] = c;
	++en;
}
char s[5];
inline void read(){
	for(int x, y, z;m--;){
		scanf("%d%d%s%d", &x, &y, s, &z);
		y += x; --x;
		if (*s == 'g')
			addEdge(y, x, -z-1);
		else
			addEdge(x, y, z - 1);
	}
}
int dist[MAX];
inline bool bell(void){
	for (int iter = 0; iter < n; ++iter)
		for (int i = 0; i <= n; ++i)
			for (int j = head[i]; ~j; j = nxt[j])
				dist[to[j]] = min(dist[to[j]], dist[i] + cost[j]);
	for (int iter = 0; iter < n; ++iter)
		for (int i = 0; i <= n; ++i)
			for (int j = head[i]; ~j; j = nxt[j])
				if (dist[to[j]] > dist[i] + cost[j]) return true;
	return false;
}
inline void init(void){
	memset(head, 0xFF, sizeof head); en = 0;
	memset(dist, 0, sizeof dist);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d", &n), n){
		init();
		scanf("%d", &m);
		read();
		printf("%s\n", bell() ? "successful conspiracy" : "lamentable kingdom");
	}
	return 0;
}

