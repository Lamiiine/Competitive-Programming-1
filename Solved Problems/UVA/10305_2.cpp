#include<stdio.h>
#include<string.h>
#include<vector>
#define MAX 105
using namespace std;
// topological sort using dfs
vector<int>adj[MAX];
int n, m;
bool vis[MAX];
vector<int>ans;
void dfs(int i){
	if (vis[i]) return;
	vis[i] = true;
	for (vector<int>::iterator iter = adj[i].begin(); iter != adj[i].end(); ++iter)
		if (!vis[*iter])
			dfs(*iter);
	ans.push_back(i);
}
void print(){
	printf("%d", ans[0]);
	for (size_t i = 1; i < ans.size(); ++i)
		printf(" %d", ans[i]);
	printf("\n");
}
int main(){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d%d", &n, &m), n || m){
		memset(vis, 0, sizeof vis);
		int x, y;
		while(m--){
			scanf("%d%d", &x, &y);
			adj[y].push_back(x);
		}
		for (int i = 1; i <= n; ++i)
			if (!vis[i])
				dfs(i);
		print();
		for (int i = 1; i <= n; ++i)
			adj[i].clear();
		ans.clear();
	}
}

