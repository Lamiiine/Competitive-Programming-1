#include<stdio.h>
using namespace std;
int main(){
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	// 'b' BEING NEGATIVE IS A CORNER CASE
	b += (100 * n);
	b %= n;
	a += b;
	a %= n;
	// 'a' BEING ZERO IS A CORNER CASE
	if (!a) printf("%d", n);
	else printf("%d", a);
	return 0;
}