#include <bits/stdc++.h>
#define MAX 100100
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
struct single_prime_edge
{
	int x, y, p;
	single_prime_edge(
			const int _x,
			const int _y,
			const int _p):
				x(_x), y(_y), p(_p) {}
};

vector<int> primes;
vector<single_prime_edge> spe;
int n;
int head[MAX], to[MAX * 2], nxt[MAX * 2], cost[MAX * 2], en;
int p[MAX], sz[MAX];

inline int parent(const int i)
{
	return (p[i] == i) ? i : (p[i] = parent(p[i]));
}
inline int get_sz(const int i)
{
	return sz[parent(i)];
}
inline void unite(const int i, const int j)
{
	const int I = parent(i), J = parent(j);
	if (I != J)
	{
		p[I] = J;
		sz[J] += sz[I];
	}
}
inline void init()
{
	memset(head, -1, sizeof head); en = 0;
	for (int i = 0; i < MAX; ++i)
	{
		p[i] = i;
		sz[i] = 1;
	}
	spe.clear();
}

inline void sieve()
{
	const int upper_bound = 1000;
	primes.reserve(upper_bound / log(upper_bound));
	bitset<upper_bound + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
	{
		if (bs[i])
		{
			primes.push_back(i);
			for (int j = i * i; j <= upper_bound; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}
inline vector<int> factorize(int x)
{
	vector<int> ans;
	for (int i = 0, p = primes[0]; p * p <= x && ans.size() < 3; p = primes[++i])
	{
		while (x % p == 0)
		{
			ans.push_back(p);
			x /= p;
		}
	}
	if (x != 1)
	{
		ans.push_back(x);
	}
	return ans;
}
inline void add_edge(const int i, const int j, const int k)
{
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	cost[en] = k;
	++en;
}
inline void add_bi_edge(const int i, const int j, const int k)
{
	add_edge(i, j, k); add_edge(j, i, k);
}
inline ll read()
{
	cin >> n;
	vector<ii> dpe;	// my double prime edges!
	for (int i = 1, x, y, w; i < n; ++i)
	{
		cin >> x >> y >> w;
		if (w == 1)
		{
			unite(x, y);
		}
		else
		{
			vector<int> factors = factorize(w);
			if (factors.size() == 1)
			{
				spe.push_back(single_prime_edge(x, y, factors[0]));
			}
			else if (factors.size() == 2 && factors[0] != factors[1])
			{
				dpe.push_back(ii(x, y));
			}
			// else if (factors.size() >= 3);
		}
	}
	ll ans = 0LL;
	// add effect of double-prime-edges!
	for (int i = 0; i < dpe.size(); ++i)
	{
		const ii & cur = dpe[i];
		ans += 1LL * get_sz(cur.first) * (ll) get_sz(cur.second);
	}
	return ans;
}

inline ll solve()
{
	ll ans = 0LL;
	// add effect of single-prime-edges!
	for (int i = 0; i < spe.size(); ++i)
	{
		const single_prime_edge & cur = spe[i];
		add_bi_edge(parent(cur.x), parent(cur.y), cur.p);
	}
	for (int v = 1; v <= n; ++v)
	{
		if (v != p[v]) continue;
		vector<ii> neighbors;
		int tot_neighbors_size = 0;
		for (int j = head[v]; ~j; j = nxt[j])
		{
			neighbors.push_back(ii(cost[j], to[j]));
			tot_neighbors_size += get_sz(to[j]);
		}
		sort(neighbors.begin(), neighbors.end());
		for (int i = 0; i < neighbors.size(); )
		{
			int cur_neighbors_size = 0;
			for(const int p = neighbors[i].first;
					i < neighbors.size() && neighbors[i].first == p; ++i)
			{
				cur_neighbors_size += get_sz(neighbors[i].second);
			}
			ans += (ll) 1LL * cur_neighbors_size * (ll) (tot_neighbors_size -= cur_neighbors_size);
		}
	}
	return ans;
}
int main()
{
	freopen("evaluations.in", "r", stdin);
	sieve();
	int TC; cin >> TC;
	for (int tc = 1; tc <= TC; ++tc)
	{
		init();
		ll ans = read();
		cout << "Case " << tc << ": " << ans + solve() << endl;
	}
	return 0;
}
/*
2
5
1 2 2
2 3 1
1 4 3
1 5 6
12
1 2 1
2 12 7
1 3 1
1 4 15
4 5 1
5 6 1
6 7 1
2 8 3
8 9 1
9 10 5
10 11 3
 */

