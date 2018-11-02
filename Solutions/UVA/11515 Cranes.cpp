#include<bits/stdc++.h>
#define MAX 15
using namespace std;
int memo[MAX][1 << MAX];
int n;
struct crane{
	int x, y, r;
	crane(int _x, int _y, int _r):x(_x), y(_y), r(_r){}
	crane(){}
} arr[MAX];
inline bool collide(const crane & a, const crane & b)
{
	const int dx = a.x - b.x, dy = a.y - b.y;
	const int sqr_dst = dx * dx + dy * dy;
	return sqr_dst <= (a.r + b.r) * (a.r + b.r);
}
inline int dp(const int i, const int mask)
{
	if (i == n) return 0;
	int & ret = memo[i][mask];
	if (ret != -1) return ret;
	ret = dp(i + 1, mask);
	for (int j = 0; j < i; ++j)
		if ((mask & (1 << j)) && collide(arr[i], arr[j]))
			return ret;
	return ret = max(ret, arr[i].r * arr[i].r + dp(i + 1, mask | (1 << i)));
}
inline void init()
{
	memset(memo, -1, sizeof memo);
}
inline void read()
{
	scanf("%d", &n);
	for (int i = 0, x, y, r; i < n; ++i)
		scanf("%d%d%d", &x, &y, &r), arr[i] = crane(x, y, r);
}
int main()
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		printf("%d\n", dp(0, 0));
	}
	return 0;
}

