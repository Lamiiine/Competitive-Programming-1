#include <stdio.h>
#include <vector>
#define MAX 105
using namespace std;
int n, m;
vector<int> adj[MAX];
bool vis[MAX];
void dfs(int s){	// source
	vis[s] = true;
	for (auto iter = adj[s].begin(); iter != adj[s].end(); ++iter)
	if (!vis[*iter]) dfs(*iter);
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n != m) {
		printf("NO");
		return 0;
	}
	int x, y;
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i)
	if (!vis[i])
	{
		printf("NO");
		return 0;
	}
	printf("FHTAGN!");
	return 0;
}