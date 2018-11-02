#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define eps 1e-9
using namespace std;
int main(){
	// freopen("Input.txt", "r", stdin);
	int r, n;
	int tc = 0;
	while(scanf("%d%d", &r, &n), r || n){
		printf("Case %d: ", ++tc);
		int ans;
		if (r <= n) ans = 0;
		else ans = (r/n) + bool(r%n) - 1;
		if (ans > 26) printf("impossible\n");
		else printf("%d\n", ans);
	}
	return 0;
}

