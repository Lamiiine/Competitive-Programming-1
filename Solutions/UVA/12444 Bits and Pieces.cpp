#include<stdio.h>
#define LSOne(s) (s & (-s))
using namespace std;
int A, B;
bool solve(const int c, const int d){
	// c is the result of anding
	// c is the result of oring
	int a = c, b = c;
	// For sure, you have all the ones in c and all the zeros in d
	// What you are not sure about is the bits are on in d and off in c
	if (c & (~d)) return false;
	int diff = d &(~c);
	while(true){
		int p = LSOne(diff);
		if (p == diff) {b += p;break;}
		a += p, diff -= p;
	}
	A = a, B = b;
	return true;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int x, y; TC--;){
		scanf("%d%d", &x, &y);
		if (solve(x, y))
		printf("%d %d\n", A, B);
		else printf("-1\n");
	}
	return 0;
}

