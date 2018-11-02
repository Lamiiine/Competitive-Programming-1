#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<vector>
#define MAX 30
using namespace std;
bool dist[MAX][MAX];
int n;
int counter;
map<string, int> m;
map<int, string> M;
inline int index(const char * const s){
	auto x = m.find(s);
	if (x != m.end()) return x->second;
	M[counter] = s;
	return m[s] = counter++;
}
int p[MAX];
vector<int>comp[MAX];
inline void init(){
	// DON'T FORGET TO CLEAR THE MAPS!
	m.clear();
	M.clear();
	counter = 0;
	memset(dist, 0, sizeof dist);
	for (int i = 0; i < n; ++i)
		p[i] = i, comp[i].clear();
}
inline void FW(){	// Floyd-Warshall
	for (int k = 0; k < n; ++k)
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
		dist[i][j] |= (dist[i][k] & dist[k][j]);
}
inline int parent(const int i){
	return p[i] == i ? i : p[i] = parent(p[i]);
}
inline void unite(const int i, const int j){
	p[parent(i)] = parent(j);
}
void solve(){
	for (int i = 0; i < n; ++i)
	for (int j = i + 1; j < n; ++j)
	if (dist[i][j] & dist[j][i])
		unite(i, j);	// they belong to the same circle
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int q;
	char a[MAX];
	char b[MAX];
	bool first = true;
	int tc = 0;
	while (scanf("%d%d", &n, &q), n || q){
		if (!first) printf("\n");
		first = false;
		printf("Calling circles for data set %d:\n", ++tc);
		init();
		while (q--)
			scanf("%s%s", a, b), dist[index(a)][index(b)] = 1;
		FW();
		solve();
		for (int i = 0; i < n; ++i)
			comp[parent(i)].push_back(i);
		for (int i = 0; i < n; ++i){
			vector<int> & v = comp[i];
			if (v.empty()) continue;
			printf("%s", M[v[0]].c_str());
			for (int j = 1; j < v.size(); ++j) printf(", %s", M[v[j]].c_str());
			printf("\n");
		}
	}
	return 0;
}