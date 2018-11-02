#include <stdio.h>
#include <algorithm>
#include <math.h>
#define MAX 1005
using namespace std;
int n, r;
int x[MAX];
int y[MAX];
struct edge{
	unsigned int f : 16;
	unsigned int t : 16;
	long double c;
};
inline bool operator <(edge a, edge b){
	return (b.c - a.c > 1e-9);
}
edge edges[MAX*MAX << 1];
int edgeCount;
int p[MAX];
inline int parent(int i){
	return (p[i] == i)?i : (p[i] = parent(p[i]));
}
inline void addEdge(unsigned int a,unsigned int b){
	long double cur = sqrt(abs(y[a]-y[b])*abs(y[a]-y[b]) + abs(x[a]-x[b])*abs(x[a]-x[b]));
	edges[edgeCount++] = {a, b, cur};
}
int main(){
	int TC;
	int a, b;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		scanf("%d%d", &n, &r);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &a, &b);
			x[i] = a; y[i] = b;
		}
		edgeCount = 0;
		for (int i = 0; i < n - 1; ++i)
		for(int j = i+1; j < n; ++j)addEdge(i, j);
		sort(edges, edges + edgeCount);
		for (int i = 0; i < n; ++i) p[i] = i;
		long double road = 0.0;
		long double rail = 0.0;
		int states = 1;
		int count = 0;
		--n;
		double R = double(r);
		for (int i = 0; i < edgeCount; ++i){
			edge temp = edges[i];
			if (parent(temp.f) != parent(temp.t)){
				p[p[temp.f]] = p[temp.t];	// This is the right way of implementing the union!
				
				if (temp.c - R > 1e-9){
					++states;
					rail += temp.c;
				}
				else {
					road += temp.c;
				}
				if (++count == n) break;
			}
		}
		printf("Case #%d: %d %d %d\n", tc, states, int(road + 0.5 + 1e-9), int (rail + 0.5 + 1e-9));
	}
	return 0;
}