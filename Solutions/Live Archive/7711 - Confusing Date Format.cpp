#include <bits/stdc++.h>
using namespace std;
inline bool between(const int a, const int b, const int c)
{
	return a >= b && a <= c;
}
const int length[13] = {-1, 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline int get_month_len(const int m, const int y)
{
	if (m != 2)
	{
		return length[m];
	}
	// It's February!
	return (y != 0 && y % 4 == 0) ? 29 : 28;
}
struct date
{
	int d, m, y;
	inline date(const int _d, const int _m, const int _y): d(_d), m(_m), y(_y) {}
	inline bool operator == (const date & other) const
	{
		return d == other.d && m == other.m && y == other.y;
	}
	inline bool is_valid()
	{
		if (!between(m, 1, 12)) return false;
		if (!between(d, 1, get_month_len(m, y))) return false;
		return true;
	}
};

inline int solve()
{
	char s[16]; scanf("%s", s);
	vector<int> values;
	for (int a, i = 0; i <= 6; i += 3)
	{
		s[i + 2] = 0;
		sscanf(s + i, "%d", &a);
		values.push_back(a);
	}
	if (date(values[0], values[1], values[2]) == date(4, 5, 1))
		return 1;
	sort(values.begin(), values.end());
	int ans = 0;
	do
	{
		ans += date(values[0], values[1], values[2]).is_valid();
	} while(next_permutation(values.begin(), values.end()));
	return ans;
}
int main()
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		printf("Case #%d: %d\n", tc, solve());
	}
	return 0;
}
/*
4
04-10-11
29-02-15
60-50-90
02-00-01
 */

