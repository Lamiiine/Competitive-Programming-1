#define MAX 105
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
using namespace std;
vector<int>adj[MAX];
int p[MAX];
int n;
inline int parent(const int i){
	return p[i] == i ? i : p[i] = parent(p[i]);
}
inline void unite(const int i, const int j){
	if (i > 0 && i <= n && j > 0 && j <= n)
	p[parent(i)] = parent(j);
}
inline bool same(const int i, const int j){
	return parent(i) == parent(j);
}
int main(){
	// freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)p[i] = i;
	int arr[MAX];
	for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
	int x;
	for (int i = 1; i <= n; ++i){
		scanf("%d", &x);
		unite(i, i - x);
		unite(i, i + x);
	}
	for (int i = 1; i <= n; ++i) if (!same(i, arr[i])){
		printf("NO");
		return 0;
	}
	printf("YES");
	return 0;
}