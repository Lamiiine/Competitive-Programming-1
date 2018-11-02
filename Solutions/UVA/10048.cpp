// A disguised Floyd Warshall problem
// See the small variation in the distance definition
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX 105
using namespace std;
typedef pair<int, int> ii;
int c, s, q;
int dist[MAX][MAX];
int main(){
	int caseNum = 0;
	while(scanf("%d%d%d", &c, &s, &q), c || s || q){
		if (++caseNum != 1) printf("\n");
		printf("Case #%d\n", caseNum);

		int inf;
		memset(&inf, 0x7F, sizeof inf);
		memset(dist, 0x7F, sizeof dist);
		for (int i = 1; i <= c; ++i) dist[i][i] = 0;
		int x, y, z;
		for (int i = 0; i < s; ++i){
			scanf("%d%d%d", &x, &y, &z);
			dist[x][y] = dist[y][x] = min(dist[x][y], z);
		}
		for (int k = 1; k <= c; ++k)
		for (int i = 1; i <= c; ++i)
		for (int j = 1; j <= c; ++j) dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
		int a, b;
		int temp;
		while(q--){
			scanf("%d%d", &a, &b);
			if ((temp = min(dist[a][b], dist[b][a])) < inf)printf("%d\n", temp);
			else printf("no path\n");
		}
	}
	return 0;
}