#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
map<vector<int>, int> dist;
inline int get_dist(const vector<int> & v)
{
	map<vector<int>, int>::iterator iter = dist.find(v);
	if (iter != dist.end())
	{
		return iter->second;
	}
	return dist[v] = INF;
}
typedef pair<int, vector<int>> iv;
bool prime[16] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0};
inline bool can_dance(const int i, const int j)
{
	return ((i > 0) != (j > 0)) && prime[abs(i) + abs(j)];
}
inline void dij(const vector<int> & init)
{
	priority_queue<iv> q;
	q.push(iv(0, init));
	dist[init] = 0;
	while(!q.empty())
	{
		const vector<int> v = q.top().second;
		const int cur_dist = -q.top().first;
		q.pop();
		if (get_dist(v) < cur_dist)
		{
			continue;
		}
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				const int a = v[i], b = v[j];
				if (can_dance(a, b))
				{
					// j should go to left and right of i
					if (i < j)
					{
						vector<int> u = v;
						for (int k = j; k > i; --k)
						{
							u[k] = v[k - 1];
						}
						u[i] = v[j];
						// we have a u
						if (get_dist(u) > cur_dist + 1)
						{
							q.push(iv(-(dist[u] = cur_dist + 1), u));
						}
						swap(u[i], u[i + 1]);
						// we have a u
						if (get_dist(u) > cur_dist + 1)
						{
							q.push(iv(-(dist[u] = cur_dist + 1), u));
						}
					}
					else
					{
						vector<int> u = v;
						for (int k = j; k < i; ++k)
						{
							u[k] = v[k + 1];
						}
						u[i] = v[j];
						// we have a u
						if (get_dist(u) > cur_dist + 1)
						{
							q.push(iv(-(dist[u] = cur_dist + 1), u));
						}
						swap(u[i], u[i - 1]);
						// we have a u
						if (get_dist(u) > cur_dist + 1)
						{
							q.push(iv(-(dist[u] = cur_dist + 1), u));
						}
					}
				}
			}
		}
	}
}
inline bool cmp(const int i, const int j)
{
	return abs(i) < abs(j);
}
int main(void)
{
	vector<int> v;
	v.resize(8);
	for(int tc = 1; scanf("%d", &v[0]), v[0]; ++tc)
	{
		// read
		for (int i = 1; i < 8; ++i)
		{
			scanf("%d", &v[i]);
		}
		// init
		dist.clear();
		dij(v);
		sort(v.begin(), v.end(), cmp);
		const int ans = get_dist(v);
		printf("Case %d: %d\n", tc, ans == INF ? -1 : ans);
	}
	return 0;
}

