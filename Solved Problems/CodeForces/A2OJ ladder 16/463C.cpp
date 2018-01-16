#include <bits/stdc++.h>
#define MAX 2002
#define left_idx(i, j) ((i) + (j))
#define right_idx(i, j) ((i) - (j) + MAX)
using namespace std;
typedef long long int ll;
int n;
int a[MAX][MAX];
ll left_diag[MAX * 2], right_diag[MAX * 2];

int main()
{
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &x);
			a[i][j] = x;
			left_diag[left_idx(i, j)] += x;
			right_diag[right_idx(i, j)] += x;
		}
	}
	// get max black!
	ll max_white = 0, max_black = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ll x = left_diag[left_idx(i, j)] + right_diag[right_idx(i, j)] - a[i][j];
			if ((i & 1) == (j & 1))
			{
				if (max_white < x)
				{
					max_white = x;
					x1 = i;
					y1 = j;
				}
			}
			else
			{
				if (max_black < x)
				{
					max_black = x;
					x2 = i;
					y2 = j;
				}
			}
		}
	}
	cout << max_white + max_black << endl;
	++x1; ++y1; ++x2; ++y2;
	cout << x1 << " " << y1 << " " << x2 << " " << y2;
}
/*
4
1 1 1 1
2 1 1 0
1 1 1 0
1 0 0 1
 */

