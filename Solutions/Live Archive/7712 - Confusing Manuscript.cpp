#include <bits/stdc++.h>
#define MAX_N 50005
#define MAX_L 11
using namespace std;
int n;
char s[MAX_N][MAX_L];
int confusion[MAX_N];
int trie[MAX_N * MAX_L][26];
int idx[MAX_N * MAX_L];
int node_count;
inline int add_node()
{
	memset(trie[node_count], -1, sizeof trie[0]);
	idx[node_count] = -1;
	return node_count++;
}
inline void init()
{
	memset(confusion, 0, sizeof confusion);
	node_count = 0;
	add_node();
}
inline void insert(const char * s, const int _idx)
{
	int cur = 0;
	for (; *s; ++s)
	{
		int & nxt = trie[cur][(int) *s - 'a'];
		if (nxt == -1) nxt = add_node();
		cur = nxt;
	}
	idx[cur] = _idx;
}
inline int get_idx(const char * s)
{
	int cur = 0;
	for (; *s; ++s)
	{
		const int nxt = trie[cur][(int) *s - 'a'];
		if (nxt == -1) return -1;
		cur = nxt;
	}
	return idx[cur];
}


inline void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
		insert(s[i], i);
	}
}
inline void process()
{
	/*
	 * Increment both on deletion!
	 * Increment only one on replacement!
	 */
	for (int i = 0; i < n; ++i)
	{
		char * cur = s[i];
		const int l = strlen(cur);
		for (int j = 0; j < l; ++j)
		{
			// Try deletions!
			const char mem = cur[j];
			cur[j] = 0;
			const string similar_to_cur = string(cur) + string(cur + j + 1);
			const int similar_idx = get_idx(similar_to_cur.c_str());
			if (similar_idx != -1)
			{
				++confusion[i];
				++confusion[similar_idx];
			}
			cur[j] = mem;
			// Try replacements!
			for (char rep = 'a'; rep <= 'z'; ++rep)
			{
				if (rep != mem)
				{
					cur[j] = rep;
					const int similar_idx = get_idx(cur);
					if (similar_idx != -1)
					{
						++confusion[i];
					}
					cur[j] = mem;
				}
			}
		}
	}
}
int main()
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		init();
		read();
		process();
		int ans_idx = 0, ans_val = confusion[0];
		for (int i = 1; i < n; ++i)
		{
			if (confusion[i] > ans_val)
			{
				ans_val = confusion[i];
				ans_idx = i;
			}
		}
		printf("Case #%d: %s\n", tc, s[ans_idx]);
	}
	return 0;
}
/*
4
5
kuku
kaki
kaku
koko
kak
3
icpc
jakarta
regional
6
doms
poms
pod
dom
pom
doom
3
agile
cable
able
 */

