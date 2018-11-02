// GOT A 'TLE' BECASUE OF USING 'DBL'; GOT 'AC' WHEN YOU STARTED USIGN 'FLT'
#include<stdio.h>
#include<float.h>
#include<iostream>
#include<limits.h>
#include<algorithm>
#include<queue>
#include<string.h>
#define MAX 32
using namespace std;
typedef float f;
int k, n, m, s, t;
float dist[MAX][1 << 8];
float p[10];	// number of horses in each coach ticket
int en;
int head[MAX];
int to[MAX*MAX];
int nxt[MAX*MAX];
float cost[MAX*MAX];
void addEdge(const int x, const int y, const float z){
	nxt[en] = head[x];
	head[x] = en;
	to[en] = y;
	cost[en++] = z;
}
void init(){
	en = 0;
	memset(dist, 0x7F, sizeof dist);
	// for (int i = 0; i < MAX; ++i) fill(dist[i], dist[i] + (1 << 8), DBL_MAX);
	// fill(dist, dist + sizeof(dist), DBL_MAX);
	memset(head, 0xFF, sizeof head);
}
struct state{
	int v;	// current city
	int s;	// state
	float t;	// time
};
bool operator < (const state & a, const state & b){
	return a.t > b.t;
}
float dij(){
	dist[s][0] = 0.0;
	priority_queue<state>q;
	q.push(state{ s, 0, 0.0 });
	while (!q.empty()){
		state cur = q.top(); q.pop();
		// printf("%d %d %llf\n", cur.v, cur.s, cur.t);
		// if (cur.v == t) ans = min(ans, cur.t);
		if (cur.v == t) return cur.t;
		if (dist[cur.v][cur.s] < cur.t) continue;
		for (int i = head[cur.v]; i != -1; i = nxt[i]){
			int u = to[i];	// for each neighbor
			for (int j = 0; j < k; ++j){	// for each ticket you still have
				if (((1 << j) & cur.s)) continue;	// YOU HAD THIS CONDITION WRONG!
				int temp_s = cur.s | (1 << j);
				float temp_t = cur.t + cost[i] / p[j];
				// YOU USED '<' INSTEAD OF '>'!!!
				if (dist[u][temp_s] > temp_t)	// if you can get a smaller distance to this state
					q.push(state{ u, temp_s, dist[u][temp_s] = temp_t });
				// printf("%d %d %llf %llf\n", u, temp_s, temp_t, dist[u][temp_s]);
			}
		}
	}
	return FLT_MAX;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	while (scanf("%d%d%d%d%d", &k, &n, &m, &s, &t), n){
		init();
		// for (int i = 0; i < n; ++i) printf("%llf\n", dist[i][0]);
		for (int i = 0; i < k; ++i) scanf("%f", p + i);
		int x, y;
		float z;
		while (m--)
			scanf("%d%d%f", &x, &y, &z), addEdge(x, y, z), addEdge(y, x, z);
		float ans = dij();
		// YOU MOVED FROM 'DBL' TO 'FLT', BUT FORGET TO CHANGE IT HERE!
		if (ans == FLT_MAX) printf("Impossible\n");
		else printf("%f\n", ans);
	}
}