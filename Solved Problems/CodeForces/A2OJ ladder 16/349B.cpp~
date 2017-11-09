#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
using namespace std;
char s[1000000];
int Count;
int main() {
	Count = 0;
	int v;
	int a[10];
	scanf("%d", &v);
	for (int i = 1; i <= 9; ++i) scanf("%d", &a[i]);
	int Min = INT_MAX;
	for (int i = 1; i <= 9; ++i) Min = min(Min, a[i]);
	if (v < Min){
		printf("-1"); return 0;
	}
	Count = v/Min;
	int x;
	for (int i = 9;; --i) if (a[i] == Min) {x = i; break;}
	memset(s, x, Count);
	int paint = v%Min;
	
	for (int i = Count-1; i>= 0 && paint; --i){
		paint += a[s[i]];
		for (int j = 9; j >= 1; --j)
		if (paint >= a[j]){
			s[i] = j;
			paint -= a[j];
		}
	}
	for (int i = Count -1; i >= 0; --i) printf("%d", int(s[i]));
	return 0;
}
