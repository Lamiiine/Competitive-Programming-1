#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<limits.h>
using namespace std;
#define MAX 5005
#define MAX_E 60005
typedef long long int ll;
int head[MAX], nxt[MAX_E], to[MAX_E], cap[MAX_E], en;
inline void addEdge(const int f, const int t, const int c){
	nxt[en] = head[f]; head[f] = en; to[en] = t; cap[en] = c; ++en;
}
inline void addBiEdge(const int f, const int t, const int c){
	addEdge(f, t, c); addEdge(t, f, c);
}
int n, m;
int vis[MAX], visID;
int dist[MAX];
int que[1 << 16]; const int mod = (1 << 16) - 1;
inline bool bfs(){
	int back = 0;
	que[back++] = 1;
	vis[1] = visID;
	dist[1] = 0;
	for (int q = 0; q < back; ++q){
		int i = que[q];
		int d = dist[i] + 1;
		for (int j = head[i]; ~j; j = nxt[j]){
			int k = to[j];
			if (vis[k] != visID && cap[j]){
				vis[k] = visID;
				dist[k] = d;
				if (k == n) return 1;
				que[back++] = k;
			}
		}
	}
	return 0;
}
int work[MAX];
inline int dfs(const int i, const int flow){
	// you don't need to check for visitation in this BFS
	// you only check for ranking
	if (i == n) return flow;
	const int d = dist[i] + 1;
	for (int &j = work[i]; ~j; j = nxt[j]){
		int k = to[j];
		if (cap[j] && dist[k] == d)
		{
			int tmp_f = min(flow, cap[j]);
			int f = dfs(k, tmp_f);
			if (f){
				cap[j] -= f, cap[j^1] += f;
				return f;
			}
		}
	}
	return 0;
}
inline ll dinic_max_flow(){
	ll ans = 0;
	for (; bfs(); visID++){
		memcpy(work, head, sizeof work);
		for (ll f; f = dfs(1, INT_MAX); )
			ans += f;
	}
	return ans;
}
inline void init(void){
	memset(head, 0xFF, sizeof head); en = 0;
	memset(vis, 0xFF, sizeof vis); visID = 0;
	memset(dist, 0x3F, sizeof dist);
}
void read(){
	scanf("%d%d", &n, &m);
	for(int x, y, z;m--;)
		scanf("%d%d%d", &x, &y, &z), addBiEdge(x, y, z);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	init();
	read();
	printf("%lld\n", dinic_max_flow());
	return 0;
}

