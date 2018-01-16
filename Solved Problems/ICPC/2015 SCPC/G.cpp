#include<bits/stdc++.h>
#define MAX 128
using namespace std;

char arr[MAX * MAX];
int ans[MAX];
int n;

int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d", &n);
		memset(ans, 0, sizeof ans);
		for (int iter = 0; iter < 3; ++iter)
		{
			scanf("%s", arr);
			int j = 0;
			for (int i = 0; i < n; ++i)
			{
				int repeat = 3;
				while(repeat--)
				{
					if (arr[j++] == '*')
						ans[i] += 4;
				}
			}
		}

		int x = 0;
		for (int i = 0; i < n; ++i)
			x = max(x, ans[i]);
		printf("%d\n", x);
	}
}
