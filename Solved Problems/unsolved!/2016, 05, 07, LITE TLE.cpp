// Range-Minimum-Query Segment Trees
#include <math.h>
#include <stdio.h>
#include <vector>
#include<string.h>
#define MAX 100005
using namespace std;
bool a[MAX];		// array
int st[MAX << 2];	// segment tree
int n;				// size
int left(int p){ return p << 1; };
int right(int p){ return (p << 1) + 1; }
int avg(int i, int j){ return (i + j) >> 1; }
// functions are not smart enought to figure out the range (L-R) fromt he root (p)
int build(int p, int L, int R){
	if (L == R) return st[p] = a[L];
	return st[p] = build(left(p), L, avg(L, R)) + build(right(p), avg(L, R) + 1, R);
}
int u, v;
int rmq(int p, int L, int R) {
	// Base case:
	if (u > R || v < L) return -1;		// entire segment outside range
	if (L >= u && R <= v) return st[p];	// entire segment inside range
	// Recurse:
	int mid = avg(L, R);
	int x = rmq(left(p), L, mid);
	int y = rmq(right(p), mid + 1, R);
	if (x == -1) return y;
	if (y == -1) return x;
	return x + y;
}
// range to be updated is u-v
int update(int p, int L, int R) {
	// Base:
	if (u > R || v < L) return st[p];				// entire segment outside range
	if (L >= u && R <= v) return build(p, L, R);	// entire segment inside range
	// Recurse:
	return st[p] = update(left(p), L, avg(L, R)) + update(right(p), avg(L, R) + 1, R);
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	int x, y, z;
	while (m--){
		scanf("%d%d%d", &x, &y, &z);
		::u = y - 1, ::v = z - 1;
		if (x) printf("%d\n", rmq(1, 0, n - 1));
		else {
			for (int i = u; i <= v; ++i) a[i] ^= true;
			update(1, 0, n - 1);
		}
	}
	return 0;
}