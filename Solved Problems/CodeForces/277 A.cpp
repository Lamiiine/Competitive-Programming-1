#include<stdio.h>
#include<set>
#include<vector>
#define MAX 105
using namespace std;
int p[MAX];
inline int parent(int i){
	return (p[i] == i)?i:p[i] = parent(p[i]);
}
inline void unite(const int i,const int j){
	p[parent(i)] = parent(j);
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) p[i] = i;
	vector<int> v[MAX];	// employees speaking language i
	int x, y;
	bool found = false;
	for (int i = 0; i < n; ++i){
		scanf("%d", &x);
		while(x--){
			scanf("%d", &y);
			v[y].push_back(i);
			found = true;
		}
	}
	// NO EMPLOYEE KNOWS ANY LANGUAGE IS A CORNER CASE!!
	for (int i = 1; i <= m; ++i)
	{
		// CONTINUE IF VECTOR IS EMPTY
		if (v[i].empty()) continue;
		int prev = *v[i].begin();
		for (auto iter = v[i].begin(); iter != v[i].end(); ++iter)
		unite(prev, *iter);
	}
	set<int> s;
	for (int i = 0; i < n; ++i) s.insert(parent(i));
	printf("%d", s.size()-found);	// TO GET NUMBER OF COMPONENTS, SUBTRACT 1
	return 0;
}