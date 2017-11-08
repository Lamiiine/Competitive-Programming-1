/*
 * What can you do to optimize the code of this problem?
 * - use a trie instead of a map to store words!
 * - find your neighbors, not by looping over the whole array, but by manually replacing characters
 */
#include<bits/stdc++.h>
#define MAX 20010
using namespace std;
int n;
string arr[MAX];
int p[MAX];
map<string, int> idx;
inline void init_p(void)
{
	for (int i = 0; i < MAX; ++i)
		p[i] = i;
}
inline int get_p(const int i)
{
	return p[i] == i ? i : p[i] = get_p(p[i]);
}
inline bool same(const int i, const int j)
{
	return get_p(i) == get_p(j);
}
inline void read(void)
{
	string temp;
	for (n = 0; getline(cin, temp), strcmp(temp.c_str(), "--"); ++n)
		idx[arr[n] = temp] = n;
}
inline void unite(const int i, const int j)
{
	p[get_p(i)] = get_p(j);
}
inline bool neighbors(const string & a, const string & b)
{
	if (a.length() != b.length()) return false;
	int ans = 0;
	for (int i = 0; i < a.length(); ++i)
		if (a[i] != b[i])
			if (++ans >= 2) return false;
	return true;
}
inline void combine(void)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (neighbors(arr[i], arr[j]))
				unite(i, j);
}
inline void solve(void)
{
	for (string a, b; cin >> a >> b; )
		printf("%s\n", idx.find(a) != idx.end() && idx.find(b) != idx.end() && same(idx[a], idx[b]) ? "Yes" : "No");
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	read();
	init_p();
	combine();
	solve();
	return 0;
}

