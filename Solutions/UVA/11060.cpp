#include<stdio.h>
#include<vector>
#include<string.h>
#include<string>
#include<map>
#define MAX 105
using namespace std;
int n;
vector<int>adj[MAX];
int deg[MAX];
bool vis[MAX];
map<string, int> m;
map<int, string> M;
int main() {
	// freopen("Input.txt", "r", stdin);
	char s[55];
	int tc = 0;
	while (scanf("%d", &n) != EOF) {
		++tc;
		memset(vis, 0, sizeof vis);
		memset(deg, 0, sizeof deg);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			m[s] = i;
			M[i] = s;
		}
		int a;
		scanf("%d", &a);
		while(a--){
			scanf("%s", s);
			int i = m[s];
			scanf("%s", s);
			int j =  m[s];
			++deg[j];
			adj[i].push_back(j);
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", tc);
		// WHEN YOU NEED TO SORT TOPOLOGICALLY IN A GIVEN ORDER, USE DEGREES
		for (int a = 0; a < n; ++a){
			int i = 0;
			while(vis[i] || deg[i]) ++i;
			vis[i] = true;
			for (int j = 0; j < adj[i].size(); ++j) --deg[adj[i][j]];
			printf(" %s", M[i].c_str());
		}
		for (int i = 0; i < n; ++i) adj[i].clear();
		printf(".\n\n");
		m.clear();
		M.clear();
	}
	return 0;
}

