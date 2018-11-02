#include <bits/stdc++.h>
using namespace std;
const int inf = int(1e4);

int dp[105][1005];
int n, m, l;
int coin_costs[105];
int coin_values[105];
int station_positions[105];
int abs_costs[1005];
int src, dest;
void init(){
	memset(dp, -1, sizeof dp);
}
int min_cost_to_make(int idx, int x){
	if(x == 0)
		return 0;
	if(idx == m)
		return inf;
	int& ret = dp[idx][x];
	if(ret != -1)
		return ret;
	if(coin_values[idx] <= x){
		return ret = min(coin_costs[idx] + min_cost_to_make(idx + 1, x - coin_values[idx]), min_cost_to_make(idx + 1, x));
	}
	return ret = min_cost_to_make(idx + 1, x);
}

int get_cost(int u, int v){
	int abs_cost = min_cost_to_make(0, abs(station_positions[u] - station_positions[v]));
	if(abs_cost > l)
		return -1;
	return abs_cost;
}
int min_num_moves(){
	priority_queue<pair<int, int>> pq;
	vector<int> dist(105, inf);
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while(!pq.empty()){
		int u = pq.top().second;
		int n_moves = -pq.top().first;
		pq.pop();
		if(u == dest)
			return n_moves;

		for (int v = 0; v < n; v ++){
			if(u == v) continue;
			if(dist[v] > dist[u] + 1){
				int cst = get_cost(u, v);
				if(cst != -1){
					dist[v] = dist[u] + 1;
					pq.push(make_pair(-dist[v] , v));
				}
			}
		}
	}
	return -1;
}
int main(){
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &n, &m, &l);
		int min_val = 1010;
		int arg_min;
		int max_val = -1;
		int arg_max;
		for(int i = 0; i < n; i ++){
			scanf("%d", station_positions + i);
			if(station_positions[i] > max_val){
				max_val = station_positions[i];
				arg_max = i;
			}
			if(station_positions[i] < min_val){
				min_val = station_positions[i];
				arg_min = i;
			}
		}
		src = arg_min;
		dest = arg_max;
		for (int i = 0; i < m; i ++){
			scanf("%d %d", coin_costs + i, coin_values + i);
		}
		init();
		printf("%d\n", min_num_moves());
	}
}

