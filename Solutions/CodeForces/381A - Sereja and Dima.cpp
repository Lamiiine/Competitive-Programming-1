#include<stdio.h>
#define MAX 1005
using namespace std;
int a[MAX];
int n;
int main(void){
	// freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	int ans[2] = {0, 0};
	int j = 0, k = n - 1;
	for (int i = 0; i < n; ++i){
		if (a[j] < a[k])ans[i&1] += a[k--];
		else ans[i&1] += a[j++];
	}
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}

