#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<string>
#include<string.h>
#define MAX 105
using namespace std;
int n;
int counter;
int root;
int parent[MAX];
int num[MAX];
int low[MAX];
bool art[MAX];
int children;
vector<int>adj[MAX];
void dfs(const int i){
	num[i] = low[i] = counter++;
	for (int j = 0; j < adj[i].size(); ++j){
		int v = adj[i][j];
		if (num[v] == -1){
			parent[v] = i;
			if (i == root) ++children;
			dfs(v);
			if (low[v] >= num[i])
				art[i] = true;
			low[i] = min(low[i], low[v]);
		}
		// compare your dfs_low to the dfs_num of this neighbor
		else if (parent[i] != v) low[i] = min(low[i], num[v]);
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	string s;
	while (scanf("%d", &n), n){
		int v;
		while (scanf("%d", &v), v){
			getline(cin, s);
			int u;
			char * token = strtok(const_cast<char*>(s.c_str()), " ");
			while (token != nullptr){
				sscanf(token, "%d", &u);
				adj[v].push_back(u), adj[u].push_back(v);
				token = strtok(NULL, " ");
			}
		}
		counter = 0;
		memset(num, 0xFF, sizeof num);
		memset(low, 0x3F, sizeof low);
		memset(art, 0, sizeof art);
		memset(parent, 0, sizeof parent);
		for (int i = 1; i <= n; ++i)
		if (num[i] == -1)
		{
			root = i;
			children = 0;
			dfs(i);
			art[i] = children > 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) ans += (art[i]);
		printf("%d\n", ans);
		for (int i = 1; i <= n; ++i) adj[i].clear();
	}
	return 0;
}