#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#define MAX 105
using namespace std;
struct edge{
	int f, t, c;	// from, to, cost
} e[MAX*MAX];
inline bool operator < (const edge & a, const edge & b){
	return a.c < b.c;
}
int n, m;
int p[MAX];
inline int parent(int i){
	return p[i] == i ? i : p[i] = parent(p[i]);
}
inline void unite(int i, int j){
	p[parent(j)] = parent(i);
}
inline bool same(int i, int j){
	return parent(i) == parent(j);
}
void init(){
	for (int i = 1; i <= n; ++i)
		p[i] = i;
}
bool taken[MAX*MAX];
int kruskal(){
	init();
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		edge temp = e[i];
		if (!same(temp.f, temp.t))
			unite(temp.f, temp.t), ans += temp.c, taken[i] = true;
	}
	return ans;
}
int kruskal(int flag){
	init();
	int ans = 0;
	int start = 0, end = flag;
	int counter = 0;
	for (int iteration = 0; iteration < 2; ++iteration){
		for (int i = start; i < end; ++i){
			edge temp = e[i];
			if (!same(temp.f, temp.t))
				unite(temp.f, temp.t), ans += temp.c, ++counter;
		}
		start = flag + 1, end = m;
	}
	return (counter == n - 1) ? ans : INT_MAX;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while(TC--){
		memset(taken, 0, sizeof taken);
		scanf("%d%d", &n, &m);
		edge temp;
		for (int i = 0; i < m; ++i)
			scanf("%d%d%d", &temp.f, &temp.t, &temp.c), e[i] = temp;
		sort(e, e + m);
		printf("%d ", kruskal());
		int ans = INT_MAX;
		for (int i = 0; i < m; ++i)
			if (taken[i])
			ans = min(ans, kruskal(i));
		printf("%d\n", ans);
	}
	return 0;
}

