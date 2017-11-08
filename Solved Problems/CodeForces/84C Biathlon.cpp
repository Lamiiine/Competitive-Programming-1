#include<bits/stdc++.h>
#define MAX 10005
using namespace std;
struct circle {
	int c, r;
	int index;
	int hit;
	circle(int x, int y, int z):c(x), r(y), index(z), hit(-1){}
	circle():c(0), r(0), index(0), hit(-1){}
} cir[MAX];
inline const bool operator <(const circle & a, const circle & b) {
	return a.c < b.c;
}
int n;
int hit[MAX];
inline const int sqr_dist(int x, int y, int a, int b) {
	int dx = a - x;
	int dy = b - y;
	return dx * dx + dy * dy;
}
int counter = 0;
void test(int x, int y, int ind, int i){
	if (ind >= 0 && ind < n)
	if (sqr_dist(x, y, cir[ind].c, 0) <= cir[ind].r && cir[ind].hit == -1)
		++counter, cir[ind].hit = i;
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	memset(hit, 0xFF, sizeof hit);
	scanf("%d", &n);
	for (int i = 0, x, y; i < n; ++i)
		scanf("%d%d", &x, &y), cir[i] = circle(x, y * y, i);
	sort(cir, cir + n);
	int m;
	scanf("%d", &m);
	for (int i = 1, x, y; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		circle tmp { x, 0, 0 };
		int ind = lower_bound(cir, cir + n, tmp) - cir;
		test(x, y, ind, i);
		test(x, y, ind - 1, i);
	}
	printf("%d\n", counter);
	for (int i = 0; i < n; ++i)
		hit[cir[i].index] = cir[i].hit;
	for (int i = 0; i < n; ++i)
		printf("%d ", hit[i]);
	return 0;
}

