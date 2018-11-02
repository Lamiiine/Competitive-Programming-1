#include<stdio.h>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<map>
#define MAX 125
using namespace std;
int n, r;
set<int> p[MAX];
void clean(){
	for (int i = 0; i < n; ++i)	// for all classes i
	for (auto j : p[i]){		// for all prerequisites j of i
		queue<int>q;
		for (auto k : p[j])
			q.push(k);			// for all prerequisistes k of j, remove them from prerequisites of i
		while (!q.empty()){
			int u = q.front();
			q.pop();
			p[i].erase(u);
			for (auto l : p[u])q.push(l);
		}
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--){
		map<string, int>m;
		map<int, string> M;
		scanf("%d", &n);
		char s[25];
		for (int i = 0; i < n; ++i){
			scanf("%s", s);
			m[s] = i;
			M[i] = s;
		}
		scanf("%d", &r);
		int x, y;
		set<string> need;
		for (int i = 0; i < r; ++i){
			scanf("%s", s);
			y = m[s];
			scanf("%d", &x);
			need.insert(s);
			while (x--){
				scanf("%s", s);
				p[y].insert(m[s]);
			}
		}
		clean();
		for (auto iter = need.begin(); iter != need.end(); ++iter){
			y = m[*iter];
			printf("%s", iter->c_str());
			printf(" %d", p[y].size());
			set<string> pre;
			for (auto i : p[y])pre.insert(M[i]);
			for (auto i :pre) printf(" %s", i.c_str());
			printf("\n");
		}
		for (int i = 0; i < n; ++i) p[i].clear();
	}
	return 0;
}