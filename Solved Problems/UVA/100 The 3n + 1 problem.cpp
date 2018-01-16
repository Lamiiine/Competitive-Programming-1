#include<bits/stdc++.h>
#define MAX (1LL << 20LL)
#define avg(a, b) (( (a) + (b) )>> 1)
#define left(a) ((a) << 1)
#define right(a) (((a) << 1) + 1)
#define size 1000000
using namespace std;
typedef long long int ll;
int memo[MAX];
inline ll next(ll i){
	return (i & 1LL) ? 3LL*i + 1LL : i >> 1LL;
}
inline int dp(ll i){
	// printf("%d\n", i);
	if (i >= MAX) return 1 + dp(next(i));
	int & ret = memo[i];
	if (ret != -1) return ret;
	return ret = 1 + dp(next(i));
}
int st[size << 3];
inline void build(int p, int l, int r){
	if (l == r) st[p] = l;
	else {
		int m = avg(l, r);
		build(left(p), l, m);
		build(right(p), m + 1, r);
		int i = st[left(p)], j = st[right(p)];
		// printf("%d %d %d %d %d\n", p, l, r, i, j);
		st[p] = dp(i) >= dp(j) ? i : j;
	}
}
int i, j;
inline int rmq(int p, int l, int r){
	// printf("%d %d %d\n", p, l, r);
	if (l >= i && r <= j) return st[p];
	if (l > j || r < i) return -1;
	int x = rmq(left(p), l, avg(l, r));
	int y = rmq(right(p), avg(l, r) + 1, r);
	if (x == -1) return y;
	if (y == -1) return x;
	return dp(x) >= dp(y) ? x : y;
}
int main(void){
	memset(memo, 0xFF, sizeof memo); memo[1] = 1;
	int i, j;
	for (build(1, 1, size); ~scanf("%d%d", &i, &j);printf("%d %d %d\n", i, j, dp(rmq(1, 1, size))))
		::i = min(i, j), ::j = max(i, j);
}

