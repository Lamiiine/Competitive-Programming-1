#include<bits/stdc++.h>
#define MAX 6000
using namespace std;
const int INF = 1e9;
int n;
struct turtle{
	int w;
	int s;
	turtle(){}
	inline turtle(const int _w, const int _s)
	{
		w = _w; s = _s;
	}
} arr[MAX];
inline bool operator < (const turtle & x, const turtle & y)
{
	return (x.s != y.s) ? x.s < y.s : x.w < y.w;
}
/*
 * memo[i] = minimum weight of a stack consisting of i turtles
 */
int memo[MAX];
inline void read(void)
{
	n = 0;
	for (int x, y; ~scanf("%d%d", &x, &y);)
	{
		if (y >= x)
		{
			arr[n++] = turtle(x, y);
		}
	}
}
int main(void)
{
	read();
	if (!n)
	{
		printf("0");
		return 0;
	}
	sort(arr, arr + n);
	memset(memo, 0x3F, sizeof memo);
	memo[0] = arr[0].w;
	int max_k = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = max_k - 1; j >= 0; --j)
		{
			if (arr[i].s >= arr[i].w + memo[j])
			{
				max_k = max(max_k, j + 2);
				memo[j + 1] = min(memo[j + 1], memo[j] + arr[i].w);
			}
		}
		memo[0] = min(memo[0], arr[i].w);
	}
	printf("%d\n", max_k);
	return 0;
}

