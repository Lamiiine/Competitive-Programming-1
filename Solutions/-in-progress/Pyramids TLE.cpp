#include<bits/stdc++.h>
#define MAX 500
#define v_size 320
#define OO 125
using namespace std;
struct pyramid{
	int height;
	bool high;
	int sz;
	pyramid(int _height, bool _high, int _sz) : height(_height), high(_high), sz (_sz) {}
	pyramid(){}
};
inline bool cmp(const pyramid & a, const pyramid & b)
{
	if (a.sz != b.sz) return a.sz > b.sz;
	return a.high;
}
vector<pyramid> v;
char memo[v_size + 3][1 << 20];
/*
 * is it possible to construct pyramids starting at style # i,
 * knowing that you have
 * j stones left
 */
inline char dp(const int i, const int j)
{
	char & ret = memo[i][j];
	if (ret != -1) return ret;
	if (j == 0)
		return ret = 0;
	if (i >= v_size)
		return ret = OO;
	return ret = min((char)dp(i + 1, j), (char) (v[i].sz <= j) ? char((char)1 + dp(i + 1, j - v[i].sz)) : char(OO));
}
inline void init_memo(void)
{
	memset(memo, -1, sizeof memo);
}
inline void init_v(void)
{
	int sz_h[MAX];
	int sz_l[MAX];
	sz_h[0] = sz_l[0] = 0;
	for (int i = 1; i < MAX; ++i)
		sz_h[i] = i * i + sz_h[i - 1];
	sz_l[1] = 1;
	for (int i = 2; i < MAX; ++i)
		sz_l[i] = sz_l[i - 2] + i * i;

	for (int i = 3; sz_l[i] <= 1000000; ++i)
		v.push_back(pyramid(i, 0, sz_l[i]));
	for (int i = 2; sz_h[i] <= 1000000; ++i)
		v.push_back(pyramid(i, 1, sz_h[i]));
	sort(v.begin(), v.end(), cmp);
}
inline void path(int j)
{
	for(int i = 0; j && i < v_size; ++i)
	{
		if (v[i].sz <= j && 1 + dp(i + 1, j - v[i].sz) <= dp(i + 1, j))
		{
			printf(" %d%c", v[i].height, v[i].high ? 'H' : 'L');
			j -= v[i].sz;
		}
	}
}
inline void test(void)
{
	for (int n = 1; n <= 1000000; ++n)
	{
		printf("%d: ", n);
		if (dp(0, n) >= OO) printf(" impossible");
		else path(n);
		printf("\n");
	}
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	init_v();
	init_memo();
	for (int n, tc = 1; scanf("%d", &n), n; ++tc)
	{
		printf("Case %d:", tc);
		if (dp(0, n) >= OO) printf(" impossible");
		else path(n);
		printf("\n");
	}
	return 0;
}

