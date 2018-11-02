#include<stdio.h>
#include<algorithm>
#include<limits.h>
#define MAX 50005
#define left(s) (s << 1)
#define right(s) ((s << 1) + 1)
#define avg(a, b) ((a + b) >> 1)
using namespace std;
int a[MAX];
int n;
struct node{
	int sum;
	int right_sum;
	int left_sum;
	int mrsq;
	node(int a, int b, int c, int d):sum(a), right_sum(b), left_sum(c), mrsq(d){}
	node():sum(0), right_sum(0), left_sum(0), mrsq(0){}
}st[MAX << 2];
const node dummy(INT_MAX, INT_MAX, INT_MAX, INT_MAX);
const inline bool operator == (const node & a, const node & b){
	return a.sum == b.sum && a.right_sum == b.right_sum && a.left_sum == b.left_sum && a.mrsq == b.mrsq;
}
node merge(const node & a, const node & b){
	node temp;
	temp.sum = a.sum + b.sum;
	temp.left_sum = max(a.left_sum, a.sum + b.left_sum);
	temp.right_sum = max(b.right_sum, b.sum + a.right_sum);
	temp.mrsq = max(a.right_sum + b.left_sum, max(a.mrsq, b.mrsq));
	return temp;
}
void build(int p, int l, int r){
	if (l == r){
		int x = a[l];
		st[p] = node(x, x, x, x);
		return;
	}
	build(left(p), l, avg(l, r));
	build(right(p), avg(l, r) + 1, r);
	st[p] = merge(st[left(p)], st[right(p)]);
}
int i, j;
void update(int p, int l, int r){
	if (r < i || l > i) return;
	if (l == i && r == i){
		st[p] = node(j, j, j, j);
		return;
	}
	update(left(p), l, avg(l, r));
	update(right(p), avg(l, r) + 1, r);
	st[p] = merge(st[left(p)], st[right(p)]);
}
node query(int p, int l, int r){
	if (r < i || l > j) return dummy;
	if (l >= i && r <= j) return st[p];
	node a = query(left(p), l, avg(l, r));
	node b = query(right(p), avg(l, r) + 1, r);
	if (a == dummy) return b;
	if (b == dummy) return a;
	return merge(a, b);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	build(1, 0, n-1);
	int t, q;
	scanf("%d", &q);
	while(q--){
		scanf("%d%d%d", &t, &i, &j);
		if (t)--i, --j, printf("%d\n", query(1, 0, n-1).mrsq);
		else --i, update(1, 0, n-1);
	}
	return 0;
}

