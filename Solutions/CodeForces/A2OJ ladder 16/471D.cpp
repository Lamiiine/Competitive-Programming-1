#include <bits/stdc++.h>
#define MAX 200005
using namespace std;
int s[MAX], p[MAX];
int n, m;	// Length of text and pattern!
int f[MAX];
inline int get_f(int i, const int c)
{
	while (i && c != p[i])
		i = f[i - 1];
	if (c == p[i])
		++i;
	return i;
}
inline void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", s + i);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", p + i);
	}
}
inline void preprocess()
{
	for (int i = n - 1; i >= 1; --i)
	{
		s[i] -= s[i - 1];
	}
	for (int i = m - 1; i >= 1; --i)
	{
		p[i] -= p[i - 1];
	}
	--n; --m;
	for (int i = 0; i < n; ++i)
	{
		s[i] = s[i + 1];
	}
	for (int i = 0; i < m; ++i)
	{
		p[i] = p[i + 1];
	}
	f[0] = 0;
	for (int i = 1; i < m; ++i)
		f[i] = get_f(f[i - 1], p[i]);
}
inline int solve()
{
	if (m == 1)
		return n;
	if (m > n)
		return 0;
	preprocess();
	int ans = 0;
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		if ((j = get_f(j, s[i])) == m)
		{
			++ans;
			j = f[j - 1];
		}
	}
	return ans;
}
int main()
{
	read();
	printf("%d", solve());
	return 0;
}

