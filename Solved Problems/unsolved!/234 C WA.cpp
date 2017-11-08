#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#define MAX 100005
using namespace std;
int n;
int t[MAX];
int main(){
	// freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	int posBefore[MAX];
	int negAfter[MAX];
	memset(negAfter, 0, sizeof negAfter);
	posBefore[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", t + i);
		posBefore[i] = posBefore[i - 1];
		if (t[i] >= 0) posBefore[i] += 1;
		if (t[i] <= 0) negAfter[i] = 1;
	}
	for (int i = n - 1; i >= 1; --i)
		negAfter[i] += negAfter[i + 1];
	int ans = INT_MAX;
	for (int i = 1; i < n; ++i){	// k can range from 1 to n-1
		ans = min(ans, posBefore[i] + negAfter[i+1]);
	}
	printf("%d", ans);
	return 0;
}