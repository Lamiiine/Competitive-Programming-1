#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAX 152
using namespace std;
int dist[MAX][MAX][MAX];
int adj[MAX][MAX];
int n;	// graph order
int p;	// number of rankings
int q;	// number of queries
int k, s, t;	// k, source, destination
int name[MAX];
int main() {
	// freopen("Input.txt", "r", stdin);
	int INF;
	memset(&INF, 0x3F, sizeof INF);
	int tc, TC;
	scanf("%d", &TC);
	for (tc = 1; tc <= TC; ++tc) {
		memset(dist, 0x3F, sizeof dist);
		printf("Case %d:", tc);
		scanf("%d", &n);
		int x;
		for (int i = 1; i <= n; ++i) {
			adj[i][i] = 0;
			for (int j = i + 1; j <= n; ++j) {
				scanf("%d", &x);
				if ((x == -1))
					adj[i][j] = adj[j][i] = INF;
				else
					adj[i][j] = adj[j][i] = x;
			}
		}
		scanf("%d", &p);
		for (int i = 1; i <= p; ++i) {
			scanf("%d", &x);
			name[i] = x;
		}
		scanf("%d", &q);

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j][0] = adj[i][j];	// using 0 intermediate vertices
		// this is the olive
		for (int m = 1; m <= p; ++m)
		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dist[i][j][m] = min(dist[i][j][m-1], dist[i][name[m]][m-1] + dist[name[m]][j][m-1]);
		while (q--) {
			scanf("%d%d%d", &k, &s, &t);
			int ans = dist[s][t][k];
			if (ans == INF)
				printf(" -1");
			else
				printf(" %d", ans);
		}
		printf("\n");
	}
	return 0;
}

