#include<bits/stdc++.h>
#define MAX 15
using namespace std;
typedef pair<int, int> ii;
int r, c;
int memo[MAX][1 << MAX];
char arr[32][32];
int d[32][32][32][32];
ii start;
ii nut[MAX];
int n;	// number of nuts
inline int dist(const ii & x, const ii & y)
{
	return max(abs(x.first - y.first), abs(x.second - y.second));
}
// you last collected nut #i, having collected
inline int dp(const int i, const int mask)
{
	int & ret = memo[i][mask];
	if (ret != -1)
		return ret;
	if (mask == (1 << n) - 1)
		return ret = dist(nut[i], start);	// no more steps
	ret = 1000000000;
	for (int j = 0; j < n; ++j)
		if (!(mask & (1 << j)))
			// not yet taken!
			ret = min(ret, dist(nut[i], nut[j]) + dp(j, mask | (1 << j)));
	return ret;
}
int main(void)
{
	while(~scanf("%d%d", &r, &c))
	{
		memset(memo, -1, sizeof memo);
		for (int i = 0; i < r; ++i)
			scanf("%s", arr[i]);
		n = 0;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				switch(arr[i][j])
				{
				case '#': nut[n++] = ii(i, j); break;
				case 'L': start = ii(i, j); break;
				}
		int ans = 1000000000;
		// pick a nut to start at
		for (int i = 0; i < n; ++i)
			ans = min(ans, dist(start, nut[i]) + dp(i, 1 << i));
		if (!n) printf("0\n");
		else printf("%d\n", ans);
	}
	return 0;
}

