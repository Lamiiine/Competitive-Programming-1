#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<algorithm>
/*
 * input to regulator (0 -> N - 1)
 * output from regulator (N -> 2N - 1)
 */
#define N 105
#define S 210
#define T 211
#define INF (INT_MAX >> 1)
#define MAX 212	// 2N + 2
using namespace std;
typedef pair<int, int> ii;
int mf, f;
int p[MAX];
int n, m;
int s, t;
int res[MAX][MAX];
inline const int in(int i) {
	return i;
}
inline const int out(int i) {
	return i + N;
}
void init(void) {
	memset(res, 0, sizeof res);
}
void read(void) {
	int x, y, z;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		res[in(i)][out(i)] = x;
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d%d", &x, &y, &z);
		res[out(--x)][in(--y)] += z;
	}
	int b, d;
	scanf("%d%d", &b, &d);
	while(b--){
		scanf("%d", &x);
		res[S][in(--x)] = INF;
	}
	while(d--){
		scanf("%d", &x);
		res[out(--x)][T] = INF;
	}
}
void aug(void){
	for (int i = T, j; i != S; i = j)
		j = p[i], res[j][i] -= f, res[i][j] += f;
}
int solve(void){
	mf = 0;
	while(1){
		f = 0;
		memset(p, 0xFF, sizeof p);
		p[S] = S;
		queue<ii>q;
		q.push(ii(S, INT_MAX));
		while(!q.empty() && !f){
			int i = q.front().first, F = q.front().second;
			q.pop();
			for (int j = 0; j < MAX; ++j){
				int z = res[i][j];
				if (!z || p[j] != -1) continue;
				p[j] = i;
				q.push(ii(j, min(z, F)));
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
	return mf;
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		init();
		read();
		printf("%d\n", solve());
	}
	return 0;
}

