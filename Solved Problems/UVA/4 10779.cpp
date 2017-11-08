#include<stdio.h>
#include<string.h>
#include<queue>
#include<limits.h>
#include<algorithm>
#define N 15	// max number of idiots (base for stickers)
#define M 30	// max number of stickers
#define T 45	// sink
#define S 0		// source
#define MAX 46	// N + M + 1
using namespace std;
typedef pair<int, int> ii;
int res[MAX][MAX];
int p[MAX];
int n, m;
int mf, f;
void aug(void){
	for(int i = T, j; i != S; i = j)
		j = p[i], res[j][i] -= f, res[i][j] += f;
}
void init(void){
	memset(res, 0, sizeof res);
	for (int i = N; i < N + M; ++i)
		res[i][T] = 1;
	mf = 0;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		init();
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i){
			int x; scanf("%d", &x);
			int has[M] = { 0 };	// has[j] = person i has sticker j
			while(x--){
				int y; scanf("%d", &y);
				has[y] = true;
				++res[i][y + N];
			}
			if (i)
			for (int j = 0; j < M; ++j)
				if (!has[j])res[j + N][i] = 1;
				else --res[i][j + N];
		}
		while(1){
			queue<ii>q;
			f = 0;
			memset(p, 0xFF, sizeof p);
			p[S] = S;
			q.push(ii(S, INT_MAX));
			while(!q.empty() && !f){
				int i = q.front().first, F = q.front().second;
				q.pop();
				for (int j = 0; j < MAX; ++j)
				{
					int z = res[i][j];
					if (!z || p[j] != -1) continue;
					p[j] = i, q.push(ii(j, min(F, z)));
					if (j == T){
						f = q.back().second;
						break;
					}
				}
			}
			if (!f) break;
			mf += f;
			aug();
		}
		printf("Case #%d: %d\n", tc, mf);
	}
	return 0;
}

