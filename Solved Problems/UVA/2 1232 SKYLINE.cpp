#include<stdio.h>
#include<assert.h>
#include<algorithm>
#include<string.h>
#define MAX 100005
#define left(s) (s << 1)
#define right(s) ((s << 1) + 1)
#define avg(a, b) ((a + b) >> 1)
using namespace std;
// MAKE YOUR CODE AS EFFICIENT AS POSSIBLE
// INITIALLY, YOU WANTED TO STORE MAXIMUM AND MINIMUM VALUE ON EACH INTERVAL
// THEN YOU CHANGED YOUR MIND AND STORED ONLY THE MAXIMUM VALUE, SO IT GAVE YOU A 'TLE'
// WHEN YOU STARTED USING MINIMUM VALUES AS WELL, IT GAVE YOU AN 'AC'
struct node{
	int mx, mn, lz;
}a[MAX << 2];
int i, j, v;
int ans;
int max_p = 0;
void propagate(int p, int l, int r) {
	int w = a[p].lz;
	if (!w) return;
	a[p] = node{w, w, 0};
	if (l != r)
		a[left(p)].lz = a[right(p)].lz = w;
}
void update(int p, int l, int r) {
	propagate(p, l, r);
	if (r < i || j < l) return;
	if (l == r) {
		max_p = max(max_p, p);
		if (v >= a[p].mx)
			// MY ONLY BUG IN THIS CODE WAS SETTING 'mx[p] = w' INSTEAD OF 'mx[p] = v'
			++ans, a[p].mx = v;
		return;
	}
	max_p = max(max_p, right(p));
	if (l >= i && r <= j) {
		node &temp = a[p];
		if (v < temp.mn) return;
		if (v >= temp.mx){
			ans += (r - l + 1);
			temp = node{v, v, 0};
			a[left(p)].lz = a[right(p)].lz = v;
			return;
		}
	}
	int lf = left(p), rt = right(p), av = avg(l, r);
	update(lf, l, av);
	update(rt, av + 1, r);
	a[p] = node{max(a[lf].mx, a[rt].mx), min(a[lf].mn, a[rt].mn), 0};
}
void init(void) {
	ans = 0;
	memset(a, 0, (max_p + 3)*sizeof (a[0]));
	max_p = 0;
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		init();
		int q;
		scanf("%d", &q);
		while (q--) {
			scanf("%d%d%d", &i, &j, &v), --i, j -= 2;
			update(1, 0, 99999);
		}
		printf("%d\n", ans);
	}
	return 0;
}

