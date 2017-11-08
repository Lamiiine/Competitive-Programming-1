#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<algorithm>
#define MAX 105
using namespace std;
typedef pair<int, int> ii;
int mf, f;
int p[MAX];
int res[MAX][MAX];
int s, t;
int n, m;
void augment(){
	int i, j;
	for (int i = t; i != s; i = j)
		j = p[i], res[j][i] -= f, res[i][j] += f;
}
int main(){
	int tc = 0;
	while (scanf("%d", &n), n){
		scanf("%d%d%d", &s, &t, &m);
		memset(res, 0, sizeof res);
		int x, y, z;
		while (m--) scanf("%d%d%d", &x, &y, &z), res[x][y] = (res[y][x] += z);
		mf = 0;
		while (1){
			queue<ii> q;
			f = 0;
			memset(p, 0xFF, sizeof p);
			p[s] = s;
			q.push(ii(s, INT_MAX));
			while (!q.empty() && !f){
				int i = q.front().first, F = q.front().second; q.pop();
				for (int j = 1; j <= n; ++j){
					int z = res[i][j];
					if (z && p[j] == -1)
					{
						p[j] = i, q.push(ii(j, min(F, z)));
						if (j == t) { f = q.back().second; break; }
					}
				}
			}
			if (!f) break;
			mf += f;
			augment();
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", ++tc, mf);
	}
	return 0;
}