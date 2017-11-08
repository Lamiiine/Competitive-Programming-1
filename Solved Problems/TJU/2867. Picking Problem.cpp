#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAX 10005
using namespace std;
short lis[MAX];	// minimum ending time of i games
void init(void){
	memset(lis, 0x3F, sizeof lis);
}
typedef pair<short, short> ss;
int n;
ss a[MAX];
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d", &n), n){
		init();
		for (int i = 0, x, y; i < n; ++i)
			scanf("%d%d", &x, &y), a[i] = ss(x, x + y - 1);
		sort(a, a + n);
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int ind = lower_bound(lis, lis + n, a[i].first) - lis;
			lis[ind] = min(a[i].second, lis[ind]);
			ans = max(ans, ind);
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}

