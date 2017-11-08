#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int b, r;
	scanf("%d", &b);
	int memo[20005];
	int x[20005];
	int Max;
	int start, end;
	for (int z = 1; z <= b; ++z){
		scanf("%d", &r);
		r--;
		memset(memo, 0xFF, sizeof(int)*r);
		for (int i = 0; i < r; i++) scanf("%d", &x[i]);
		memo[r] = -1;
		Max = 0;
		for (int i = r - 1; i >= 0; i--)
			Max = max(Max, memo[i] = x[i] + memo[i + 1]*(memo[i + 1] > 0));
		int i = 0;
		start = end = 0;
		int startTemp, endTemp;
		while (i < r){
			startTemp = i;
			while (memo[startTemp] < Max) startTemp++;
			endTemp = startTemp;
			while (endTemp < r && memo[endTemp] >= 0) endTemp++;
			i = endTemp;
			if (endTemp - startTemp > end - start) end = endTemp, start = startTemp;
		}
		if (Max > 0) printf("The nicest part of route %d is between stops %d and %d\n", z, start + 1, end + 1);
		else printf("Route %d has no nice parts\n", z);
	}
	return 0;
}