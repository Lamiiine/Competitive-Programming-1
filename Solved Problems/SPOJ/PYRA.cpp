#include<stdio.h>
#include<string.h>
#define MAX 10005
using namespace std;
int n;
int en;
int child[MAX];
int head[MAX];
int to[MAX << 1];
int nxt[MAX << 1];
int p[MAX];
inline void addEdge(const int x, const int y){
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
inline int width(int i){	// node number
	if (!child[i]) return 1;
	int ans = child[i] + 1;
	for (int j = head[i]; j != -1; j = nxt[j]){
		int x = to[j];
		if (x != p[i]) { p[x] = i;  ans += width(x); }
	}
	return ans;
}
int q[MAX];
inline int size(int i){
	if (!child[i]) return 1;
	int ans = width(i);
	for (int j = head[i]; j != -1; j = nxt[j]){
		int x = to[j];
		if (x != q[i]){ q[x] = i; ans += size(x); }
	}
	return ans;
}
inline void init(){
	memset(child, 0xFF, sizeof child);	// this is not deg, 
	child[0] = 0;
	p[0] = -1;
	q[0] = -1;
	memset(head, 0xFF, sizeof head);
	en = 0;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &n);
		init();
		int x, y;
		for (int i = 0; i < n - 1; ++i){
			scanf("%d%d", &x, &y);
			addEdge(x, y);
			addEdge(y, x);
			++child[x];
			++child[y];
		}
		printf("%d\n", size(0));
	}
	return 0;
}