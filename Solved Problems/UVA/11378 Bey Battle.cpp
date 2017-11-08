#include<bits/stdc++.h>
#define X first
#define Y second
#define avg(a, b) ((a + b) >> 1)
#define MAX 100005
using namespace std;
typedef pair<int, int> ii;
int n;
ii arr[MAX];
inline int dist(const ii & a, const ii & b)
{
	return max(abs(a.X - b.X), abs(a.Y - b.Y));
}
inline bool cmp_x(const ii & a, const ii & b)
{
	return a.X < b.X;
}
inline bool cmp_y(const ii & a, const ii & b)
{
	return a.Y < b.Y;
}

ii tmp[MAX];
inline int solve(const int l, const int r)
{
	if (r - l < 3)
	{
		// base case!
		int ans = INT_MAX;
		for (int i = l; i <= r; ++i)
			for (int j = i + 1; j <= r; ++j)
				ans = min(ans, dist(arr[i], arr[j]));
		return ans;
	}
	const int m = avg(l, r);
	int ans = min(solve(l, m), solve(m + 1, r));
	ii * low = lower_bound(arr + l, arr + m + 1, ii(arr[m + 1].X - ans, 0), cmp_x);
	ii * up = lower_bound(arr + m + 1, arr + r + 1, ii(arr[m].X + ans, 0), cmp_x);
	const int num = up - low;
	memcpy(tmp, low, num * sizeof (ii));
	sort(tmp, tmp + num, cmp_y);
	for (int i = 0; i < num; ++i)
		for(int k = i + 1; k < num && tmp[k].Y - tmp[i].Y < ans; ++k)
			ans = min(ans, dist(tmp[i], tmp[k]));
	return ans;
}
inline void read(void)
{
	for (int a, b, i = 0; i < n; ++i)
		scanf("%d%d", &a, &b), arr[i] = ii(a, b);
}
int main(void)
{
	while(~scanf("%d", &n))
	{
		read();
		sort(arr, arr + n, cmp_x);
		printf("%d\n", solve(0, n - 1));
	}
	return 0;
}

