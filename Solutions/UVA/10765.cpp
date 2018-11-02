#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<string.h>
#define MAX 10005
using namespace std;
typedef pair<int, int> ii;
int n, m;
int root;
int counter;
int children;
int child[MAX];
int dfs_p[MAX];
int dfs_num[MAX];
int dfs_low[MAX];
int val[MAX];
bool art[MAX];
vector<int>adj[MAX];
inline void dfs(const int i){
	dfs_low[i] = dfs_num[i] = counter++;
	for (auto j : adj[i])
	if (dfs_num[j] == -1){
		dfs_p[j] = i;
		if (i == root) ++children;
		dfs(j);
		// THIS IS HOW YOU FIND THE NUMBER OF COMPONENTS AFTER REMOVING 'i'
		if (dfs_low[j] >= dfs_num[i]) art[i] = true, ++child[i];
		dfs_low[i] = min(dfs_low[i], dfs_low[j]);
	}
	// YOU FORGOT TO CHECK WHETHER OR NOT 'j' IS YOUR PARENT BEFORE RELAXING
	else if (j != dfs_p[i]) dfs_low[i] = min(dfs_low[i], dfs_num[j]);
}
int main(){
	// freopen("Input.txt", "r", stdin);
	while (scanf("%d%d", &n, &m), n || m){
		memset(dfs_num, 0xFF, sizeof dfs_num);
		memset(dfs_low, 0x3F, sizeof dfs_low);
		// 'child[i]' IS 1 LESS THAN THE NUMBER OF CHILDREN OF ARTICULATION POINT 'i'
		memset(child, 0, sizeof child);
		memset(art, 0, sizeof art);
		int x, y;
		while (scanf("%d%d", &x, &y), x != -1){
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		int numCC = 0;
		for (int i = 0; i < n; ++i)
		if (dfs_num[i] == -1){
			++numCC;
			root = i;
			counter = children = 0;
			dfs_p[i] = -1;
			dfs(i);
			if (art[i] = children > 1) child[i] = children - 1;
		}
		// wrong answer
		for (int i = 0; i < n; ++i)
		if (art[i])
			// child does not consider the parent!
			val[i] = numCC + child[i];
		else val[i] = numCC;
		vector<ii>ans;
		ans.resize(n);
		for (int i = 0; i < n; ++i) ans[i] = ii(-val[i], i);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < m; ++i)
			printf("%d %d\n", ans[i].second, -ans[i].first);
		for (int i = 0; i < n; ++i) adj[i].clear();
		printf("\n");
	}
	return 0;
}