#include <bits/stdc++.h>
using namespace std;

vector<int> v;
inline void init_fib()
{
	v.push_back(1); v.push_back(2);
	for(int val; v.back() != 1836311903;)
	{
		val = v.back() + v[v.size() - 2];
		v.push_back(val);
	}
}

int arr[10100];
int n;
inline void read(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
}
inline int solve()
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < v.size(); ++j)
		ans += upper_bound(arr + i + 1, arr + n, v[j] - arr[i]) - lower_bound(arr + i + 1, arr + n, v[j] - arr[i]);
	return ans;
}
inline void test_fib()
{
	for (int i = 0; i < v.size(); ++i)
		printf("%d\n", v[i]);
}
int main()
{
#ifdef ONLINE_JUDGE
	freopen("bill.in", "r", stdin);
#endif
	init_fib();
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		sort(arr, arr + n);
		printf("%d\n", solve());
	}
}
