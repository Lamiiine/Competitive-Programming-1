#include<stdio.h>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<map>
#define MAX 105
using namespace std;
int n;
int counter;
int root;
int children;
int dfs_p[MAX];
bool art[MAX];
int dfs_num[MAX];
int dfs_low[MAX];
vector<int>adj[MAX];
inline void dfs(const int i){
	dfs_low[i] = dfs_num[i] = counter++;
	for (auto j : adj[i]){
		// TYPO! YOU WROTE 'i' INSTEAD OF 'j'
		if (dfs_num[j] == -1){
			dfs_p[j] = i;
			if (i == root) ++children;
			dfs(j);
			if (dfs_low[j] >= dfs_num[i]) art[i] = true;
			// IF HE IS YOUR CHILD, YOU CAN USE 'dfs_low'
			dfs_low[i] = min(dfs_low[i], dfs_low[j]);
		}
		// IF HE IS NOT YOUR CHILD, YOU CAN ONLY USE 'dfs_num'
		else if (j != dfs_p[i]) dfs_low[i] = min(dfs_low[i], dfs_num[j]);
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	map<string, int>m;
	string M[MAX];
	char s[35];
	char a[35];
	int tc = 0;
	bool firstCase = true;
	while (scanf("%d", &n), n){
		if (!firstCase) printf("\n");
		firstCase = false;
		memset(art, 0, sizeof art);
		memset(dfs_num, 0xFF, sizeof dfs_num);
		memset(dfs_low, 0x3F, sizeof dfs_low);
		printf("City map #%d: ", ++tc);
		for (int i = 0; i < n; ++i){
			scanf("%s", s);
			m[s] = i;
			M[i] = s;
		}
		int x;
		scanf("%d", &x);
		while (x--){
			scanf("%s%s", a, s);
			int y = m[a];
			int z = m[s];
			adj[y].push_back(z), adj[z].push_back(y);
		}

		for (int i = 0; i < n; ++i)
		if (dfs_num[i] == -1){
			// printf("%d\n", i);
			dfs_p[i] = -1;
			children = counter = 0;
			root = i;
			dfs(i);
			art[i] = children > 1;
		}
		// for (int i = 0; i < n; ++i) printf("%d %d\n", i, dfs_num[i]);
		int ans = 0;
		set<string>S;
		for (int i = 0; i < n; ++i)
		if (art[i]) ++ans, S.insert(M[i]);
		printf("%d camera(s) found\n", ans);
		for (auto iter = S.begin(); iter != S.end(); ++iter) printf("%s\n", iter->c_str());
		m.clear();
		for (int i = 0; i < n; ++i) adj[i].clear();
	}
	return 0;
}