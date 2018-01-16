#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
string arr[MAX];
char s[MAX];
int n;

int trie[MAX * 5][26];
int idx[MAX * 5];
int sz[MAX * 5];
bool is_end[MAX * 5];
int node_count;
int counter;
inline void dfs(int i)
{
	int & my_size = sz[i];
	my_size = 0;
	if (is_end[i])
	{
		my_size = 1;
		idx[i] = counter++;
	}
	for (int j = 0; j < 26; ++j)
		if (trie[i][j] != -1)
		{
			dfs(trie[i][j]);
			my_size += sz[trie[i][j]];
		}
}

inline int get_index(const char * c)
{
	int cur = 0;
	for (;*c; ++c)
		cur = trie[cur][*c - 'a'];
	return idx[cur];
}
inline int add_node()
{
	memset(trie[node_count], -1, sizeof trie[0]);
	is_end[node_count] = false;
	return node_count++;
}
inline void insert(char * c)
{
	int cur = 0;
	for (;*c; ++c)
	{
		int & nxt = trie[cur][*c - 'a'];
		if (nxt == -1) nxt = add_node();
		cur = nxt;
	}
	is_end[cur] = true;
}
inline void init()
{
	node_count = 0;
	add_node();
	counter = 0;
	for (int i = 0; i < MAX; ++i)
		arr[i] = "";
}

int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s);
			insert(s);
			arr[i] = s;
		}
		dfs(0);
		for (int i = 0; i < n; ++i)
		{
			const string & cur = arr[i];
			int cur_node = 0;
			int cur_depth = 0;
			int cur_sz = n;
			int cur_idx = get_index(cur.c_str());
			int ans = INT_MAX;

			ans = min(ans, 1 + cur_depth + min(cur_idx, cur_sz - cur_idx));
			for (const char * c = cur.c_str(); *c; ++c)
			{
				for (char d = 'a'; d < *c; ++d)
					if (trie[cur_node][d - 'a'] != -1)
						cur_idx -= sz[trie[cur_node][d - 'a']];
				cur_idx -= is_end[cur_node];

				cur_node = trie[cur_node][*c - 'a'];
				++cur_depth;
				cur_sz = sz[cur_node];
				ans = min(ans, 1 + cur_depth + min(cur_idx, cur_sz - cur_idx));
			}
			printf("%d%c", ans, (i == n - 1) ? '\n' : ' ');
		}
	}
	return 0;
}
