#include<stdio.h>
#include<string.h>
#include<queue>
#define MAX 205
using namespace std;
int p[MAX << 2];
int x, y, z, n;
void init(void){
	memset(p, 0xFF, sizeof p);
}
void bfs(){
	int val[3] = {x, y, -z};
	queue<int>q;
	q.push(x); p[x] = 0;
	q.push(y); p[x] = 0;
	while(!q.empty()){
		int v = q.front(); q.pop();
		for (int i = 0; i < 3; ++i){
			int u = v + val[i];
			if (u < 0 || u >= (MAX << 2) || p[u] != -1) continue;
			p[u] = v;
			q.push(u);
		}
	}
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d%d%d%d", &x, &y, &z, &n) != EOF){
		init();
		bfs();
		if (p[n] == -1) {printf("-1\n");continue;}
		int counter[3] = {0};
		int i = n;
		while(i){
			int val = i - p[i];
			if (val == x) counter[0]++;
			else if (val == y) counter[1]++;
			else if (val == -z) counter[2]++;
			i = p[i];
		}
		printf("%d %d %d\n", counter[0], counter[1], counter[2]);
	}
	return 0;
}
