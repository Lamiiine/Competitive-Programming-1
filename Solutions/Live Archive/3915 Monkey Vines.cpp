#include<bits/stdc++.h>
#define MAX 200
using namespace std;
vector<int>adj[MAX];
char s[MAX];
inline void init(void){
	for (int i = 0; i < MAX; ++i) adj[i].clear();
}
int p[MAX];
inline void parse(void){
	int cur = 0, counter = 0;
	for (int i = 0; s[i]; ++i)
		if (s[i] == '[')
		{
			++counter;	// new node
			adj[cur].push_back(counter);
			p[counter] = cur;
			cur = counter;
		}
		else {
			cur = p[cur];
		}
}
/*
3
[]

[[][[]]]
*/
inline int weight(int i){
	vector<int> & v = adj[i];
	if (v.empty()) return 2;
	if (v.size() == 1)
		return 2*weight(v[0]);
	if (v.size() == 2)
		return 2*max(weight(v[0]), weight(v[1]));
	return 0;
}
int main(void){
	int TC;
	fgets(s, INT_MAX, stdin);
	sscanf(s, "%d", &TC);
	for(int tc = 1; tc <= TC; ++tc){
		fgets(s, INT_MAX, stdin); s[strlen(s) - 1] = 0;
		init();
		parse();
		int ans;
		if (adj[0].empty()) ans = 1;
		else ans = weight(adj[0][0]);
		printf("%d %d\n", tc, ans);
	}
}

