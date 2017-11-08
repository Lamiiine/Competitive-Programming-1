#include <bits/stdc++.h>
#define MAX 100
#define INF 1000000000
using namespace std;
int score[MAX], val[MAX], n;
inline void read(void)
{
	for (int i = 0, x, y, z; i< n; ++i)
	{
		scanf("%d%d%d%d", &x, &y, &z, score + i);
		--x; --y; --z;
		val[i] = (1 << x) | (1 << y) | (1 << z);
	}
}
int main() {
	for(int tc = 1; scanf("%d", &n), n; ++tc)
	{
		read();
		int ans = 0;
		for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		for (int k = j + 1; k < n; ++k)
			if ((val[i] | val[j] | val[k]) == 0x1FF)
				ans = max(ans, score[i] + score[j] + score[k]);
		printf("Case %d: %d\n", tc, ans ? ans : -1);
	}
	return 0;
}