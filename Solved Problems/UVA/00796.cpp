#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define MAX 1005
using namespace std;
typedef pair<int, int> ii;
int counter;
vector<int >dfs_p;
vector<int> dfs_num;
vector<int >dfs_low;
vector<vector<int>>adj;
vector<ii>b;
void dfs(const int i){
	dfs_num[i] = dfs_low[i] = counter++;
	for (int j = 0; j < adj[i].size(); ++j){
		int x;
		if (dfs_num[x = adj[i][j]] == -1){
			dfs_p[x] = i;
			dfs(x);
			if (dfs_low[x] > dfs_num[i]) b.push_back((i < x)?ii(i, x):ii(x, i));
			dfs_low[i] = min(dfs_low[i], dfs_low[x]);
		}
		else if (x != dfs_p[i]) dfs_low[i] = min(dfs_low[i], dfs_num[x]);
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int n;
	int INF;
	memset(&INF, 0x3F, sizeof INF);
	while (scanf("%d", &n) != EOF){
		adj.resize(n + 2);
		dfs_low.assign(n + 2, INF);
		dfs_num.assign(n + 2, -1);
		dfs_p.resize(n + 2);

		int x, y, z;
		for (int i = 0; i < n; ++i){
			scanf("%d (%d)", &x, &z);
			while (z--){
				scanf("%d", &y);
				adj[x].push_back(y);
			}
		}
 		for (int i = 0; i < n; ++i)
		if (dfs_num[i] == -1){
			// printf("%d\n", i);
			counter = 0;
			dfs_p[i] = -1;
			dfs(i);
		}
		sort(b.begin(), b.end());
		printf("%d critical links\n", b.size());
        for (int i = 0; i < b.size(); ++i) printf("%d - %d\n", b[i].first, b[i].second);
		printf("\n");
		b.clear();
		for (int i = 0; i < n; ++i) adj[i].clear();
	}
	return 0;
}