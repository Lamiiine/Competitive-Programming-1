#include <iostream>
#include <algorithm>
#define MAX 200000
using namespace std;
int n, m;
struct edge{
	int f;
	int t;
	int c;
};
inline bool operator <(edge a, edge b){
	return (a.c < b.c);
}
edge edges[MAX];
int p[MAX];
inline int parent(int i){
	return (p[i] == i) ? i : (p[i] = parent(p[i]));
}
int main(){
	freopen("Input.txt", "r", stdin);
	while (scanf("%d%d", &m, &n), n || m){
		// 0-based indexing
		int x, y, z;
		int total = 0;
		for (int i = 0; i < n; ++i){
			scanf("%d%d%d", &x, &y, &z);
			edges[i] = { x, y, z };
			total += z;
		}
		sort(edges, edges + n);
		for (int i = 0; i < m; ++i) p[i] = i;
		int s = m--;
		int ans = 0;
		for (int i = 0; m; ++i){
			edge temp = edges[i];
			if (parent(temp.f) != parent(temp.t)){
				ans += temp.c;
				m--;
				p[p[temp.f]] = p[temp.t];
			}
		}
		printf("%d\n", total - ans);
	}
	return 0;
}