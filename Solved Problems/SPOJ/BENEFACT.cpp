#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#define MAX 50005
using namespace std;
int n;
int en;
int head[MAX];
int nxt[MAX << 1];
int from[MAX << 1];
int to[MAX << 1];
int cost[MAX << 1];
int memo[MAX << 1];
inline void addEdge(int F, int T, int C){
	nxt[en] = head[F];	// it's nxt[en], not nxt[F]
	head[F] = en;
	from[en] = F;
	to[en] = T;
	cost[en++] = C;	// don't forget to increment en
}
int dp(int x){	// maximum length of a path passing by edge number i, going in the direction (done == 1)? to: from
	if (memo[x] != -1) return memo[x];
	int ans = 0;
	int index = head[to[x]];
	int v = from[x];
	while (index != -1){
		if (to[index] == v)
		{
			index = nxt[index];		// don't forget to update the value of index before you contineu
			continue;
		}
		ans = max(ans, dp(index));
		index = nxt[index];
	}
	return memo[x] = cost[x] + ans;
}
int main(){
	int TC;
	scanf("%d", &TC);
	while (TC--){
		memset(head, 0xFF, sizeof head);
		memset(memo, 0xFF, sizeof memo);
		en = 0;
		scanf("%d", &n);
		int x, y, z;
		for (int i = 0; i < n - 1; ++i){
			scanf("%d%d%d", &x, &y, &z);
			addEdge(x, y, z);
			addEdge(y, x, z);
		}
		int ans = 0;
		for (int i = 0; i < en; ++i)
			ans = max(ans, dp(i));
		printf("%d\n", ans);
	}
	return 0;
}