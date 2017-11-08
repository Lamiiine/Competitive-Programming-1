#include<stdio.h>
#define MAX 100005
#define left(s) (s << 1)
#define right(s) ((s << 1) + 1)
#define avg(a, b) ((a + b) >> 1)
int st0[MAX << 2];
int st1[MAX << 2] = {0};
int st2[MAX << 2] = {0};
char lazy[MAX << 2] = {0};	// lazy[i] = how much do you need to add to item #i
void build(int p, int l, int r){
	// build st0
	// this is the only one that needs to be built
	if (l == r){
		st0[p] = 1;
		return;
	}
	build(left(p), l, avg(l, r));
	build(right(p), avg(l, r) + 1, r);
	st0[p] = st0[left(p)] + st0[right(p)];
}
int i, j;
void propagate(int p, int l, int r){
	char temp = lazy[p] % 3;
	if (!temp) return;
	lazy[p] = 0;
	int num0 = st0[p], num1 = st1[p], num2 = st2[p];
	if (temp % 3 == 1){
		st1[p] = num0;
		st2[p] = num1;
		st0[p] = num2;
	}
	else {	// we need to add 2
		st0[p] = num1;
		st1[p] = num2;
		st2[p] = num0;
	}
	if (l != r){
		lazy[left(p)] = (lazy[left(p)] + temp) % 3;
		lazy[right(p)] = (lazy[right(p)] + temp) % 3;
	}
}
int rsq(int p, int l, int r){
	if (r < i || l > j) return 0;
	propagate(p, l, r);
	if (l >= i && r <= j) return st0[p];
	return rsq(left(p), l, avg(l, r)) + rsq(right(p), avg(l, r) + 1, r);
}
void update(int p, int l, int r){
	propagate(p, l, r);
	if (r < i || l > j)	// outside my array
		return;
	if (l >= i && r <= j){	// all inside my array
		int num0 = st0[p], num1 = st1[p], num2 = st2[p];
		st1[p] = num0;
		st2[p] = num1;
		st0[p] = num2;
		if (l != r)
			lazy[left(p)] = (lazy[left(p)] + 1) % 3,
			lazy[right(p)] = (lazy[right(p)] + 1) % 3;
		return;
	}
	update(left(p), l, avg(l, r));
	update(right(p), avg(l, r) + 1, r);
	st0[p] = st0[left(p)] + st0[right(p)];
	st1[p] = st1[left(p)] + st1[right(p)];
	st2[p] = st2[left(p)] + st2[right(p)];
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int n, q;
	scanf("%d%d", &n, &q);
	build(1, 0, n-1);
	int t;
	while(q--){
		scanf("%d%d%d", &t, &i, &j);
		if (t) printf("%d\n", rsq(1, 0, n-1));
		else update(1, 0, n-1);
	}
	return 0;
}

