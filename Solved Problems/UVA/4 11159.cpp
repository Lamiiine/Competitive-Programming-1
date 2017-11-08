#include<stdio.h>
#include<string.h>
#define MAX 105
using namespace std;
int n, m;
// graph
int head[MAX *2], to[MAX*MAX*2], nxt[MAX*MAX*2], en;
inline void addEdge(int x, int y){
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
int val[MAX << 1];
// matching
int match[MAX << 1];
// initialize
void init(void){
	en = 0;
	memset(head, 0xFF, sizeof head);
	memset(match, 0xFF, sizeof match);	// no one is matched
}
bool vis[MAX << 1];
bool aug(int x){
	if (vis[x]) return 0;
	vis[x] = 1;
	for (int j = head[x]; j != -1; j = nxt[j]){
		int y = to[j];
		int w = match[y];
		if (w == -1 || aug(w)){
			match[y] = x;
			return 1;
		}
	}
	return 0;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		scanf("%d", &n);
		for (int i = 0 ; i < n; ++i) scanf("%d", val + i);
		scanf("%d", &m);
		for (int i = MAX; i < MAX + m; ++i) scanf("%d", val + i);
		init();
		// 'val[i] = 0' IS A SPECIAL CASE
		// CAREFUL WHEN YOU USE '%'
		for (int i = 0; i < n; ++i){
			int v = val[i];
			if (v){
			for (int j = MAX; j < MAX + m; ++j)
				if (!(val[j]%v))addEdge(i, j), addEdge(j, i);
			}
			else{
				for (int j = MAX; j < MAX + m; ++j)
					if (!val[j])addEdge(i, j), addEdge(j, i);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
			memset(vis, 0, sizeof vis), ans += aug(i);
		printf("Case %d: %d\n", tc, ans);
	}
	return 0;
}

