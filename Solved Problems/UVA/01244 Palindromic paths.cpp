#include<bits/stdc++.h>
#define MAX 53
using namespace std;
int n;
int memo[MAX][MAX];
char adj[MAX][MAX];
inline int dp(const int i, const int j)
{
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	ret = 1;	// if you go from i to j directly
	for (int k = i + 1; k < j; ++k)
	{
		for (int t = j - 1; t >= k; --t)
		{
			if (adj[i][k] == adj[t][j])
			{
				ret = max(ret, 2 + dp(k, t));
			}
		}
	}
	return ret;
}
inline void init(void)
{
	memset(memo, 0xFF, sizeof memo);
	for (int i = 0; i <= n; ++i)
	{
		memo[i][i] = 0;
		memo[i][i + 1] = 1;
		memo[i + 1][i] = 0;
	}
}
inline void read(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", adj[i]);
	}
}
struct option{
	int a, b;
	char c;
	option(int _a, int _b, char _c){
		a = _a; b = _b; c = _c;
	}
};
inline bool cmp(const option & x, const option & y)
{
	return x.c < y.c;
}
inline string solve(const int i, const int j)
{
	if (i >= j)
	{
		return "";
	}
	int cur_ans = dp(i, j);
	if (j == i + 1 || cur_ans == 1)
	{
		return string(1, adj[i][j]);
	}
	vector<option>v;
	for (int k = i + 1; k < j; ++k)
	{
		for (int t = j - 1; t >= k; --t)
		{
			if (adj[i][k] == adj[t][j] && cur_ans == 2 + dp(k, t))
			{
				v.push_back(option(k, t, adj[i][k]));
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	while(v.back().c != v[0].c)
	{
		v.pop_back();
	}
	vector<string>u;
	for (int i = 0; i < v.size(); ++i)
	{
		u.push_back(solve(v[i].a, v[i].b));
	}
	sort(u.begin(), u.end());
	return string(1, v[0].c) + u[0] + string(1, v[0].c);
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		init();
		printf("%s\n", solve(0, n - 1).c_str());
	}
	return 0;
}

