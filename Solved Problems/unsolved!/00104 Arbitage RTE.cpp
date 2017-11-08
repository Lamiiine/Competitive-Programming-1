#include<stdio.h>
#include<string.h>
#include<iostream>
#define MAX 25
using namespace std;
long double dist[MAX][MAX];
int n;
int p[MAX][MAX];
int via;
int bell(){
	// You just run this once!
	for (int k = 1; k <= n; ++k)
	for (int i = 1; i <= n; ++i)
	for (int j = 1; j <= n; ++j){
		if (dist[i][k] * dist[k][j] - dist[i][j] > 1e-9){
			dist[i][j] = dist[i][k] * dist[k][j];
			p[i][j] = k;
			if (i == j && dist[i][j] > 1.01 + 1e-9) { via = k; return i; }
		}
	}
	// let Floyd Warshall's finish looping before you end, so you can correctly print the path
	return -1;
}
void path(int i, int j){
	if (p[i][j] == -1){
		printf("%d ", i);
		return;
	}
	path(i, p[i][j]);
	path(p[i][j], j);
}
int main(){
	// freopen("Input.txt", "r", stdin);
	long double x;
	while (scanf("%d", &n) != EOF){
		memset(p, 0xFF, sizeof p);

		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j){
			if (i == j) dist[i][j] = 1.0;
			else {
				cin >> x;
				dist[i][j] = x;
			}
		}
		int y = bell();
		if (y == -1) { printf("no arbitrage sequence exists\n"); }
		else {
			path(y, via);
			path(via, y);
			printf("%d\n", y);
		}
	}
	return 0;
}