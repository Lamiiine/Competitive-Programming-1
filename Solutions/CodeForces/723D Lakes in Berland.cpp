#include<bits/stdc++.h>
#define MAX 55
using namespace std;
int n, m, k;
char s[MAX][MAX];
const int di[4] = {1, -1, 0, 0},
		dj[4] = {0, 0, 1, -1};
int id[MAX][MAX];
bool valid[MAX * MAX];
int sz[MAX * MAX];
inline void dfs(const int i, const int j, const int my_id)
{
	id[i][j] = my_id;
	for (int k = 0; k < 4; ++k)
	{
		const int x = i + di[k], y = j + dj[k];
		if (x < 0 || x >= n || y < 0 || y >= m)
			valid[my_id] = 0;
		else if (s[x][y] == '.' && id[x][y] == -1)
			dfs(x, y, my_id);
	}
}

int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
#endif
	memset(id, -1, sizeof id);
	memset(valid, 1, sizeof valid);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	int counter = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '.' && id[i][j] == -1)
				dfs(i, j, counter++);
	memset(sz, 0, sizeof sz);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			++sz[id[i][j]];

	typedef pair<int, int> ii;
	vector<ii> v;
	for (int i = 0; i < counter; ++i)
		if (valid[i])
			v.push_back(ii(sz[i], i));
	sort(v.begin(), v.end());
	int ans = 0;
	const int num = v.size() - k;
	for (int c = 0; c < num; ++c)
	{
		ans += v[c].first;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (id[i][j] == v[c].second)
					s[i][j] = '*';
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i)
		printf("%s\n", s[i]);
	return 0;
}

