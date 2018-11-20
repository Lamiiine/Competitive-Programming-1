#include<vector>
#include<ctype.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#define MAX 105
using namespace std;
// graph representation
int head[MAX];
int to[MAX*30];
int nxt[MAX*30];
int en;
inline void addEdge(int i, int j){
	nxt[en] = head[i];
	head[i] = en;
	to[en++] = j;
}
// string to int
int map_count;
map<string, int>m;
string M[MAX];
inline int index(string s){
	map<string, int>::iterator iter = m.find(s);
	if (iter != m.end()) return iter->second;
	m[s] = map_count;
	M[map_count] = s;
	++map_count;
	return map_count - 1;
}
// disjoint sets
int p[MAX];
int size[MAX];
inline int parent(int i){
	return p[i] == i ? i : p[i] = parent(p[i]);
}
inline void unite(int i, int j){
	int I = parent(i), J = parent(j);
	if (I == J) return;
	p[J] = I;
	size[I] += size[J];
}
inline bool same(int i, int j){
	return parent(i) == parent(j);
}
// Tarjan
int dfs_low[MAX];
int dfs_num[MAX];
int dfs_count;
enum color:char{white = 0, gray, black}vis[MAX];
vector<int>dfs_v;
void dfs(int i){
	dfs_v.push_back(i);
	dfs_low[i] = dfs_num[i] = dfs_count++;
	vis[i] = gray;
	for (int j = head[i]; j != -1; j = nxt[j]){
		int k = to[j];
		if (!vis[k]) dfs(k);
		if (vis[k] == gray) dfs_low[i] = min(dfs_low[i], dfs_low[k]);
	}
	if (dfs_low[i] == dfs_num[i]){
		int j = -1;
		while(j != i){
			j = dfs_v.back();
			dfs_v.pop_back();
			unite(i, j);
			vis[j] = black;
		}
	}
}
// dictionary
bool outDeg[MAX];
// initialize test case
inline void init(void){
	dfs_count = map_count = en = 0;
	memset(head, 0xFF, sizeof head);
	memset(vis, 0, sizeof vis);
	memset(outDeg, 0, sizeof outDeg);
	for (int i = 0; i < MAX; ++i)
		p[i] = i, size[i] = 1;
	m.clear();
	dfs_v.clear();
}
// int order[MAX];	// alphapetical order of a word
bool empty(char * s){
	for (int i = 0; s[i]; ++i)
		if (!isspace(s[i])) return false;
		return true;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int n;
	char line[1000];
	char space[3] = " \n";
	while(scanf("%d", &n), n){
		init();
		for (int line_count = 0; line_count < n; ++line_count){
			*line = 0;while(empty(line))fgets(line, INT_MAX, stdin);
			char * word =  strtok(line, space);
			int i = index(word);
			for (word = strtok(NULL, space); word != NULL; word = strtok(NULL, space))
				addEdge(i, index(word));
		}
		for (int i = 0; i < map_count; ++i)
			if (!vis[i]) dfs(i);

		for (int i = 0; i < map_count; ++i){
			int I = parent(i);
			for (int j = head[i]; j != -1; j = nxt[j]){
				int k = to[j];
				if (parent(k) != I)outDeg[I] = true;
			}
		}
		int ans_val = INT_MAX, ans_ind;
		for (int i = 0; i < map_count; ++i){
			int I = parent(i);
			if (!outDeg[I])
				if (size[I] < ans_val){
					ans_val = size[I]; ans_ind = I;
				}
		}
		printf("%d\n", ans_val);
		vector<string>v;
		for (int i = 0; i < map_count; ++i)
			if (parent(i) == ans_ind)	// a word in my subdictionary
				v.push_back(M[i]);
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); ++i)
			printf("%s%c", v[i].c_str(), " \n"[i == v.size() - 1]);
	}
	return 0;
}

