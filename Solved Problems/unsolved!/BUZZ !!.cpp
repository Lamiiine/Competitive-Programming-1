#include<stdio.h>
#include<limits.h>
#include<set>
#include<algorithm>
#include<string.h>
#define MAX 255
#define E_MAX MAX*MAX*2
using namespace std;
int en;
int head[MAX];
int to[E_MAX];
int nxt[E_MAX];
bool art[MAX], bridge[E_MAX];	// articulation points and bridges
inline void addEdge(const int x, const int y) {
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
int p[MAX];			// region number of city i
int eng[MAX];		// energy of city i
int Eng[MAX];		// energy of region i
bool isReg[MAX];	// is city i parent of a region?
int buzz[MAX];
int n, e, b;	// cities, roads, buzzes
inline int parent(const int i) {
	return p[i] == i ? i : p[i] = parent(p[i]);
}
inline void unite(const int i, const int j) {
	p[parent(i)] = parent(j);
}
int root;
int children;
int counter;
int dfs_p[MAX];
int dfs_low[MAX];
int dfs_num[MAX];
inline void dfs(const int i) {
	dfs_low[i] = dfs_num[i] = counter++;
	for (int ind = head[i]; ind != -1; ind = nxt[ind]) {
		int j = to[ind];
		if (dfs_num[j] == -1) {
			dfs_p[j] = i;
			if (i == root)
				++children;
			dfs(j);
			if (dfs_low[j] >= dfs_num[i])
				art[i] = true;
			if (dfs_low[j] > dfs_num[i])
				bridge[ind] = bridge[ind ^ 1] = true;
			dfs_low[i] = min(dfs_low[i], dfs_low[j]);
		} else if (j != dfs_p[i])
			dfs_low[i] = min(dfs_low[i], dfs_num[j]);
	}
}
inline void init() {
	en = 0;
	memset(head, 0xFF, sizeof head);
	memset(art, 0, sizeof art);
	memset(bridge, 0, sizeof bridge);
	memset(dfs_num, 0xFF, sizeof dfs_num);
	memset(Eng, 0, sizeof Eng);
	memset(isReg, 0, sizeof isReg);
	for (int i = 0; i < MAX; ++i)
		p[i] = i;
}
bool can(int i){
	// do bipartite matching!!!!!!!!!!
}
int main() {
	freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc) {
		// CALL 'init()' AFTER READING INPUT SIZE!
		scanf("%d%d%d", &n, &e, &b);
		init();
		for (int i = 0; i < n; ++i)
			scanf("%d", eng + i);
		for (int i = 0; i < b; ++i)
			scanf("%d", buzz + i);
		for (int i = 0, x, y; i < e; ++i)
			scanf("%d%d", &x, &y), --x, --y, addEdge(x, y), addEdge(y, x);
		for (int i = 0; i < n; ++i)
			if (dfs_num[i] == -1) {
				root = i;
				counter = children = 0;
				dfs(i);
				art[i] = children > 1;
			}
		for (int i = 0; i < n; ++i)
			if (!art[i]) {
				for (int j = head[i]; j != -1; j = nxt[j])
					if (!bridge[j] && !art[to[j]])
						unite(i, to[j]);
			} else {
				int cur_end = eng[i];
				bool flag = true;
				for (int j = head[i]; j != -1; j = nxt[j]) {
					int k = to[j];
					if (!art[k] && !bridge[j])
						flag = false, eng[k] += cur_end;
				}
				isReg[i] = flag;
			}
		int x;
		for (int i = 0; i < n; ++i){
			Eng[x = parent(i)] += eng[i];
			if (!art[x]) isReg[x] = true;
		}
		int regCount = 0;
		int regEng[MAX];
		for (int i = 0; i < n; ++i)
			if (isReg[i])
				regEng[regCount++] = Eng[i];
		for (int i = 0; i < regCount; ++i)
			printf("%d\n", regEng[i]);
		printf("Buzz Mission %d: %d ", tc, regCount);
		if (b < regCount) {
			printf("No\n");
			continue;
		}
		int lo = 0, hi = 260000;
		while(lo != hi){

		}
		printf("%d\n", hi);
	}
	return 0;
}

