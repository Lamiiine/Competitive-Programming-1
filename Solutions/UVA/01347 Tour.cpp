#include<bits/stdc++.h>
#define MAX 512
#define X real()
#define Y imag()
#define dist(a, b) (hypot((a).X - (b).X, (a).Y - (b).Y))
using namespace std;
typedef complex<double> point;
// points have to be sorted by strictly increasing x-coordinate in order for this solution to work!
point arr[MAX];
int n;
double memo[MAX][MAX];
inline double dp(const int i, const int j)
{
	// memorization
	double & ret = memo[i][j];
	if (ret != -1.0) return ret;
	// base case
	const int k = max(i, j) + 1;
	if (k == n)
		return ret = dist(arr[i], arr[j]);
	// recursion
	return ret = min(dist(arr[i], arr[k]) + dp(k, j), dist(arr[j], arr[k]) + dp(i, k));
}
inline void read(void)
{
	for (int x, y, i = 0; i < n; ++i)
	{
		scanf("%d%d", &x, &y);
		arr[i] = point(x, y);
	}
}
inline void init_memo(void)
{
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			memo[i][j] = -1.0;
}
int main(void)
{
	while(~scanf("%d", &n))
	{
		read();
		init_memo();
		printf("%.2lf\n", dp(0, 0));
	}
	return 0;
}

