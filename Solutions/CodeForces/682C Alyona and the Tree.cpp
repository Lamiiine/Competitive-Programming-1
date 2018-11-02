#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef long long int ll;
int p[MAX];	// parent of i
int c[MAX];	// cost of edge from i to p[i]
int a[MAX];	// value written on node i
bool done[MAX];
ll memo[MAX];
int n;
bool ex[MAX];
ll dp(const int i){
	if (done[i]) return memo[i];
	done[i] = true;
	return memo[i] = max((ll)c[i], (ll) c[i] + dp(p[i]));
}
inline void init(void){
	memset(done, 0, sizeof done);
	done[1] = 1;
	memo[1] = 0;
	memset(ex, 0, sizeof ex);
}
vector<int>adj[MAX];
void dfs(const int i, bool flag){
	ex[i] = flag = (ex[i] | flag);
	const vector<int>&v = adj[i];
	for (int j = 0; j < v.size(); ++j)
		dfs(v[j], flag);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 2; i <= n; ++i)
		scanf("%d%d", p + i, c + i), adj[p[i]].push_back(i);
	for (int i = 2; i <= n; ++i)
		if (dp(i) > a[i])
			ex[i] = 1;
	dfs(1, 0);
	int ans = 0;
	for (int i = 2; i <= n; ++i)
		ans += ex[i];
	printf("%d", ans);
	return 0;
}

