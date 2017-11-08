// 8 11967 Hic-Hac-Hoe
#include<bits/stdc++.h>
#define MAX 100100
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
ii crosses[MAX / 2], noughts[MAX / 2];
int c, n, k;
inline void read(void)
{
	c = n = 0;
	int m;
	scanf("%d%d", &m, &k);
	for (int i = 0, x, y; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		if (i & 1)
			noughts[n++] = ii(x, y);
		else crosses[c++] = ii(x, y);
	}
}
inline bool win_row(const ii * arr, const int sz, const ii & start)
{
	for (ll i = 1LL; i < k; ++i)
		if (!binary_search(arr, arr + sz, ii(start.first + i, start.second)))
			return false;
	return true;
}
inline bool win_col(const ii * arr, const int sz, const ii & start)
{
	for (ll i = 1LL; i < k; ++i)
		if (!binary_search(arr, arr + sz, ii(start.first, start.second + i)))
			return false;
	return true;
}
inline bool win_d1(const ii * arr, const int sz, const ii & start)
{
	for (ll i = 1LL; i < k; ++i)
		if (!binary_search(arr, arr + sz, ii(start.first + i, start.second + i)))
			return false;
	return true;
}
inline bool win_d2(const ii * arr, const int sz, const ii & start)
{
	for (ll i = 1; i < k; ++i)
		if (!binary_search(arr, arr + sz, ii(start.first - i, start.second + i)))
			return false;
	return true;
}

inline bool win(ii * arr, const int sz)
{
	for (int i = 0; i < sz; ++i)
		if (win_col(arr, sz, arr[i]) || win_row(arr, sz, arr[i]) || win_d1(arr, sz, arr[i]) || win_d2(arr, sz, arr[i]))
			return true;
	return false;
}
char ans[10] = { 0 };
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		read();
		sort(crosses, crosses + c);
		sort(noughts, noughts + n);
		bool cw = (k <= 0) || win(crosses, c), nw = (k <= 0) || win(noughts, n);
		*ans = 0;
		if (cw)
			if (nw)
				strcpy(ans, "error");
			else
				strcpy(ans, "crosses");
		else
			if (nw)
				strcpy(ans, "noughts");
			else
				strcpy(ans, "none");

		printf("Case %d: %s\n", tc, ans);
	}
	return 0;
}

