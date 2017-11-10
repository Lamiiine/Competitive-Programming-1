#include <bits/stdc++.h>
#define MAX 100005
#define OO 1000000001
using namespace std;
typedef pair<int, int> ii;
ii s, e;
map<int, vector<ii>> allowed;
map<ii, int> dist;
const int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0},
		dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};
inline bool is_allowed(const int r, const int c)
{
	const vector<ii> & v = allowed[r];
	if (v.empty()) return false;
	const int idx = upper_bound(v.begin(), v.end(), ii(c, OO)) - v.begin() - 1;
	return c >= v[idx].first && c <= v[idx].second;
}
inline void bfs(const ii s)
{
	queue<ii> q;
	q.push(s);
	dist[s] = 0;
	while(!q.empty())
	{
		const ii i = q.front(); q.pop();
		const int cur_dist = dist[i] + 1;
		for (int j = 0; j < 8; ++j)
		{
			const ii k = ii(i.first + dx[j], i.second + dy[j]);
			if (is_allowed(k.first, k.second) && dist.find(k) == dist.end())
			{
				q.push(k);
				dist[k] = cur_dist;
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d", &s.first, &s.second, &e.first, &e.second);
	int n; scanf("%d", &n);
	for(int r, a, b; n--; )
	{
		scanf("%d%d%d", &r, &a, &b);
		if (allowed.find(r) == allowed.end())
		{
			allowed[r];
		}
		allowed[r].push_back(ii(a, b));
	}
	for (auto iter = allowed.begin(); iter != allowed.end(); ++iter)
	{
		vector<ii> & v = iter->second;
		sort(v.begin(), v.end());
		int counter = 0;
		for (int i = 1; i < v.size(); ++i)
		{
			if (v[i].first <= v[counter].second + 1)
			{
				v[counter] = ii(v[counter].first, max(v[counter].second, v[i].second));
			}
			else
			{
				v[++counter] = v[i];
			}
		}
		++counter;
		while(v.size() > counter) v.pop_back();
	}
	bfs(s);
	if (dist.find(e) == dist.end())
	{
		printf("-1");
	}
	else
	{
		printf("%d", dist[e]);
	}
	return 0;
}

