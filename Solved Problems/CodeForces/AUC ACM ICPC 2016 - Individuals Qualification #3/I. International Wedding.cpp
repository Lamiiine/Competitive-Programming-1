#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, x, y;
ll arr[6][202];
vector<ll> v, u;
inline void read(void)
{
	cin >> n >> x >> y;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}
}
inline void init_v(void)
{
	v.clear();
	u.clear();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				ll val = arr[0][i] + arr[1][j] + arr[2][k];
				if (val <= y)
				{
					v.push_back(val);
				}

				val = arr[3][i] + arr[4][j] + arr[5][k];
				if (val <= y)
				{
					u.push_back(val);
				}
			}
		}
	}

	sort(v.begin(), v.end());
	sort(u.begin(), u.end());
}
inline ll solve(void)
{
	ll ans = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		ans += upper_bound(u.begin(), u.end(), y - v[i]) - lower_bound(u.begin(), u.end(), x - v[i]);
	}

	return ans;
}
int main(void)
{
	freopen("international.in", "r", stdin);
	int TC; cin >> TC;
	while(TC--)
	{
		read();
		init_v();
		cout << solve() << '\n';
	}
	return 0;
}

