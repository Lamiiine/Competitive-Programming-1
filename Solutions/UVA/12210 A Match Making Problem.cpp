#include<stdio.h>
#include<limits.h>
#include<algorithm>
#define MAX 10005
using namespace std;
int b, s;
int main(void){
	// freopen("Input.txt", "r", stdin);
	int tc = 0;
	while(scanf("%d%d", &b, &s), b || s){
		printf("Case %d: ", ++tc);
		int ans = INT_MAX;
		int x;
		for (int i = 0; i < b; ++i)
			scanf("%d", &x), ans = min(ans, x);
		for (int i = 0; i < s; ++i)
			scanf("%d", &x);
		if (b <= s) printf("0\n");
		else printf("%d %d\n", b - s, ans);
	}
	return 0;
}

