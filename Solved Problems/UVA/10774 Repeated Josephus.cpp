#include<bits/stdc++.h>
#define MAX 30010
using namespace std;
int memo[MAX];
inline void init(void){
	memo[1] = 0;	// index zero wins if you only have one person
	for (int i = 2; i < MAX; ++i)
		memo[i] = (memo[i-1] + 2) % i;
}
typedef pair<int, int> ii;
ii solve(int n){
	int x = memo[n] + 1;
	if (x == n) return ii(0, n);
	ii tmp = solve(x);
	return ii(tmp.first + 1, tmp.second);
}
int main(void){
	init();
	int TC; scanf("%d", &TC);
	for(int tc = 1, n; tc <= TC; ++tc){
		scanf("%d", &n);
		ii ans = solve(n);
		printf("Case %d: %d %d\n", tc, ans.first, ans.second);
	}
}

