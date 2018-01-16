#include<bits/stdc++.h>
using namespace std;
int trie[45000][128];
int node_count;
inline int add_node(void){
	memset(trie[node_count], 0xFF, sizeof trie[0]);
	return node_count++;
}
inline void init(void){
	node_count = 0;
	add_node();
}
inline void insert(const char * str){
	int cur = 0;
	for (; *str; ++str){
		int & nxt = trie[cur][(int)*str];
		if (nxt == -1) nxt = add_node();
		cur = nxt;
	}
}
char a[310], b[310];
int get_len(const int i, const int j){
	// starting at node i in the trie, j in b
	if (!b[j]) return 0;
	int nxt = trie[i][b[j]];
	if (nxt == -1) return 0;
	return 1 + get_len(nxt, j + 1);
}
int ans;
struct cmp{
	bool operator ()(const int i, const int j){
		return memcmp(b + i, b + j, ans) < 0;
	}
};
inline bool empty(const char * str){
	for (;*str; ++str)
		if (!isspace(*str)) return false;
	return true;
}
int main(void){
	bool first = true;
	while(true){
		*a = *b = 0;
		if (!first) {
			fgets(a, INT_MAX, stdin);
		}
		init();
		fgets(a, INT_MAX, stdin);
		if (empty(a)) break;
		if (!first) printf("\n");
		first = false;
		a[strlen(a) - 1] = 0;
		fgets(b, INT_MAX, stdin);
		b[strlen(b) - 1] = 0;
		// insert all of a in the trie
		for (const char * str = a; *str; ++str)
			insert(str);
		ans = 0;
		for (int i = 0; b[i]; ++i)
			ans = max(ans, get_len(0, i));
		if (!ans){
			printf("No common sequence.\n");
			continue;
		}
		set<int, cmp>v;
		for (int i = 0; b[i]; ++i)
			if (get_len(0, i) == ans) v.insert(i);
		for (set<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			char & cur = b[*iter + ans];
			const char temp = cur;
			cur = 0;
			printf("%s\n", b + *iter);
			cur = temp;
		}
	}
	return 0;
}

