#include<stdio.h>
#include<list>
#include<string.h>
#include<set>
#define MAX 55
// FOR A GRAPH TO BE EULERIAN, IT ALSO HAS TO BE A SINGLE-COMPONENT GRAPH
using namespace std;
int n;
int num[MAX];
int adj[MAX][MAX];
int p[MAX];
void init(){
	for (int i = 0; i < MAX; ++i) p[i] = i;
}
int parent(int i){
	return (p[i] == i)?i:(p[i] = parent(p[i]));
}
void unite(int i, int j){
	p[parent(i)] = parent(j);
}
bool conn(){
	int x = -1;
	for (int i = 0; i < MAX; ++i)
	if (num[i])
	{
		if (x != -1 && x != (parent(i)))
			return false;
		x = parent(i);
	}
	return true;
}
bool emp(){
	for (int i = 0; i < MAX; ++i)
		if (num[i]) return false;
	return true;
}
// EULER TOUR ALGORITHM
list<int>cyc;
void euler(list<int>::iterator i, int u){
	for (int j = 0; j < MAX; ++j)
		if (adj[u][j])
		{
			--adj[u][j];
			--adj[j][u];
			euler(cyc.insert(i, u), j);
		}
}
void print(){
	list<int>::iterator iter = cyc.begin();
	while(1){
		int i = *iter;
		++iter;
		if (iter == cyc.end()) break;
		printf("%d %d\n", i, *iter);
	}
	printf("%d %d\n", *(--iter), cyc.front());
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	bool firstCase = true;
	for (int tc = 1; tc <= TC; ++tc){
		init();
		if (!firstCase) printf("\n");
		firstCase = false;
		printf("Case #%d\n", tc);
		// DON'T FORGET TO MEMSET BETWEEN CASES
		memset(num, 0, sizeof num);
		memset(adj, 0, sizeof adj);
		scanf("%d", &n);
		int x, y;
		for (int i = 0; i < n; ++i){
			scanf("%d%d", &x, &y);
			++num[x]; ++num[y];
			++adj[x][y];
			++adj[y][x];
			unite(x, y);
		}
		bool flag = true;
		for (int i = 0; i < MAX; ++i)
			if (num[i]&1) flag = false;
		if (!flag || !conn()){
			printf("some beads may be lost\n");
			continue;
		}
		x = 0;
		for (int i = 1; i < MAX && !x; ++i)
			if (num[i]) x = i;
		euler(cyc.begin(), x);
		print();
		cyc.clear();
	}
	return 0;
}
