#include <bits/stdc++.h>
#define MAX 10
using namespace std;
int num_offers;
struct offer{
	int a[6];
	inline offer(int x, int y, int z, int w, int u, int v)
	{
		a[0] = max(x, 0);
		a[1] = max(y, 0);
		a[2] = max(z, 0);
		a[3] = max(w, 0);
		a[4] = max(u, 0);
		a[5] = max(v, 0);
	}
	offer(){}
} o[20];
inline int dp(const offer &);
inline int dp(const int, const int, const int, const int, const int, const int);
int n;
inline bool have_common(const offer & x, const offer & y)
{
	bool flag = false;
	for (int i = 0; i < 6 && !flag; ++i)
	if (x.a[i] && y.a[i]) flag = true;
	if (!flag) return false;
	for (int i = 0; i < 6; ++i)
	if (y.a[i] > x.a[i]) return false;
	return true;
}
inline bool operator == (const offer & x, const offer & y)
{
	return !memcmp(&x, &y, sizeof (offer));
}
inline offer operator - (const offer & x, const offer & y)
{
	return offer(x.a[0] - y.a[0], x.a[1] - y.a[1], x.a[2] - y.a[2], x.a[3] - y.a[3], x.a[4] - y.a[4], x.a[5] - y.a[5]);
}
int price[20];
/*
 * memo[i][j][k][l][m][n] stores the minimum price of
 * an order having i items of type 1, j items of type 2, ...etc.
 */
int memo[MAX][MAX][MAX][MAX][MAX][MAX];
inline int dp(const offer & w)
{
	return dp(w.a[0], w.a[1], w.a[2], w.a[3], w.a[4], w.a[5]);
}
inline int dp(const int a, const int b, const int c, const int d, const int e, const int f)
{
	int & ret = memo[a][b][c][d][e][f];
	if (ret != -1) return ret;
	const offer current_state(a, b, c, d, e, f);
	ret = INT_MAX;
	for (int i = 0; i < num_offers; i = (i == n) ? 6 : i)
	{
		if (i >= num_offers) break;
		const offer & current_offer = o[i];
		if (have_common(current_state, current_offer))
			ret = min(ret, price[i] + dp(current_state - current_offer));
		++i;
	}
	return ret;
}
inline void init_memo()
{
	memset(memo, 0xFF, sizeof memo);
	memo[0][0][0][0][0][0] = 0;
}
inline void init_o(void){
	o[0] = offer(1, 0, 0, 0, 0, 0);
	o[1] = offer(0, 1, 0, 0, 0, 0);
	o[2] = offer(0, 0, 1, 0, 0, 0);
	o[3] = offer(0, 0, 0, 1, 0, 0);
	o[4] = offer(0, 0, 0, 0, 1, 0);
	o[5] = offer(0, 0, 0, 0, 0, 1);
}
int main() {
	while(~scanf("%d", &n))
	{
		init_memo();
		memset(o, 0, sizeof o);
		init_o();
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", price + i);
		}
		int m; scanf("%d", &m); num_offers = 6 + m;
		for (int i = 6; i < num_offers; ++i)
		{
			for (int j = 0; j < n; ++j)
				scanf("%d", &(o[i].a[j]));
			scanf("%d", price + i);
		}
		scanf("%d", &m);
		while(m--)
		{
			offer order(0, 0, 0, 0, 0, 0);
			for (int i = 0; i < n; ++i)
			scanf("%d", &order.a[i]);
			printf("%d\n", dp(order));
		}
	}
	return 0;
}
