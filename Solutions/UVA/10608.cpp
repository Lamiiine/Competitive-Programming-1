#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#define MAX 30005
using namespace std;
int p[MAX];
int Count[MAX];
int n, m;
inline int parent(const int i){
	return (p[i] == i)?i:p[i] = parent(p[i]);
}
inline void unite(const int x, const int y){
	p[parent(x)] = parent(y);
}
int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) p[i] = i;
		int x, y;
		while(m--) {scanf("%d%d", &x, &y); unite(x, y);}
		memset(Count, 0, sizeof Count);
		for (int i = 1; i <= n; ++i) ++Count[parent(i)];
		int ans = 0;
		for (int i = 1; i <= n; ++i) ans = max(ans, Count[i]);
		printf("%d\n", ans);
	}
	return 0;
}