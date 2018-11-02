#include<bits/stdc++.h>
#define N 9
using namespace std;
int arr[N][N];
int m;
int n;
inline void read()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", arr[i] + j);
}
inline bool valid(const int i, const int j, const int x)
{
	for (int k = 0; k < n; ++k)
		for (int t = 0; t < n; ++t)
			if ((i != k || j != t)
					&& (i == k || j == t || (i / m == k / m && j / m == t / m))
					&& arr[k][t] == x)
					return false;
	return true;
}
inline bool rec(const int idx)
{
	if (idx == n * n)
		return true;
	const int i = idx / n, j = idx % n;
	if (arr[i][j])
		return rec(idx + 1);
	for (int k = 1; k <= n; ++k)
		if (valid(i, j, k))
		{
			arr[i][j] = k;
			if (rec(idx + 1))
				return true;
		}
	return arr[i][j] = 0;
}
int main(void)
{
	for (int tc = 0; ~scanf("%d", &n); ++tc)
	{
		if (tc) printf("\n");
		m = n;
		n *= n;
		read();
		if (!rec(0)) printf("NO SOLUTION\n");
		else
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					printf("%d%c", arr[i][j], j == n - 1 ? '\n' : ' ');
	}
	return 0;
}

