#include<stdio.h>
#include<string.h>
#define MAX 10000005
#define P_MAX 40005
#define left(s) (s << 1)
#define right(s) ((s << 1) + 1)
#define avg(a, b) ((a + b) >> 1)
using namespace std;
typedef unsigned short us;
us st[MAX << 2];
us lazy[MAX << 2];
bool seen[P_MAX];
void init(void){
	memset(st, 0, sizeof st);
	memset(lazy, 0, sizeof st);
	memset(seen, 0, sizeof seen);
}
int i, j, v;
void propagate(int p, int l, int r){
	us temp = lazy[p];
	if (!temp) return;
	st[p] = temp;
	lazy[p] = 0;
	if (l != r) lazy[left(p)] = lazy[right(p)] = temp;
}
void update(int p, int l, int r){
	propagate(p, l, r);
	if (r < i || l > j) return;
	if (l >= i && r <= j){
		st[p] = v;
		if (l != r)
			lazy[left(p)] = lazy[right(p)] = v;
		return;
	}
	update(left(p), l, avg(l, r));
	update(right(p), avg(l, r) + 1, r);
}
void query(int p, int l, int r){
	propagate(p, l, r);
	if (l == r) seen[st[p]] = true;
	else query(left(p), l, avg(l, r)), query(right(p), avg(l, r) + 1, r);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	int n;
	while(TC--){
		init();
		int n;
		scanf("%d", &n);
		for (v = 1; v <= n; ++v)
			scanf("%d%d", &i, &j), update(1, 1, 10000000);
		query(1, 1, 10000000);
		int ans = 0;
		for (int i = 1; i <= n; ++i) ans += seen[i];
		printf("%d\n", ans);
	}
}

