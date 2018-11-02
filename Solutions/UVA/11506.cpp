#include<stdio.h>
#include<queue>
#include<limits.h>
#include<string.h>
#include<algorithm>
#define N 55
#define MAX 110
using namespace std;
typedef pair<int, int> ii;
int mf, f;
int s, t;
int res[MAX][MAX];
int p[MAX];
int n, m;	// number of machines and wires
int in(int i){return i;}
int out(int i){return i + N;}
void init(void){
	memset(res, 0, sizeof res);
	mf = 0;
}
void read(void){
	s = out(1);
	t = in(n);
	int x, y, z;
	// read machine info
	for (int i = 0; i < n-2; ++i){
		scanf("%d%d", &x, &y);
		res[in(x)][out(x)] = y;
		// res[out(x)][in(x)] = y;
	}
	// read wire info
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		res[out(x)][in(y)] = z;
		res[out(y)][in(x)] = z;
	}
}
void aug(){
	for (int i = t, j; i != s; i = j)
		j = p[i], res[j][i] -= f, res[i][j] += f;
}
int solve(void){
	while(1){
		f = 0;
		memset(p, 0xFF, sizeof p);
		p[s] = s;
		queue<ii>q;
		q.push(ii(s, INT_MAX));
		while(!q.empty() && !f){
			int i = q.front().first, F = q.front().second;
			q.pop();
			for (int j = 0; j < MAX; ++j){
				int z = res[i][j];
				if (!z || p[j] != -1) continue;
				p[j] = i;
				q.push(ii(j, min(F, z)));
				if (j == t){
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
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d%d", &n, &m), n || m){
		init();
		read();
		printf("%d\n", solve());
	}
	return 0;
}

