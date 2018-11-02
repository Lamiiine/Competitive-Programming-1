#include <bits/stdc++.h>
#define MAX 100100
#define LSOne(s) ((s) & (-s))
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
struct operation
{
	ll l, r, d;
	operation(const ll _l, const ll _r, const ll _d)
	{
		l = _l;
		r = _r;
		d = _d;
	}
	operation(){l = r = d = 0LL; }
};

int n, m, k;
ll arr[MAX];
ll arr_adds[MAX] = { 0 };
operation operations[MAX];
ll operation_repition[MAX] = { 0 };
ii queries[MAX];

inline void read()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0, l, r, d; i < m; ++i)
	{
		cin >> l >> r >> d; --l; --r;
		operations[i] = operation(l, r, d);
	}
	for (int i = 0, x, y; i < k; ++i)
	{
		cin >> x >> y; --x; --y;
		queries[i] = ii(x, y);
	}
}
inline void process_operation_repitions()
{
	for (int i = 0; i < k; ++i)
	{
		const ii & query = queries[i];
		++operation_repition[query.first];
		--operation_repition[query.second + 1];
	}
	for (int i = 1; i < m; ++i)
	{
		operation_repition[i] += operation_repition[i - 1];
	}
	for (int i = 0; i < m; ++i)
	{
		operations[i].d *= operation_repition[i];
	}
}
inline void process_arr_adds()
{
	for (int i = 0; i < m; ++i)
	{
		const operation & cur = operations[i];
		arr_adds[cur.l] += cur.d;
		arr_adds[cur.r + 1] -= cur.d;
	}
	for (int i = 1; i < n; ++i)
	{
		arr_adds[i] += arr_adds[i - 1];
	}
	for (int i = 0; i < n; ++i)
	{
		arr[i] += arr_adds[i];
	}
}
inline void print()
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << (i == n ? "" : " ");
	}
}
int main()
{
	read();
	process_operation_repitions();
	process_arr_adds();
	print();
}
/*
3 3 3
1 2 3
1 2 1
1 3 2
2 3 4
1 2
1 3
2 3

1 1 1
1
1 1 1
1 1

4 3 6
1 2 3 4
1 2 1
2 3 2
3 4 4
1 2
1 3
2 3
1 2
1 3
2 3
 */
