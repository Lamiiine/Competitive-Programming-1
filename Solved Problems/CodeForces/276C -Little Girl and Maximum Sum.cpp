/* You need to remember the following when dealing with Fenwick trees:
 * - It uses 1-based indexing
 * - It's optimized for range updates
 * - It's intended for dynamic accumulation arrays of frequencies
 * - It doesn't answer reqular range sum queries (maybe it does, but I don't know how)
 * */
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#define MAX 200005
using namespace std;
int n, q;
int ft[MAX];
inline int LSOne(int s){
	return s & (-s);
}
inline void init(void) {
	memset(ft, 0, sizeof ft);
}
inline int rsq(int b) {	// return rsq(1, b);
	// return summation of all values added to element # b
	int sum = 0;
	for (; b; b -= LSOne(b))
		sum += ft[b];
	return sum;
}
inline int rsq(int a, int b) {
	return rsq(b) - rsq(a - 1);
}
inline void update(int k, int v) {
	for (; k <= n; k += LSOne(k))
		ft[k] += v;
}
inline void update(int a, int b, int v){
	// add v to every element in the interval [a, b]
	// what it actually does is add v to element # a, and -v to element # b
	// when you query element i, the value returned will be rsq(1, i)
	// Thus, if i belongs to [a, b], then you have indirectly added
	// v to element # i, by adding v to element # a
	update(a, v);
	update(b + 1, -v);
}
int a[MAX];
int b[MAX];
int main(void){
	init();
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0, l, r; i < q; ++i)
		scanf("%d%d", &l, &r), update(l, r, 1);
	for (int i = 1; i <= n; ++i)
		b[i] = rsq(i);
	sort(a, a + n);
	sort(b + 1, b + n + 1);
	long long sum = 0;
	for (int i = 0; i < n; ++i)
		sum += (long long) a[i]*b[i + 1];
	cout << sum;
	return 0;
}

