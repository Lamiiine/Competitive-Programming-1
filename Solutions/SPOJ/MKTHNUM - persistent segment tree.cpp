#include <bits/stdc++.h>
#define OO 1000000000
#define MAX_N 100003
using namespace std;
struct node
{
	const node * left, * right;
	const int sum;
	node():left(this), right(this), sum(0) {}
	node(const node * _left, const node * _right, const int _sum)
	:left(_left), right(_right), sum(_sum){}
};

const node * empty = new node;

const node * insert(const node * cur, const int v, const int l = -OO, const int r = OO)
{
	if (l > v || r < v) return cur;
	if (l == r)
		return new node(empty, empty, cur->sum + 1);
	const int m = l + (r - l) / 2;
	const node * left = insert(cur->left, v, l, m);
	const node * right = insert(cur->right, v, m + 1, r);
	return new node(left, right, left->sum + right->sum);	// same as 'cur->sum + 1'
}

inline int query(const node * j, const node * im1,
		const int k, const int l = -OO, const int r = OO)
{
	if (l == r) return l;
	const int left_sum = j->left->sum - im1->left->sum;
	if (k <= left_sum)
	{
		return query(j->left, im1->left, k, l, l + (r - l) / 2);
	}
	return query(j->right, im1->right, k - left_sum, l + (r - l) / 2 + 1, r);
}

const node * roots[MAX_N];
int n, m;
int main()
{
	roots[0] = empty;
	scanf("%d%d", &n, &m);
	for (int i = 1, x; i <= n; ++i)
	{
		scanf("%d", &x);
		roots[i] = insert(roots[i - 1], x);
	}
	for (int i, j, k; m--; )
	{
		scanf("%d%d%d", &i, &j, &k);
		printf("%d\n", query(roots[j], roots[i - 1], k));
	}
	return 0;
}
/*
7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
 */

