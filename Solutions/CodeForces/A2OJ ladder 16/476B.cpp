#include <bits/stdc++.h>
#define MAX 16
using namespace std;
typedef long long int ll;
typedef long double ld;
string a, b;
ll choose[MAX][MAX];
inline void build_choose()
{
	for (int i = 0; i < MAX; ++i)
	{
		choose[i][0] = 1LL;
		for (int j = 1; j < i; ++j)
		{
			choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
		}
		choose[i][i] = 1LL;
		for (int j = i + 1; j < MAX; ++j)
		{
			choose[i][j] = 0LL;
		}
	}
}
inline ld get_prob(const int count_tosses, const int count_heads)
{
	if (count_heads < 0 || count_heads > count_tosses) return 0.0;
	return (ld) choose[count_tosses][count_heads] / (ld) (1 << count_tosses);
}
int main()
{
	build_choose();
	cin >> a >> b;
	int count_tosses = 0, count_heads = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		if (b[i] == '?')
		{
			++count_tosses;
			if (a[i] == '+')
			{
				++count_heads;
			}
		}
		else
		if (a[i] != b[i])
		{
			if (a[i] == '+')
			{
				++count_heads;
			}
			else
			{
				--count_heads;
			}
		}
	}
	cout << fixed << setprecision(9) << get_prob(count_tosses, count_heads);
	return 0;
}
