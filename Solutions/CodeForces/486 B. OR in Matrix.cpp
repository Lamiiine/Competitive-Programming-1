#include<bits/stdc++.h>
#define MAX (1 << 7)
using namespace std;
bool row[MAX] = {false}, column[MAX] = {false};
int m, n;
int mat[MAX][MAX];
int ans[MAX][MAX] = { 0 };
inline void read(void)
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", mat[i] + j);
}
inline void mark()
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (!mat[i][j])
				row[i] = true, column[j] = true;
}
inline bool valid()
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (mat[i][j])
			{
				bool flag = false;
				// find an entry in row i
				if (!row[i])
				for (int k = 0; k < n; ++k)
					if (!column[k])
					{
						ans[i][k] = 1;
						flag = true;
						break;
					}
				// find an entry in column j
				if (!column[j])
					for (int k = 0; k < m; ++k)
						if (!row[k])
						{
							ans[k][j] = 1;
							flag = true;
							break;
						}
				if (!flag) return false;
			}

	return true;
}
inline void print()
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		printf("%d%c", ans[i][j], j == n - 1 ? '\n' : ' ');
}
int main(void)
{
	read();
	mark();
	if (!valid()) printf("NO");
	else printf("YES\n"), print();
	return 0;
}

