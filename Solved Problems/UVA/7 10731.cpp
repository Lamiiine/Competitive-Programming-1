#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#define MAX 30
using namespace std;
int n;
vector<char>adj[MAX];
vector<char>comp[MAX];
bool used[MAX];
int dfs_num[MAX];
int dfs_low[MAX];
int dfs_count;
enum color :char{ white = 0, grey, black } vis[MAX];
inline void init(){
	dfs_count = 0;
	for (auto &v : adj) v.clear();
	for (auto &v : comp) v.clear();
	memset(dfs_num, 0xFF, sizeof dfs_num);
	memset(vis, 0, sizeof vis);
	memset(used, 0, sizeof used);
}
vector<char>dfs_v;
inline void dfs(const int i){
	dfs_v.push_back(i);
	dfs_num[i] = dfs_low[i] = dfs_count++;
	vis[i] = grey;
	for (auto j : adj[i]){
		if (dfs_num[j] == -1) dfs(j);
		if (vis[j] == grey) dfs_low[i] = min(dfs_low[i], dfs_low[j]);
	}
	if (dfs_low[i] == dfs_num[i]){
		// head of a component
		set<char>temp_comp;
		char j = -1;
		while (j != i){
			j = dfs_v.back();
			dfs_v.pop_back();
			temp_comp.insert(j);
			vis[j] = black;
		}
		j = *temp_comp.begin();
		for (char k : temp_comp) comp[j].push_back(k);
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	bool first = true;
	while (scanf("%d", &n), n){
		init();
		if (!first) printf("\n");
		first = false;
		char s[6][3];
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < 6; ++j) scanf("%s", s[j]);
			char c = s[5][0] - 'A';
			used[c] = true;
			for (int j = 0; j < 5; ++j) { char d = s[j][0] - 'A'; used[d] = true; adj[c].push_back(d); }
		}
		for (int i = 0; i < MAX; ++i) if (used[i] && dfs_num[i] == -1) dfs(i);
		for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < comp[i].size(); ++j)
			printf("%c%c", comp[i][j] + 'A', " \n"[j == comp[i].size() - 1]);
	}
}