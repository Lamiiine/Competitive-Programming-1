#include<stdio.h>
#include<limits.h>
#include<iostream>
#include<algorithm>
#define MAX 105
using namespace std;
typedef long long ll;
char s[MAX];
struct burger {
	int b, s, c;
	burger(int i, int j, int k) :
			b(i), s(j), c(k) {
	}
	burger() {
		b = s = c = 0;
	}
};
inline bool operator > (const burger & x, const burger & y) {
	return x.b > y.b && x.s > y.s && x.c > y.c;
}
inline bool operator ==(const burger & x, const burger & y) {
	return x.b == y.b && x.s == y.s && x.c == y.c;
}
inline bool operator !=(const burger & x, const burger & y) {
	return !(x == y);
}
inline int operator /(const burger & x, const burger & y) {
	int b = (y.b) ? x.b / y.b : INT_MAX;
	int s = (y.s) ? x.s / y.s : INT_MAX;
	int c = (y.c) ? x.c / y.c : INT_MAX;
	return min(b, min(s, c));
}
inline burger operator *(int i, const burger & x) {
	return burger(x.b * i, x.s * i, x.c * i);
}
inline burger operator -(const burger & x, const burger & y) {
	return burger(max(x.b - y.b, 0), max(x.s - y.s, 0), max(x.c - y.c, 0));
}
int main(void) {
	int count_b = 0, count_s = 0, count_c = 0;
	scanf("%s", s);
	for (char * ss = s; *ss; ++ss) {
		switch (*ss) {
		case 'B':
			count_b++;
			break;
		case 'S':
			count_s++;
			break;
		case 'C':
			count_c++;
			break;
		}
	}
	burger one(count_b, count_s, count_c);	// reuirements for one
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	burger cur(x, y, z);		// what I currently have
	scanf("%d%d%d", &x, &y, &z);
	burger price(x, y, z);	// price of one
	int price_of_one = price.b*one.b + price.s*one.s + price.c*one.c;
	ll money;
	cin >> money;
	// DIVISION BY ZERO!!!!!!1
	ll ans = ll(cur / one);
	cur = cur - int(ans) * one;	// how much remains?
	while ((cur.b && one.b) || (cur.s && one.s) || (cur.c && one.c)) {
		// ASK YOURSELF, COULD THIS GET INTO AND INFINITE LOOP?
		burger temp = one - cur;
		cur = cur - one;
		// printf("%d %d %d\n", cur.b, cur.s, cur.c);
		// printf("%d %d %d\n", temp.b, temp.s, temp.c);
		int need = temp.b * price.b + temp.s * price.s + temp.c * price.c;
		// if (!need) break;
		if (need > money) {
			cout << ans;
			return 0;
		}
		++ans;
		money -= need;
	}
	ans += (money / price_of_one);
	cout << ans;
	return 0;
}

