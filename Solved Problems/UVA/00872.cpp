// Print all topological sorts!
#include <iostream>
#include<string.h>
#include <stdio.h>
#include<string>
#include <stack>
#define MAX 26
using namespace std;
int adj[MAX];	// stores prerequisites of i
char s[MAX << 1];
int used;
bool flag;
int n;
inline void init(){
	memset(adj, 0, sizeof adj);
	memset(s, 0, sizeof s);
	n = used = 0;
	flag = false;
}
inline void dfs(const int i){
	int vis = 0;
	stack<int>s;
	s.push(i); vis |= 1 << i;
	while(!s.empty()){
		int u = s.top(); s.pop();
		int a = adj[u];
		for (int j = 0; j < MAX; ++j) {
			int cur = 1 << j;
			if ((used & cur) && !(vis & cur) && (a & cur)) adj[i] |= cur, vis |= cur, s.push(j);
		}
	}
}
inline void recurse(int i, int m){
	if (m == n) { s[strlen(s) - 1] = '\n'; printf("%s", s); flag = true;}
	else
	for (int j = 0; j < 26; ++j)
	{
		int temp = 1 << j;
		if ((used & temp) && !(i&temp) && !(adj[j] & ~i)) s[m << 1] = j + 'A', s[(m << 1) + 1] = ' ', recurse(i | temp, m + 1);
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	bool first = true;
	while(TC--){
		if (!first) printf("\n");
		first = false;
		init();
		string temp;
		while(getline(cin, temp), temp == "");
		for (int i = 0; i < temp.length(); ++i){
			char c = temp[i];
			if (c != ' ') used |= 1 << (c-'A'), ++n;
		}
		getline(cin, temp);
		for (int i = 0; i < temp.length();){
			char c = temp[i] - 'A', d = temp[i + 1], e = temp[i+2] - 'A';
			if (d == '<') adj[e] |= 1 << c;
			else adj[c] |= 1 << c;
			i += 3;
			while(temp[i] == ' ') ++i;
		}
		for (int i = 0; i < MAX; ++i) if (used & (1 << i)) dfs(i);
		recurse(0, 0);
		if (!flag) printf("NO\n");
	}
	return 0;
}

