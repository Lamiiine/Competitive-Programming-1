#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<map>
#include<string>
#define MAX 205
#define MAXX 19905
using namespace std;
int from[MAXX];
int to[MAXX];
int cost[MAXX];
int en;
int n, r;
int source, target;
void addEdge(const int x, const int y, const int z){
	from[en] = x;
	to[en] = y;
	cost[en++] = z;
}
int p[MAX];
int parent(int i){
	return (p[i] == i) ? i : p[i] = parent(p[i]);
}
void unite(int i, int j){
	p[parent(i)] = parent(j);
}
bool can(int x){
	// 0-BASED INDEXING!!!!!!!!!
	for (int i = 0; i < n; ++i)
		p[i] = i;
	for (int i = 0; i < en; ++i)
	if (cost[i] >= x)
		unite(from[i], to[i]);
	return (parent(target) == parent(source));
}
int main(){
	int TC = 0;
	while (scanf("%d%d", &n, &r), n || r){
		en = 0;
		int counter = 0;
		map<string, int> m;
		char f[35], t[35];
		int c;
		while (r--){
			scanf("%s%s%d", f, t, &c);
			if (m.find(f) == m.end()) m[f] = counter++;
			if (m.find(t) == m.end()) m[t] = counter++;
			addEdge(m[f], m[t], c);
		}
		scanf("%s%s", f, t);
		source = m[f];
		target = m[t];
		// THIS IS HOW YOU BINARY SEARCH AN INTEGER ANSWER
		int low = 0, high = 10000;
		while (low != high){
			int mid = max((low + high) >> 1, low+1);
			if (can(mid))
				low = mid;
			else high = mid - 1;
		}
		printf("Scenario #%d\n%d tons\n\n", ++TC, (can(low))?low:0);
	}
	return 0;
}