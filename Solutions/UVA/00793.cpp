#include <stdio.h>
#include<iostream>
#include<string>
#include <stdlib.h>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;
vector<int>p;
inline int find(int i){
	return(p[i] == i)?i:p[i] = find(p[i]);
}
inline void unite(int x, int y){
	p[find(x)] = find(y);
}
inline bool query(int x, int y){
	return find(x) == find(y);
}
int main() {
	int TC;
	int n;
	scanf("%d", &TC);
	size_t len = 200;
	bool firstCase = true;
	while(TC--){
		if (!firstCase) printf("\n");
		firstCase = false;
		scanf("%d", &n);
		p.resize(n+1);
		for (int i = 1; i <= n; ++i) p[i] = i;
		char c;
		int x, y;
		string line;
		int ans[2] = {};
		cin.ignore();
		while(getline(cin, line), line != ""){
			sscanf(line.c_str(), "%c%d%d", &c, &x, &y);
			if (c == 'c') unite(x, y);
			else ans[query(x, y)]++;
		}
		printf("%d,%d\n", ans[1], ans[0]);
	}
	return 0;
}