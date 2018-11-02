#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define MAX 105
using namespace std;
int n;
int main(){
	freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	int x;
	int numOdd = 0;
	int minOdd = INT_MAX;
	int ans = 0;	// don't forget to initialize!
	for (int i = 0; i < n; ++i){
		scanf("%d", &x);
		ans += x;
		if (!(x & 1)) continue;
		++numOdd;
		minOdd = min(minOdd, x);
	}
	if (!numOdd){
		printf("0");
		return 0;
	}
	if (!(numOdd & 1)) ans -= minOdd;
	printf("%d", ans);
	return 0;
}