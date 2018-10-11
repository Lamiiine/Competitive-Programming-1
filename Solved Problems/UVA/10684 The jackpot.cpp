#include <stdio.h>
#include <algorithm>
// algorithm does not work with long long
using namespace std;
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int n;
	int x[10005];
	int memo[10005];
	int Max;
	while (scanf("%d", &n), n){
		for (int i = 0; i < n; i++) scanf("%d", &x[i]);
		Max = memo[n - 1] = x[n - 1];
		for (int i = n - 2; i >= 0; i--)
			Max = max(Max, memo[i] = x[i] + max(0, memo[i+1]));
		if (Max > 0) printf("The maximum winning streak is %d.\n", Max); 
		else printf("Losing streak.\n");
	}
	return 0;
}