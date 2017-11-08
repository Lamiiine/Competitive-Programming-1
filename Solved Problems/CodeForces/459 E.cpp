// Nice problem.. New idea!
// It was difficult to trace
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 300005
using namespace std;
typedef pair<int, int> ii;
struct edge{
	int f;	// from
	int t;	// to
	int c;	// cost
};
inline bool operator <(edge x, edge y){
	return (x.c < y.c);
}
int main(){
	int n, m;
	edge g[MAX];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i){
		scanf("%d%d%d", &g[i].f, &g[i].t, &g[i].c);
	}
	sort(g, g+m);
	int counter = 0;
	int dp[MAX];
	memset(dp, 0, sizeof dp);
	vector<ii> buffer;
	while(counter < m){
		int cur_c = g[counter].c;
		while(g[counter].c == cur_c && counter < m){
			int f = g[counter].f;
			int t = g[counter].t;
			// you have to use a buffer in order to insert all simaltenously
			buffer.push_back(ii(t, max(dp[t], dp[f] + 1)));
			++counter;
		}
		// if two elements in the buffer have the same weight and point to the same location!
		for (vector<ii>::iterator iter = buffer.begin(); iter != buffer.end(); ++iter) dp[(*iter).first] = max((*iter).second, dp[(*iter).first]);
		buffer.clear();
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
	printf("%d", ans);
	return 0;
}
