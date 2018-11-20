#include<stdio.h>
#include<ctype.h>
#include<algorithm>
#include<string.h>
#include<limits.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#define MAX 105
using namespace std;

int head[MAX];
int nxt[MAX*32];
int to[MAX*32];
int en;

bool vis[MAX];
int dfs_num[MAX];
int dfs_low[MAX];
int dfs_count, m_count;
map<string, int> m;	// from string to int
string M[MAX];		// from int to string
int n;	// number of words
bool scc[MAX];
inline void init(){
	m.clear();
	en = m_count = dfs_count = 0;
	memset(vis, 0, (n+3)*sizeof vis[0]);
	memset(head, 0xFF, (n+5)*sizeof head[0]);
	memset(scc, 0, (n+5)*sizeof scc[0]);
}
inline void dfs(int i){
	dfs_num[i] = dfs_low[i] = dfs_count++;
	vis[i] = true;
	for (int j = head[i]; j != -1; j = nxt[j])
	{
		int k = to[j];
		if (!vis[k]) dfs(k);
		dfs_low[i] = min(dfs_low[i], dfs_low[k]);
	}
	if (dfs_low[i] == dfs_num[i])
		scc[i] = true;	// this vertex is head of an SCC
}
inline int index(const char * const s){
	map<string, int>::iterator x = m.find(s);
	if (x != m.end()) return x->second;
	M[m_count] = s;
	m[s] = m_count++;
	return m_count - 1;
}
inline void addEdge(const int x, const int y){
	// from i to j
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
// find all words referenced by this word
inline void dfs(int i, vector<int>&s){
	vis[i] = true;
	s.push_back(i);
	for (int j = head[i]; j != -1; j = nxt[j]){
		int k = to[j];
		if (!vis[k]) dfs(k, s);
	}
}
inline void dfs(int i, int & counter){
	++counter;
	vis[i] = true;
	for (int j = head[i]; j != -1; j = nxt[j]){
		int k = to[j];
		if (!vis[k]) dfs(k, counter);
	}
}
inline bool empty(const char * const s){
	for (int i = 0; s[i]; ++i)
		if (!isspace(s[i]))
			return false;
	return true;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	char line[1000];
	char space[7] = " \n\t\v\r\f";
	while(scanf("%d", &n), n){
		init();
		for (int i = 0; i < n; ++i){
			line[0] = 0;
			// keep reading until you find a non-empty line
			while(empty(line))
				fgets(line, INT_MAX, stdin);
			char * a = strtok(line, space);
			int x = index(a), y;
			while(a = strtok(NULL, space)) y = index(a), addEdge(x, y);
		}
		for (int i = 0; i < n; ++i)
			if (!vis[i]) dfs(i);
		int root, temp, size = INT_MAX;
		for (int i = 0; i < n; ++i){
			if (scc[i]){
				memset(vis, 0, sizeof vis);
				// DON'T FORGET TO INITIALIZE 'temp' TO '0'
				temp = 0;
				dfs(i, temp);
				if (temp < size)
					size = temp, root = i;
			}
		}
		vector<string>ans_v;
		// printf("root = %d; size = %d\n", root, size);
		memset(vis, 0, sizeof vis);
		vector<int>ans;
		dfs(root, ans);
		// YOU WROTE 'M[i]' INSTEAD OF 'M[ans[i]]'
		for (int i = 0; i < ans.size(); ++i)
			ans_v.push_back(M[ans[i]]);
		sort(ans_v.begin(), ans_v.end());	// sort alphabetically
		int x = ans_v.size();
		printf("%d\n", x--);
		for (int i = 0; i <= x; ++i)
			printf("%s%c", ans_v[i].c_str(), " \n"[i == x]);
	}
 	return 0;
}

