#include <stdio.h>
#include <algorithm>
#define Num 2005
using namespace std;
 
int main(){
	int n, x;
	int p[Num];
	bool processed[Num];
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		processed[i] = false;
		p[i] = i;
		scanf("%d", &x);
		if (x != -1) p[i] = --x;
	}
	//
	int cur, Max = 1;
	for (int i = 0; i < n; ++i){
		if (processed[i]) continue;
		processed[i] = true;
		x = i;
		cur = 1;
		while (p[x] != x) processed[x = p[x]] = true, cur++;
		Max = max(Max, cur);
	}
	printf("%d\n", Max);
	return 0;
}
