#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAX 3005
using namespace std;
typedef long long ll;
struct order{
	int f, d, p;
}a[MAX];
inline const bool operator < (const order & a, const order & b){
	return a.f < b.f;
}
int n;
ll memo[MAX];
void init(void){
	memset(memo, 0xFF, sizeof memo);
	for (int i = n; i < MAX; ++i) memo[i] = 0;
}
ll dp(int i){
	if (memo[i] != -1) return memo[i];
	int ans = a[i].p;	// let say you are taking this order
	int finish = a[i].f + a[i].d;
	int j = i + 1;
	while (a[j].f < finish && j < n) ++j;
	return memo[i] = max(ans + dp(j), dp(i + 1));
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	char s[85];
	bool first = true;
	while (scanf("%d", &n) != EOF){
		if (!first) printf("\n");
		first = false;
		for (int i = 0; i < n; ++i)
			scanf("%s%d%d%d", s, &a[i].f, &a[i].d, &a[i].p);
		sort(a, a + n);
		init();
		printf("%lld\n", dp(0));
	}
	return 0;
}