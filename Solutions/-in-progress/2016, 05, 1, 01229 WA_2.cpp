#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<limits.h>
#include<string.h>
#include<map>
#include<string>
#define MAX 105
using namespace std;
int head[MAX];
int to[MAX * 32];
int nxt[MAX * 32];
int en;
inline void addEdge(const int x, const int y)
{
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
bool vis[MAX];
int n;
int m_counter;
map<string, int> m;
string M[MAX];
inline void init(){
	m_counter = en = 0;	// map_counter & edge number
	m.clear();
	memset(head, 0xFF, (n + 2)*sizeof head[0]);
}
inline int dfs(const int i){
	vis[i] = true;
	int ans = 1;
	for (int j = head[i]; j != -1; j = nxt[j]){
		int k = to[j];
		if (!vis[k]) ans += dfs(k);
	}
	return ans;
}
inline int index(const char * const s){
	auto x = m.find(s);
	if (x != m.end()) return x->second;
	M[m_counter] = s;
	return m[s] = m_counter++;
}
bool empty(const char * const s){
	for (size_t i = 0; s[i]; ++i)
	if (!isspace(s[i])) return false;
	return true;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	// freopen("Output.txt", "w", stdout);
	char line[10000];
	char space[7] = " \n\t\v\r\f";
	while (scanf("%d", &n), n){
		init();
		for (int i = 0; i < n; ++i){
			*line = 0; while (empty(line)) fgets(line, INT_MAX, stdin);
			char *a = strtok(line, space);
			int x = index(a);
			while (a = strtok(0, space)) addEdge(x, index(a));
		}
		int root = -1, size = INT_MAX;
		for (int i = 0; i < n; ++i){
			memset(vis, 0, (n + 2)*sizeof vis[0]);
			int temp = dfs(i);
			if (temp < size) size = temp, root = i;
		}
		printf("%d\n", size);
		memset(vis, 0, (n + 2)*sizeof vis[0]);
		dfs(root);
		auto iter = m.begin();
		while (!vis[iter->second]) ++iter;
		printf("%s", (iter->first).c_str());
		++iter;
		for (; iter != m.end(); ++iter)if (vis[iter->second]) printf(" %s", (iter->first).c_str());
		printf("\n");
	}
	return 0;
}