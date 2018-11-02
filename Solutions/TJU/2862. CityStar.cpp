#include<stdio.h>
#include<limits.h>
#include<algorithm>
#define MAX 100005
using namespace std;
int n;
int a[MAX];
int ans_v, ans_i, ans_j;
void solve(void){
	sort(a, a + n);
	ans_v = INT_MAX;
	for (int i = 0, j = 4; j < n; ++i, ++j)
		if (ans_v > a[j] - a[i])
			ans_v = a[ans_j = j] - a[ans_i = i];
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		printf("Scenario #%d:\n", tc);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		solve();
		printf("%d:", ans_v + 1);
		for (int i = ans_i; i <= ans_j; ++i)
			printf(" %d", a[i]);
		printf("\n\n");
	}
	return 0;
}

