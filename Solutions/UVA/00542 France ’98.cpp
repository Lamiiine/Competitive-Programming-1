#include<bits/stdc++.h>
#define MAX 16
#define left(s) ((s) << 1)
#define right(s) (((s) << 1) + 1)
using namespace std;
char name[MAX][15];
double p[MAX][MAX];
double memo[MAX][MAX << 1];
inline void read(void)
{
	for (int i = 0; i < MAX; ++i)
	{
		scanf("%s", name[i]);
	}
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			scanf("%lf", p[i] + j);
		}
	}
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			p[i][j] /= 100.0;
		}
	}
}
inline void init_memo(void)
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < (MAX << 1); ++j)
		{
			memo[i][j] = -1.0;
		}
	}
}
inline double dp(const int i, const int j)
{
	double & ret = memo[i][j];
	if (ret != -1.0)
	{
		return ret;
	}
	if (j >= MAX)
	{
		return ret = (i == j - 16) ? 1.0 : 0.0;
	}
	ret = 0.0;
	for (int k = 0; k < MAX; ++k)
	{
		ret += (dp(i, left(j)) * dp(k, right(j)) + dp(i, right(j)) * dp(k, left(j))) * p[i][k];
	}
	return ret;
}
int main(void)
{
	read();
	init_memo();
	for (int i = 0; i < MAX; ++i)
	{
		printf("%-11sp=%.2lf%\n", name[i], dp(i, 1) * 100.0);
	}
	return 0;
}

