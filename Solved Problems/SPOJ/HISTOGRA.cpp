#include<stdio.h>
#include<algorithm>
#define left(s) (s << 1)
#define right(s) ((s << 1) + 1)
#define avg(a, b) ((a + b) >> 1)
#define MAX 100005
using namespace std;
typedef long long int ll;
int n;
int a[MAX];
int st[MAX << 2];	// st[i] stores index of smallest element in range represented by i
void build(int p, int l, int r){
	if (l == r){
		st[p] = l;
		return;
	}
	build(left(p), l, avg(l, r));
	build(right(p), avg(l, r) + 1, r);
	int p1 = st[left(p)], p2 = st[right(p)];
	st[p] = a[p1] < a[p2] ? p1 : p2;
}
int i, j;
int rmq(int p, int l, int r){
	if (r < i || l > j) return -1;
	if (l >= i && r <= j) return st[p];
	int p1 = rmq(left(p), l, avg(l, r));
	int p2 = rmq(right(p), avg(l, r) + 1, r);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	return a[p1] < a[p2] ? p1 : p2;
}
// smallest element in range [l, r]
int rmq(int l, int r){
	i = l, j = r;
	return rmq(1, 0, n-1);
}
// largest histogram in range [l, r]
ll recurse(int l, int r){
	if (l == r) return a[l];
	if (l > r) return 0LL;
	int i = rmq(l, r);	// get index of smallest element
	return max((ll) a[i]*(r + 1 - l), max(recurse(l, i - 1), recurse(i + 1, r)));
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d", &n), n){
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		build(1, 0, n-1);
		printf("%lld\n", recurse(0, n-1));
	}
	return 0;
}

