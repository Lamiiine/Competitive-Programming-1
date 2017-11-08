#include<stdio.h>
#include<algorithm>
#define MAX 25005
using namespace std;
int n, m;
int p[1005];
struct edge{
	int c;
	int f;
	int t;
};
inline bool operator <(edge a, edge b){
	return a.c < b.c;
}
inline int parent(int i){
	return (p[i] == i)?i:p[i] = parent(p[i]);
}
inline void unite(int x, int y){
	p[parent(x)] = parent(y);
}
edge e[MAX];
int main(){
	while(scanf("%d%d", &n, &m), n || m){
		for (int i = 0; i < n; ++i) p[i] = i;
		int x, y, z;
		for (int i = 0; i < m; ++i)
			scanf("%d%d%d", &e[i].f, &e[i].t, &e[i].c);
		sort(e, e + m);
		bool first = true;
		for (int i = 0; i < m; ++i){
			if (parent(x = e[i].f) == parent(y = e[i].t)) {
				if (!first) printf(" ");
				printf("%d", e[i].c);
				first = false;
			}
			else p[p[x]] = p[y];
		}
		if (first) printf("forest");
		printf("\n");
	}
	return 0;
}