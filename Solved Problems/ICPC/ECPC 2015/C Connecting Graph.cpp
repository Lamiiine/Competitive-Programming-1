#include<stdio.h>
#include<string.h>
#include<vector>
#define MAX 100005
using namespace std;
int n, q;
int t_count;
int p[MAX];
int time[MAX];
int _rank[MAX];
inline int parent(const int i){
	return p[i] == i ? i : parent(p[i]);
}
inline void unite(const int i, const int j){
	int I = parent(i), J = parent(j);
	if (I == J) return;
	int ri = _rank[I], rj = _rank[J];
	if (ri < rj){
		p[I] = J;
		time[I] = t_count;
	}
	else {
		p[J] = I;
		time[J] = t_count;
		if (ri == rj) ++_rank[I];
	}
}
inline bool same(const int i, const int j){
	return parent(i) == parent(j);
}
inline void path(const int i, vector<int> & v){
	if (p[i] != i)
		path(p[i], v);
	v.push_back(i);
}
inline void init(void){
	t_count = 0;
	for (int i = 1; i <= n; ++i) p[i] = i;
	memset(_rank, 0, (n+3)*sizeof _rank[0]);
	memset(time, 0, (n + 3)*sizeof time[0]);
}
int main(void){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d", &n, &q);
		init();
		int x, y, z;
		vector<int>v;
		vector<int>u;
		while(q--){
			++t_count;
			scanf("%d%d%d", &x, &y, &z);
			if (x == 1) unite(y, z);
			else if (!same(y, z)) printf("-1\n");
			else if (y == z) printf("0\n");
			else
			{
				path(y, v);
				path(z, u);
				int i = 0;
				while(i < v.size() && i < u.size() && v[i] == u[i]) ++i;
				int ans = 0;
				for (int j = i; j < v.size(); ++j)
					ans = max(ans, time[v[j]]);
				for (int j = i; j < u.size(); ++j)
					ans = max(ans, time[u[j]]);
				printf("%d\n", ans);
				v.clear();
				u.clear();
			}
		}
	}
	return 0;
}


