#include <bits/stdc++.h>
#define MAX 128
#define SZ (k - 1)
using namespace std;
int k;
inline void print(const int i, const int j)
{
	printf("%d %d\n", i, j);
}
int main()
{
	scanf("%d", &k);
	if (k & 1)
	{
		printf("YES\n");
		// K is odd!
		/* Vertices 1 ... k - 1,
		 * k ... 2k - 2,
		 * 2k - 1 .. 3k - 3,
		 * 3k - 2 .. 4k - 4,
		 *
		 * 4k - 3,
		 * 4k - 2
		 */
		const int a = 4 * SZ + 1, b = 4 * SZ + 2;
		int n = b, m = (b * k) / 2;
		print(n, m);
		print(a, b);
		// Connect 1 ... k - 1
		for (int i = 1; i <= SZ; ++i)
		{
			print(a, i);
			print(b, i + 2 * SZ);
			for (int j = SZ + 1; j <= 2 * SZ; ++j)
			{
				print(i, j);
				print(i + 2 * SZ, j + 2 * SZ);
			}
		}
		for (int j = SZ + 1; j <= 2 * SZ; j += 2)
		{
			print(j, j + 1);
			print(j + 2 * SZ, j + 1 + 2 * SZ);
		}
	}
	else
	{
		printf("NO");
	}
	return 0;
}

