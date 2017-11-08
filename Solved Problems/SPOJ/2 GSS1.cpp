#include<stdio.h>
#include<algorithm>
#include<limits.h>
#define MAX 50005
#define left(s) (s << 1)
#define right(s) ((s << 1) + 1)
#define avg(a, b) ((a + b) >> 1)
using namespace std;
struct node{
	int sum;		// sum
	int r_sum;		// max right sum
	int l_sum;		// max left sum
	int m_sum;		// max range sum
	node():sum(0),r_sum(0), l_sum(0), m_sum(0){}
	node(int a, int b, int c, int d):sum(a),r_sum(b), l_sum(c), m_sum(d){}
} st[MAX << 2];
node dummy(INT_MAX, INT_MAX, INT_MAX, INT_MAX);
inline const bool operator == (const node & a, const node & b){
	return a.sum == b.sum && a.r_sum == b.r_sum && a.l_sum == b.l_sum && a.m_sum == b.m_sum;
}
int n;
int a[MAX];
node merge(node a, node b){
	node temp;
	temp.sum = a.sum + b.sum;
	temp.l_sum = max(a.l_sum, a.sum + b.l_sum);
	temp.r_sum = max(b.r_sum, b.sum + a.r_sum);
	temp.m_sum = max(a.r_sum + b.l_sum, max(a.m_sum, b.m_sum));
	return temp;
}
void build(int p, int l, int r){
	if (l == r){
		node temp;
		temp.l_sum = temp.r_sum = temp.m_sum = temp.sum = a[l];
		st[p] = temp;
		return;
	}
	build(left(p), l, avg(l, r));
	build(right(p), avg(l, r) + 1, r);
	st[p] = merge(st[left(p)], st[right(p)]);
}
int i, j;
node query(int p, int l, int r){
	if (r < i || l > j) return dummy;
	if (l >= i && r <= j) return st[p];
	node p1 = query(left(p), l, avg(l, r));
	node p2 = query(right(p), avg(l, r) + 1, r);
	if (p1 == dummy) return p2;
	if (p2 == dummy) return p1;
	return merge(p1, p2);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	build(1, 0, n-1);
	int q;	// number of queries
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &i, &j); --i; --j;
		printf("%d\n", query(1, 0, n-1).m_sum);
	}
	return 0;
}

