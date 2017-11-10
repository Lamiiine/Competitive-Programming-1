#include <bits/stdc++.h>
#define MAX 512
using namespace std;
typedef long long int ll;

int n;
int edge[MAX][MAX];
int dist[MAX][MAX];
int x[MAX];

inline void read()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> edge[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i]; --x[i];
	}
}
inline vector<ll> solve()
{
	vector<ll> ans;
	for (int idx = n - 1; idx >= 0; --idx)
	{
		const int v = x[idx];
		// Add node v to the graph!
		dist[v][v] = 0;
		for (int i = idx; i < n; ++i)
		{
			const int u = x[i];
			dist[u][v] = edge[u][v];
			dist[v][u] = edge[v][u];
		}
		// Rerun (some of the steps of) Floyd-Warshall
		// to compute the updated weights!
		for (int i = n - 1; i >= idx; --i)
		{
			const int u = x[i];
			for (int j = idx; j < n; ++j)
			{
				const int w = x[j];
				dist[v][w] = min(dist[v][w], dist[v][u] + dist[u][w]);
				dist[w][v] = min(dist[w][v], dist[w][u] + dist[u][v]);
			}
		}
		ll sum = 0;
		for (int i = idx; i < n; ++i)
		{
			const int u = x[i];
			for (int j = idx; j < n; ++j)
			{
				const int w = x[j];
				sum += (dist[u][w] = min(dist[u][w], dist[u][v] + dist[v][w]));
			}
		}
		ans.push_back(sum);
	}
	return ans;
}
int main()
{
	read();
	vector<ll> ans = solve();
	for (int i = ans.size() - 1; i >= 0; --i)
	{
		cout << ans[i] << (i ? " " : "");
	}
	return 0;
}

