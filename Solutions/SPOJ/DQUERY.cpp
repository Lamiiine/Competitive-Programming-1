#include <bits/stdc++.h>
#define MAX_N 30005
#define MAX_Q 200005
#define MAX_A 1000005
using namespace std;
int _sqrt;
struct query{
	int s, e, idx;
	bool operator < (const query & other) const
	{
		return make_pair(s/ _sqrt, e) < make_pair(other.s/_sqrt, other.e);
	}
};
query queries[MAX_Q];
int s = 0, e = -1;
int n, q;
int arr[MAX_N];
int freq[MAX_A] = { 0 }, counter = 0;
int ans[MAX_Q];

inline void add(const int v)
{
	if (!freq[v]++)
		++counter;
}
inline void remove(const int v)
{
	if (!--freq[v])
		--counter;
}
inline void read(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
	}
	scanf("%d", &q);
	for (int i = 0, a, b; i < q; ++i)
	{
		scanf("%d%d", &a, &b); --a, --b;
		queries[i] = query{a, b, i};
	}
}
inline void update_window(const int qs, const int qe)
{
	while (e < qe)
	{
		add(arr[++e]);
	}
	while (e > qe)
	{
		remove(arr[e--]);
	}
	while (s < qs)
	{
		remove(arr[s++]);
	}
	while (s > qs)
	{
		add(arr[--s]);
	}
}

int main()
{
	read();
	::_sqrt = sqrt(n);
	sort(queries, queries + q);
	for (int i = 0; i < q; ++i)
	{
		update_window(queries[i].s, queries[i].e);
		ans[queries[i].idx] = counter;
	}
	for (int i = 0; i < q; ++i)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}

