#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 100005
#define left(s) (s << 1)
#define right(s) ((s << 1) + 1)
#define avg(a, b) ((a + b) >> 1)
using namespace std;
inline int ind(int i) {
	return MAX + i;
}
int st[MAX << 2];	// my segment tree
int a[MAX];			// my array
int n, q;
// st[i] stores index of most frequent value in range represented by i
void build(int p, int l, int r) {
	if (l == r) {
		st[p] = 1;	// highest frequency in the given range
		return;
	}
	build(left(p), l, avg(l, r));
	build(right(p), avg(l, r) + 1, r);
	int p1 = max(st[left(p)], st[right(p)]);	// highest frequencies in right and left subtree
	int a1 = a[avg(l, r)], a2 = a[avg(l, r) + 1];
	if (a1 != a2){
		st[p] = p1;	// maximum frequency in the given range
		return;
	}
	int p2 = upper_bound(a + l, a + r + 1, a1) - lower_bound(a + l, a + r + 1, a1);
	st[p] = max(p1, p2);
}
int i, j;	// my boundaries
int rmq(int p, int l, int r) {
	if (i > r ||  j < l) return -1;
	if (l >= i && r <= j) return st[p];
	int p1 = rmq(left(p), l, avg(l, r));
	int p2 = rmq(right(p), avg(l, r) + 1, r);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	int a1 = a[avg(l, r)], a2 = a[avg(l, r) + 1];
	if (a1 != a2) return max(p1, p2);
	int p3 = upper_bound(a + max(i, l), a + min(j, r) + 1, a1) - lower_bound(a + max(i, l), a + min(j, r) + 1, a1);
	return max(p1, max(p2, p3));
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	while (scanf("%d", &n), n) {
		scanf("%d", &q);
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);	// read element number i
		build(1, 0, n - 1);	// build tree rooted at 1, representing elements 0 to n-1
		while(q--){
			scanf("%d%d", &i, &j);
			--i; --j;
			printf("%d\n", rmq(1, 0, n-1));
		}
	}
	return 0;
}

