#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;
ii h[16];
int n;
double memo[1 << 16];
double dist[16][16];
inline double get_dist(int i, int j){
	return hypot(h[i].first - h[j].first, h[i].second - h[j].second);
}
inline void init(int n){
	for (int i = 0; i < (1 << n); ++i)
		memo[i] = -1.0;
	for (int i = 0; i < n; ++i)
	for (int j = i + 1; j < n; ++j)
		dist[i][j] = dist[j][i] = get_dist(i, j);
}
inline double dp(int i){
	double & ret = memo[i];
	if (ret != -1.0) return ret;
	int j = 0;
	while (i &(1 << j)) ++j;
	i |= (1 << j);
	double ans = 1e9;
	for (int k = j + 1; k < n; ++k)
	if (!(i & (1 << k)))
		ans = min(ans, dist[j][k] + dp(i | (1 << k)));
	return ret = ans;
}
char s[30];
int main() {
	// freopen("Input.txt", "r", stdin);
	// freopen("Output.txt", "w", stdout);
	for (int tc = 1; scanf("%d", &n), n; ++tc){
		n <<= 1;
		for (int i = 0; i < n; ++i)
			scanf("%s%d%d", s, &h[i].first, &h[i].second);
		init(n);
		memo[(1 << n) - 1] = 0.0;
		printf("Case %d: %.2lf\n", tc, dp(0));
	}
	return 0;
}