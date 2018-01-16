// The only operation is flip
#include<stdio.h>
#include<algorithm>
#define left(s) (s << 1)
#define right(s) ((s << 1) + 1)
#define avg(a, b) ((a + b) >> 1)
#define MAX 100005
using namespace std;
int st[MAX << 2] = {0};
bool lazy[MAX << 2] = {0};
int n, m;
void propagate(int p, int l, int r){
	// needs no updating
	if (!lazy[p]) return;
	lazy[p] = false;
	st[p] = r + 1 - l - st[p];	// flip all
	// if you have children, flip their state
	if (l != r)
		lazy[left(p)]^=1, lazy[right(p)]^= 1;
}
int i, j;
int rsq(int p, int l, int r){
	if (r < i || l > j) return -1;
	propagate(p, l, r);
	if (l >= i && r <= j) return st[p];
	int p1 = rsq(left(p), l, avg(l, r));
	int p2 = rsq(right(p), avg(l, r) + 1, r);
	return max(p1, 0) + max(p2, 0);
}
void update(int p, int l, int r){
	propagate(p, l, r);
	if (r < i || l > j) return;
	// if you have no children
	if (l == r)
	{
		st[p] ^= 1; return;
	}
	// if it's inside your range
	if (l >= i && r <= j){
		st[p] = r + 1 - l - st[p];
		lazy[left(p)]^=1, lazy[right(p)]^= 1;
		return;
	}
	update(left(p), l, avg(l, r));
	update(right(p), avg(l, r) + 1, r);
	st[p] = st[left(p)] + st[right(p)];
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	while(m--){
		int type;
		scanf("%d%d%d", &type, &i, &j); --i; --j;
		if (type) printf("%d\n", rsq(1, 0, n-1));
		else update(1, 0, n-1);
	}
	return 0;
}

