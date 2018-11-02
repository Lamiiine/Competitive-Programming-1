#include<stdio.h>
using namespace std;
struct dice{
	char t, b, f, k, l, r;	// top, bottom, front, back, left, right
};
inline dice rotate(const dice & a, int j){
	dice b;
	b.t = a.t, b.b = a.b;
	char x[4] = {a.f, a.l, a.k, a.r};
	char y[4];
	for (int i = 0; i < 4; ++i)
		y[i] = x[(i + j) & 3];
	b.f = y[0], b.l= y[1], b.k= y[2], b.r= y[3];
	return b;
}
inline bool operator == (const dice & a, const dice & b){
	return a.t == b.t && a.b == b.b && a.f == b.f && a.k == b.k && a.r == b.r && a.l == b.l;
}
inline dice parse(int x){
	dice a;
	a.r = x % 10;
	x /= 10;
	a.k = x % 10;
	x /= 10;
	a.l = x % 10;
	x /= 10;
	a.f = x % 10;
	x /= 10;
	a.b = x % 10;
	x /= 10;
	a.t = x % 10;
	return a;
}
inline bool eq_rot(const dice & a, const dice & b){
	for (int i = 0; i < 4; ++i)
		if (a == rotate(b, i)) return true;
	return false;
}
inline bool eq(const dice & a, const dice & b){
	// top gets top
	dice c = b;
	if (eq_rot(c, a))return true;
	// top gets bottom
	c = b;
	c.t = b.b;
	c.b = b.t;
	c.l = b.r;
	c.r = b.l;
	if (eq_rot(c, a)) return true;
	// top bets back
	c = b;
	c.t = b.k;
	c.k = b.b;
	c.b = b.f;
	c.f = b.t;
	if (eq_rot(c, a)) return true;
	// top gets front
	c = b;
	c.t = b.f;
	c.k = b.t;
	c.b = b.k;
	c.f = b.b;
	if (eq_rot(c, a)) return true;
	// top gets right
	c = b;
	c.t = b.r;
	c.r = b.b;
	c.b = b.l;
	c.l = b.t;
	if (eq_rot(c, a)) return true;
	// top gets left
	c = b;
	c.t = b.l;
	c.l = b.b;
	c.b = b.r;
	c.r = b.t;
	if (eq_rot(c, a)) return true;
	return false;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while(TC--){
		int x, y;
		scanf("%d%d", &x, &y);
		dice a = parse(x), b = parse(y);
		printf("%s\n", eq(a, b)?"Equal":"Not Equal");
	}
	return 0;
}

