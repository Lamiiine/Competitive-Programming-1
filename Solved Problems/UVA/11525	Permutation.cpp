#include<bits/stdc++.h>
#define MAX 50050
#define lsone(s) ((s) & (-s))
using namespace std;
int ft[MAX];
int k;
inline void add(int i, const int val)
{
	for (;i <= k; i += lsone(i))
	{
		ft[i] += val;
	}
}
inline int query(int i)
{
	int ans = 0;
	for (;i; i -= lsone(i))
	{
		ans += ft[i];
	}

	return ans;
}
inline int lower_bound(const int v)
{
	int lo = 1, hi = k;
	while(lo != hi)
	{
		const int mid = (lo + hi) >> 1;
		if (query(mid) >= v)
		{
			hi = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}

	return lo;
}
inline void init(void)
{
	memset(ft, 0, sizeof ft);
	for (int i = 1; i <= k; ++i)
	{
		add(i, 1);
	}
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d", &k);
		init();
		for (int s, i = 0; i < k; ++i)
		{
			scanf("%d", &s);
			const int ind = lower_bound(s + 1);
			printf("%d%c", ind, i == k - 1 ? '\n' : ' ');
			add(ind, -1);
		}
	}
	return 0;
}

