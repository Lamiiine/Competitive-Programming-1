#include<stdio.h>
#include<string.h>
#define MAX 105
using namespace std;
// topological sort using degrees
bool adj[MAX][MAX];
int degree[MAX];
bool done[MAX];
int n, m;
int main(){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d%d", &n, &m), n || m){
		memset(adj, 0, sizeof adj);
		memset(degree, 0, sizeof degree);
		memset(done, 0, sizeof done);
		int x, y;
		while(m--){
			scanf("%d%d", &x, &y);
			adj[y][x] = 1;	// y needs x
		}
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <=n; ++j)
				if (adj[i][j]) ++degree[i];
		bool first = true;
		for (int i = 0; i < n;){
			for (int j = 1; j <= n; ++j){
				if (!degree[j] && !done[j]) {
					done[j] = true;
					++i;
					if (!first) printf(" ");
					first = false;
					printf("%d" ,j);
					for (int k = 1; k <= n; ++k) if (adj[k][j]) --degree[k];
				}
			}
		}
		printf("\n");
	}
}

