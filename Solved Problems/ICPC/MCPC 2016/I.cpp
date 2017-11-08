#include<bits/stdc++.h>
#define MAX (1 << 10)
#define X real()
#define Y imag()
#define dist(a, b) (abs((a).X - (b).X) + abs((a).Y - (b).Y))
using namespace std;
typedef complex<int> point;
point arr[MAX];
int deg[MAX];
int n, d;
inline void read()
{
	scanf("%d%d", &n, &d);
	for (int a, b, i = 0; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		arr[i] = point(a, b);
	}
}
inline void init()
{
	memset(deg, 0, sizeof deg);
}
inline int solve()
{
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (dist(arr[i], arr[j]) <= d)
			{
				++deg[i];
				++deg[j];
			}

	int ans = 0, ans_idx = 0;
	for (int i = 0; i < n; ++i)
		if (deg[i] > ans)
		{
			ans = deg[i];
			ans_idx = i;
		}
	return ans_idx + 1;
}
int main(void)
{
	freopen("intergalactic.in", "r", stdin);
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		printf("%d\n", solve());
	}
	return 0;
}
