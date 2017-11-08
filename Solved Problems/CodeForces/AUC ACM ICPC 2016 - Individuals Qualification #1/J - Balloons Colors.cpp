#include<stdio.h>
#include<vector>
#define MAX 2505
using namespace std;
int main(void)
{
	// freopen("Input.txt", "r", stdin);
	int TC; scanf("%d", &TC);
	bool a, b;
	for (int r, g, b, t, i, j; TC--;)
	{
		scanf("%d%d%d", &r, &g, &b);
		t = r | (g << 8) | (b << 16);
		for (i = 0, j = 23; i < j; ++i, --j)
		{
			a = bool(t & (1 << i));
			b = bool(t & (1 << j));
			if (a != b)
			{
				t &= ~(1 << i);
				t &= ~(1 << j);
			}
		}
		printf("%.3d %.3d %.3d\n", t & 0xFF, (t >> 8) & 0xFF, (t >> 16) & 0xFF);
	}
	return 0;
}