#include <bits/stdc++.h>
#define MAX 2002
#define SZ (MAX * MAX / 2)
using namespace std;
char s[MAX];
char s_begin[MAX], s_end[MAX];	// My pattern is s_end!
int trie[SZ][26];
int node_count;
int f[MAX];
int l;
inline int get_f(int i, const char c)
{
	while (i && c != s_end[i])
		i = f[i - 1];
	if (c == s_end[i])
		++i;
	return i;
}
inline int add_node()
{
	memset(trie[node_count], -1, sizeof trie[0]);
	return node_count++;
}
inline void insert(const char * s)
{
	int cur = 0;
	for (; *s; ++s)
	{
		int & nxt = trie[cur][(int)(*s - 'a')];
		if (nxt == -1) nxt = add_node();
		cur = nxt;
	}
}
inline void init()
{
	node_count = 0;
	add_node();
}
inline void read()
{
	scanf("%s%s%s", s, s_begin, s_end);
	l = strlen(s_end);
}
inline void preprocess()
{
	// Build Trie!
	for (const char * c = s; *c; ++c)
	{
		insert(c);
	}
	// Build KMP!
	f[0] = 0;
	for (int i = 1; i < l; ++i)
		f[i] = get_f(f[i - 1], s_end[i]);
}
int ans = 0;
inline void dfs(const int i, const int cur)
{
	if (cur == l) ++ans;
	for (int j = 0; j < 26; ++j)
	{
		const int nxt = trie[i][j];
		if (nxt != -1)
		{
			dfs(nxt, get_f(cur, j + 'a'));
		}
	}
}
inline int solve()
{
	int i = 0, cur = 0;
	for (char * c = s_begin; *c && i != -1; ++c)
		i = trie[i][*c - 'a'], cur = get_f(cur, *c);
	if (i == -1) return 0;
	dfs(i, cur);
	return ans;
}
int main()
{
	init();
	read();
	preprocess();
	printf("%d", solve());
	return 0;
}

