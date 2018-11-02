// SORTING CAN SOLVE A LOT OF GEOMETRIC PROBLEMS
#include<stdio.h>
#include<algorithm>
#define MAX 100005
using namespace std;
typedef pair<int, int> ii;
struct point{
	int x, y, h;
	inline int quarter(){
		return (x >= 0) ? y >= 0 ? 1 : 4 : y >= 0 ? 2 : 3;
	}
};
inline const int cross(point & a, point & b){
	return a.x*b.y - a.y*b.x;
}
inline bool operator < (point & a, point & b){
	int A = a.quarter(), B = b.quarter();
	if (A != B) return A < B;
	int temp = cross(a, b);
	if (temp) return temp > 0;	// 'b' is to the left of 'a'
	if (a.x != b.x) return abs(a.x) < abs(b.x);
	return abs(a.y) < abs(b.y);
}
point p[MAX];
ii ans[MAX];
int main(){
	int n;
	int tc = 0;
	while (scanf("%d", &n), n){
		int a, b, c;
		for (int i = 0; i < n; ++i) scanf("%d%d%d", &a, &b, &c), p[i] = point{a, b, c};
		sort(p, p + n);
		point prev = p[0];
		int h = prev.h;
		int top = 0;
		for (int i = 1; i < n; ++i){
			point cur = p[i];
			if (!cross(cur, prev)){	// they are both aligned
				if (cur.h <= h) ans[top++] = ii(cur.x, cur.y);
				else h = cur.h;
			}
			else h = cur.h;
			prev = cur;
		}
		sort(ans, ans + top);
		printf("Data set %d:\n%s\n", ++tc, top ? "Some lights are not visible:" : "All the lights are visible.");
		for (int i = 0; i < top; ++i) printf("x = %d, y = %d%c\n", ans[i].first, ans[i].second, ";."[i == top - 1]);
	}
	return 0;
}