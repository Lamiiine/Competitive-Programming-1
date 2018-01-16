#include<stdio.h>
#include<vector>
#include<string.h>
#define MAX 55
using namespace std;
bool vis[MAX] = {};
vector<int>adj[MAX];
inline bool dfs(const int i, const int j){
	for (auto k : adj[i]){
		if (k == j) return true;
		if (!vis[k]) { vis[k] = true; if (dfs(k, j)) return true; }
	}
	return false;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int counter[MAX] = {};
	int n;
	scanf("%d", &n);
	int num = n;
	num *= (n - 1);
	num >>= 1;
	--num;
	int x, y;
	int ans[2] = {};
	for (int i = 0; i < num; ++i) {
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		++counter[x];
		++counter[y];
	}

	for (int i = 1; i <= n; ++i) if (counter[i] < n - 1) ans[bool(ans[0])] = i;
	// if 'ans[0]' is an ancestor of 'ans[1]'
	vis[ans[0]] = true;
	if (dfs(ans[0], ans[1])) printf("%d %d", ans[0], ans[1]);
	else printf("%d %d", ans[1], ans[0]);
	return 0;
}