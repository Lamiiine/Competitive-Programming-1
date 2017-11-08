#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#define MAX 205
using namespace std;
typedef pair<int, int> ii;
vector<int> adj[MAX];
char color[MAX];
int n;
bool valid(int i){
	if (color[i] != char(-1)) return true;
	color[i] = 0;
	stack<ii> s;
	s.push(ii(i, color[i]));
	while(!s.empty()){
		int v = s.top().first;
		int cur = s.top().second;
		s.pop();
		int u;
		for (auto iter = adj[v].begin(); iter != adj[v].end(); ++iter){
		if (color[u = *iter] == cur) return false;
		if (color[u] != char(-1)) continue;
		color[u] = 1^cur;
		s.push(ii(u, color[u]));
	}
	}
	return true;
}
int main(){
	// This problem was using zero based indexing!
	int l;
	int x, y;
	while(scanf("%d%d", &n, &l), n){
		memset(color, 0xFF, sizeof color);
		while(l--){
			scanf("%d%d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		bool flag = true;
		// I was using square brackets instead of parenthesis in the function call!
		for (int i = 0; i < n; ++i) if (!valid(i)) {printf("NOT BICOLORABLE.\n"); flag = false;}
		if (flag) printf("BICOLORABLE.\n");
		for (int i = 0; i < n; ++i) adj[i].clear();
	}
	return 0;
}
