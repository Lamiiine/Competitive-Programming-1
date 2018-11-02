#include<stdio.h>
#include <math.h>
#include <algorithm>
#define MAX 505
using namespace std;
int S, P;
int p[MAX];
inline int parent(int i){
	return (p[i] == i)?i:(p[i] = parent(p[i]));
}
struct edge{
	int f;
	int t;
	long double c;
};
bool operator <(edge a, edge b){
	return (b.c - a.c > 1e-9);
}
int x[MAX];
int y[MAX];
int edgeCount;
edge edges[(MAX*MAX) << 1];
inline void addEdge(int i, int j){
	long double cur = sqrt(abs(x[i]-x[j])*abs(x[i]-x[j]) + abs(y[i]-y[j])*abs(y[i]-y[j]));
	::edges[edgeCount++] = {i, j, cur};
}
int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d", &S, &P);
		for (int i = 0; i < P; ++i) p[i] = i;
		int a, b;
		for (int i = 0; i < P; ++i){
			scanf("%d%d", &a, &b);
			x[i] = a;
			y[i] = b;
		}
		edgeCount = 0;
		for (int i = 0; i < P - 1; ++i)
		for (int j = i + 1; j < P; ++j) addEdge(i, j);
		sort(::edges,::edges + edgeCount);
		P -= S;
		long double D = 0.0;
		for (int i = 0; P > 0; ++i){
			edge temp = ::edges[i];
			if (parent(temp.f) == parent(temp.t)) continue;
			p[p[temp.f]] = p[temp.t];
			--P;
			D = max(D, temp.c);
		}
		printf("%1.2llf\n", D);
	}
	return 0;
}