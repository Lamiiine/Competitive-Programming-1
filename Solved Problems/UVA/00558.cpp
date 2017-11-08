#include <stdio.h>
#include<string.h>
#include<algorithm>
#define MAX 1005
using namespace std;
int head[MAX];
int nxt[MAX << 1];
int to[MAX << 1];
int cost[MAX << 1];
int n, m;
int en;
int dist[MAX];
bool bellman(){
	dist[0] = 0;	// a random vertex
	bool flag = true;
	for (int j = 0; flag && j < n; ++j){
		flag = false;
		for (int i = 0; i < n; ++i){
			int index = head[i];
			while (index != -1){
				int To = to[index];
				int Cost = cost[index];
				if (dist[To] > dist[i] + Cost){
					dist[To] = dist[i] + Cost;
					flag = true;
				}
				index = nxt[index];
			}
		}
	}
	return flag;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--){
		memset(head, 0xFF, sizeof head);
		memset(dist, 0x7F, sizeof dist);
		en = 0;
		scanf("%d%d", &n, &m);
		if (n == 1) { printf("not possible\n"); continue; }
		int x, y, z;
		for (int i = 0; i < m; ++i){
			scanf("%d%d%d", &x, &y, &z);
			nxt[en] = head[x];
			head[x] = en;
			to[en] = y;
			cost[en++] = z;
		}
		if (bellman()) printf("possible\n");
		else printf("not possible\n");
	}
	return 0;
}