#include <stdio.h>
#include<string.h>
#include<algorithm>
#define MAX 505
#define MAXX 10005
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int p[MAX];
int n, m, q;
ii e[MAXX];
ii s[MAX << 1];
int ind[MAX << 1];
bool taken[MAXX];
inline void init(){
	for (int i = 1; i <= n; ++i)
	p[i] = i;
}
inline int parent(int i){
	return(p[i] == i)?i:(p[i] = parent(p[i]));
}
inline void unite(int i, int j){
	p[parent(i)] = parent(j);
}
inline bool same(int i, int j){
	return (parent(i) == parent(j));
}
int main() {
	scanf("%d%d", &n, &m);
	int x, y;
	for (int i = 0; i < m; ++i){
		scanf("%d%d", &x, &y);
		e[i] = ii(x, y);
	}
	init();
	memset(taken, 0, sizeof taken);
	for (int i = 0; i < m; ++i){
		if (!same(e[i].first, e[i].second)) {
			taken[i] = true;
			unite(e[i].first, e[i].second);
		}
	}
	init();
	for (int i = m - 1; i >= 0; --i){
		if (!same(e[i].first, e[i].second)) {
			taken[i] = true;
			unite(e[i].first, e[i].second);
		}
	}
	int counter = 0;
	for (int i = 0; i < m; ++i)
	if (taken[i]){
		ind[counter] = i;
		s[counter++] = e[i];
	}
	scanf("%d", &q);
	bool need[MAX];
	while(q--){
		memset(need, 0, sizeof need);
		init();
		scanf("%d%d", &x, &y);
		--x; --y;
		// YOU USED ARRAY 'e' INSTEAD OF ARRAY 'S'
		for (int i = 0; ind[i] < x; ++i) unite(s[i].first, s[i].second);
		// YOU USED M INSTEAD OF COUNTER
		for (int i = counter-1; ind[i] > y; --i) unite(s[i].first, s[i].second);
		for (int i = 1; i <= n; ++i) need[parent(i)] = true;
		int ans = 0;
		for (int i = 1; i <= n; ++i) if(need[i])++ans;
		printf("%d\n", ans);
	}
	return 0;
}
