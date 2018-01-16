#include <bits/stdc++.h>
#define MAX (1 << 20)
#define lsone(i) ((i) & (-i))
using namespace std;
typedef long long ll;
int n;
int a[MAX], tmp[MAX];
ll ft[MAX];
ll acc[MAX];
inline ll rsq(int i)
{
	ll ans = 0LL;
	for (; i; i -= lsone(i))
		ans += ft[i];
	return ans;
}
inline void update(int i, ll v)
{
	for (; i <= n; i += lsone(i))
		ft[i] += v;
}
int main()
{
	// Reading!
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	// Grid compression!
	memcpy(tmp, a, sizeof a);
	sort(tmp, tmp + n);
	for (int i = 0; i < n; ++i)
		a[i] = 1 + (lower_bound(tmp, tmp + n, a[i]) - tmp);
	// rsq(a[i]) = number of elements with indexes greater than i that are less than a[i].
	for (int i = n - 1; i >= 0; --i)
	{
		acc[a[i]] = rsq(a[i]);
		update(a[i], 1LL);
	}
	// for (int i = 1; i <= n; ++i) cout << acc[i] << endl;
	memset(ft, 0, sizeof ft);
	ll ans = 0LL;
	for (int i = n - 1; i >= 0; --i)
	{
		ans += rsq(a[i]);
		update(a[i], acc[a[i]]);
	}
	cout << ans;
	return 0;
}
/*
input
3
3 2 1
output
1
input
3
2 3 1
output
0
input
4
10 8 3 1
output
4
input
4
1 5 4 3
output
1
 */

