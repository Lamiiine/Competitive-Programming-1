#include<bits/stdc++.h>
#define MAX 50010
using namespace std;
int n, r1, r2;
vector<int>adj[MAX];
bool vis[MAX] = {};
int p[MAX];
void dfs(const int i){
	vis[i] = true;
	const vector<int>&v = adj[i];
	for (int j = 0; j < v.size(); ++j){
		int k = v[j];
		if (!vis[k])
			p[k] = i, dfs(k);
	}
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	scanf("%d%d%d", &n, &r1, &r2);
	for (int i = 1, x; i <= n; ++i)
		if (i != r1)
			scanf("%d", &x), adj[i].push_back(x), adj[x].push_back(i);
	dfs(r2);
	for (int i = 1; i <= n; ++i)
		if (i != r2)
			printf("%d ", p[i]);
	return 0;
}

