#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
#define N 105		// max number of categories (base for problems)
#define M 1005		// max number of problems
#define MAX 1110	// N + M
using namespace std;
int head[N], nxt[N * M], to[N * M], en;
void addEdge(int x, int y) {
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}

int n, m;
int cat[N];	// val[i] = category of problem i
int counter;
int p[MAX];
int match[MAX];
void aug(int i) {
	for (int j; i != -1; i = p[j]) {
		j = p[i];
		match[i] = j;
		match[j] = i;
	}
}
void init(void) {
	en = counter = 0;
	memset(head, 0xFF, sizeof head);
	memset(match, 0xFF, sizeof match);
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	// numbers of categories and problems respectively
	while (scanf("%d%d", &n, &m), n || m) {
		int start[N];
		int end[N];
		init();
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			start[i] = counter;
			for (int j = 0; j < x; ++j)
				cat[counter++] = i;	// 1-based!!
			end[i] = counter;
		}
		for (int i = 0; i < m; ++i) {
			int x;
			scanf("%d", &x);
			while (x--) {
				int y;
				scanf("%d", &y);
				--y;
				int s = start[y], e = end[y];
				for (int j = s; j < e; ++j)
					addEdge(j, N + i);
			}
		}
		memset(p, 0xFF, sizeof p);
		bool flag = true;
		vector<int> vec;
		while (flag) {
			flag = false;
			// loop over all categories
			for (int i = 0; i < counter; ++i) {
				if (match[i] != -1)
					continue;
				vec.push_back(i);
				while (!vec.empty()) {
					int v = vec.back();
					vec.pop_back();
					for (int j = head[v]; j != -1; j = nxt[j]) {
						int u = to[j];
						int w = match[u];
						if (u == v)
							continue;
						if (w == -1) {
							flag = true;
							p[u] = v;
							aug(u);
							vec.clear();
							memset(p, 0xFF, sizeof p);
							break;
						} else if (p[u] == -1) {
							p[u] = v;
							p[w] = u;
							vec.push_back(w);
						}
					}
				}
			}
		}
		flag = true;
		for (int i = 0; i < counter && flag; ++i)
			if (match[i] == -1)
				flag = false;
		if (!flag)
			printf("0\n");
		else {
			printf("1\n");
			set<int> z[22];
			for (int i = N; i < N + m; ++i) {
				int x = match[i];
				if (x == -1)
					continue;
				x = cat[x];
				z[x].insert(i - N + 1);
			}
			for (int i = 0; i < n; ++i) {
				set<int>::iterator iter = z[i].begin();
				printf("%d", *iter);
				++iter;
				for (; iter != z[i].end(); ++iter)
					printf(" %d", *iter);
				printf("\n");
			}
		}
	}
	return 0;
}

