#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<string>v;
vector<char> adj[26];
bool vis[26];
vector<char>ans;
bool used[26];
void dfs(char i){
	for (auto j : adj[i]) if (!vis[j]) vis[j] = true, dfs(j);
	ans.push_back(i);
}
int main(){
	// freopen("Input.txt", "r", stdin);
	char temp[23];
	memset(used, 0, sizeof used);
	memset(vis, 0, sizeof vis);
	while (scanf("%s", temp), strcmp(temp, "#")) {
		v.push_back(temp);
		for (int i = 0; temp[i]; ++i) used[temp[i] - 'A'] = true;
	}
	char a[23];
	char b[23];
	for (int i = 0; i < v.size() - 1; ++i){
		strcpy(a, v[i].c_str());
		strcpy(b, v[i + 1].c_str());
		int j = 0;
		while (a[j] && a[j] == b[j]) ++j;
		char c = a[j];
		if (c) adj[b[j] - 'A'].push_back(c - 'A');
	}
	for (int i = 0; i < 26; ++i) if (used[i] && !vis[i]) vis[i] = true, dfs(i);
	for (int i = 0; i < ans.size(); ++i) printf("%c", ans[i] + 'A');
	printf("\n");
	return 0;
}