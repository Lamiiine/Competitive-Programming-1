#include<stdio.h>
#include <queue>
#include <string.h>
#define MAX 52
#define MAXX 1005
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
int dist[MAX][MAXX];
int cost[MAX][MAX];
int time[MAX][MAX];
int n, t;
int dij(){
	dist[0][0] = 0;
	priority_queue<iii> q;
	q.push(iii(ii(0, 0), 0));
	while(!q.empty()){
		int v = q.top().second;
		int cur_cost  = -q.top().first.first;
		int cur_time = -q.top().first.second;
		q.pop();
		if (dist[v][cur_time] < cur_cost) continue;
		for (int i = 0; i < n; ++i){
			int Time = cur_time + time[v][i];
			int Cost = cur_cost + cost[v][i];
			if (Time <= t && dist[i][Time] > Cost){
				dist[i][Time] = Cost;
				q.push(iii(ii(-Cost, - Time), i));
			}
		}
	}
}
int main(){
	while(scanf("%d%d", &n, &t), n || t){
		memset(dist, 0x7F, sizeof dist);
		// THE PROBLEM STATEMENT SAID SCAN TIME BEFORE COST!!!!!!!!
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		scanf("%d", &time[i][j]);
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		scanf("%d", &cost[i][j]);	// YOU WERE STORING IN THE WRONG ARRAY!!!!!
		dij();
		--n;
		int ans;
		memset(&ans, 0x7F, sizeof ans);
		int total = -1;
		for (int i = 0; i <= t; ++i)
		if (dist[n][i] < ans) ans = dist[n][i], total = i;
		printf("%d %d\n", ans, total);
	}
	return 0;
}