	#include<bits/stdc++.h>
#define MAX 7
using namespace std;
const int INF = 1e9;
int m, k;
int mixture[MAX][MAX];
int heat[MAX][MAX];
map<int, int> M;
inline vector<int>decompose(int a)
{
	vector<int>ans;
	while(a != 1LL)
	{
		ans.push_back(a & 7);
		a >>= 3;
	}
	sort(ans.begin(), ans.end());
	return ans;
}
inline int compose(vector<int> &v)
{
	int ans = 1;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		ans = (ans << 3) | v[i];
	}
	return ans;
}
inline int dp(const int a)
{
	if (M.find(a) != M.end()) return M[a];
	vector<int> v = decompose(a);
	if (v.size() <= 1)
	{
		return M[a] = 0;
	}
	int ans = INF;
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = i + 1; j < v.size(); ++j)
		{
			vector<int> to;
			for (int k = 0; k < v.size(); ++k)
			{
				if (k != i && k != j)
				{
					to.push_back(v[k]);
				}
			}
			to.push_back(mixture[v[i]][v[j]]);
			ans = min(ans, heat[v[i]][v[j]] + dp(compose(to)));
		}
	}
	return M[a] = ans;
}
inline void read_table(void)
{
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d%d", mixture[i] + j, heat[i] + j);
			--mixture[i][j];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			heat[i][j] = heat[j][i] = max(heat[i][j], heat[j][i]);
		}
	}
}
inline vector<int> read_chemicals(void)
{
	vector<int>ans;
	scanf("%d", &k);
	ans.resize(k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &ans[i]);
	}
	char s[5];
	scanf("%s", s);
	for (int i = 0; i < k; ++i)
		--ans[i];
	return ans;
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read_table();
		M.clear();
		vector<int>v = read_chemicals();
		printf("%d\n", dp(compose(v)));
	}
	return 0;
}

