#include<stdio.h>
#include<string.h>
#define MAX 100005
#define left(s) (s << 1)
#define right(s) ((s << 1) + 1)
#define avg(a, b) ((a + b) >> 1)
typedef long long ll;
ll st[MAX << 2];	// store summation of all elements in the interval
ll lazy[MAX << 2];	// lazy[p] stores the value v that should be added to all elements in the range specified by p
void init(void){
	memset(st, 0, sizeof st);
	memset(lazy, 0, sizeof lazy);
}
int i, j, v;	// query details
void propagate(int p, int l, int r){
	ll temp = lazy[p];
	if (!temp) return;
	lazy[p] = 0;
	st[p] += (ll) temp*(r + 1 - l);
	if (l != r)
		// ADD 'temp' TO THE LAZINESS. YOU DON'T SET LAZINESS TO TEMP
		lazy[left(p)] += temp, lazy[right(p)] += temp;
}
void update(int p, int l, int r){
	propagate(p, l, r);
	if (r < i || l > j) return;	// outside my range
	if (l >= i && r <= j){		// inside my range
		st[p] += (ll) v * (r + 1 - l);
		if (l != r)
			lazy[left(p)] += v, lazy[right(p)] += v;
		return;
	}
	update(left(p), l, avg(l, r));
	update(right(p), avg(l, r) + 1, r);
	st[p] = st[left(p)] + st[right(p)];
}
ll rsq(int p, int l, int r){
	if (r < i || l > j) return 0;
	propagate(p, l, r);
	if (l >= i && r <= j) return st[p];
	return rsq(left(p), l, avg(l, r)) + rsq(right(p), avg(l, r) + 1, r);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	int n, c;	// number of elements and number of queries
	scanf("%d", &TC);
	while(TC--){
		init();
		scanf("%d%d", &n, &c);
		int t;
		while(c--){
			// for (int k = 1; k <= n; ++k) i = j = k, printf("%d %d\n", k, rsq(1, 1, n));
			scanf("%d%d%d", &t, &i, &j);
			if (t)
				printf("%lld\n", rsq(1, 1, n));
			else
				scanf("%d", &v), update(1, 1, n);
		}
	}
	return 0;
}
 
