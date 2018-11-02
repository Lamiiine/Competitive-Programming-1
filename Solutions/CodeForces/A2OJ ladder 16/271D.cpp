#include <bits/stdc++.h>
#define MAX 1505
#define SZ (MAX * MAX / 2)
using namespace std;
char s[MAX];
char good[27];
int trie[SZ][26];
int is_end[SZ];
int node_count;
int k;
inline int add_node()
{
	memset(trie[node_count], -1, sizeof trie[0]);
	is_end[node_count] = false;
	return node_count++;
}
int ans = 0;
inline void insert(const char * s)
{
	int cur = 0, bad_count = 0;
	for (; *s && bad_count <= k; ++s)
	{
		bad_count += !good[*s - 'a'];
		int & nxt = trie[cur][(int)(*s - 'a')];
		if (nxt == -1) nxt = add_node(), ans += (bad_count <= k);
		cur = nxt;
	}
	is_end[cur] = true;
}
inline void init()
{
	node_count = 0;
	add_node();
}
inline void read()
{
	scanf("%s%s%d", s, good, &k);
}
inline void preprocess()
{
	for (int i = 0; i < 26; ++i)
	{
		good[i] -= '0';
	}
	for (const char * c = s; *c; ++c)
	{
		insert(c);
	}
}
int main()
{
	init();
	read();
	preprocess();
	printf("%d", ans);
	return 0;
}

