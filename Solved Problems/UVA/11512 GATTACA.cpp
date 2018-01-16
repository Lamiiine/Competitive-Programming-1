#include<bits/stdc++.h>
using namespace std;
const char c[4] = {'A', 'C', 'G', 'T'};
map<char, int>m;
map<int, char>M;
inline void init_m(void){
	for (int i = 0; i < 4; ++i)
		m[c[i]] = i, M[i] = c[i];
}
int trie[501000][4];
int rep_count[501000];
int depth[501000];
int p[501000];
int node_count;
inline int add_node(void){
	memset(trie[node_count], 0xFF, sizeof trie[0]);
	return node_count++;
}
inline void init_trie(void){
	node_count = 0;
	add_node();
}
inline void insert(const char * str){
	int cur = 0;
	for (int i = 1;*str; ++str, ++i){
		int & nxt = trie[cur][m[*str]];
		if (nxt == -1) {
			nxt = add_node();
			p[nxt] = cur;
			rep_count[nxt] = 1;
		}
		else ++rep_count[nxt];
		depth[nxt] = i;
		cur = nxt;
	}
}
char s[1010];
inline void print(const int i){
	if (i){
		const int my_parent = p[i];
		print(my_parent);
		for (int j = 0; j < 4; ++j)
			if (trie[my_parent][j] == i){printf("%c", M[j]); break;}
	}
}
int ans, ans_index;
inline void traverse(const int i){
	if (i == -1) return;
	if (rep_count[i] > 1 && depth[i] > ans){
		ans = depth[i]; ans_index = i;
	}
	for (int j = 0; j < 4; ++j)
		traverse(trie[i][j]);
}
int main(void){
	init_m();
	int TC; scanf("%d", &TC);
	while(TC--){
		init_trie();
		scanf("%s", s);
		for (const char * c = s; *c; ++c) insert(c);
		ans = 0;
		traverse(0);
		if (!ans) printf("No repetitions found!\n");
		else {
			print(ans_index);
			printf(" %d\n", rep_count[ans_index]);
		}
	}
	return 0;
}

