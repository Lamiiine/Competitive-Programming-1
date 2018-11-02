#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#define M 100
using namespace std;

int n;
int adj[M][M];
int deg[M];
vector<int> ss;

vector<int> recurse(int i, vector<int> s){
	if (i == n) return s;
	for (int j = 0; j < s.size(); j++) if (binary_search(adj[i], adj[i]+deg[i], s[j])) return recurse(i + 1, s);
	vector<int> s1 = recurse(i + 1, s);
	s.push_back(i);
	vector<int> s2 = recurse(i + 1, s);
	if (s1.size() > s2.size()) return s1;
	else return s2;
}
int main(){
	int k, TC, x, y;
	scanf("%d", &TC);
	while (TC--){
		scanf("%d%d", &n, &k);
		memset(deg, 0, n * sizeof(int));
		for (int i = 0; i < k; i++){
			scanf("%d%d", &x, &y);
			x--; y--;
			adj[x][deg[x]++] = y;
			adj[y][deg[y]++] = x;
		}
		for (int i = 0; i < n; i++) sort(adj[i], adj[i] + deg[i]);
		ss = recurse(0, ss);
		printf("%d\n", ss.size());
		for (int i = 0; i < ss.size()-1; i++)
			printf("%d ", ss[i]+1);
		printf("%d\n", ss[ss.size()-1] + 1);
		ss.clear();
	}
	return 0;
}
