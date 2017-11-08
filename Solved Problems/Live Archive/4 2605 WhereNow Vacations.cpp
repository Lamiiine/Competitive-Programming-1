#include<bits/stdc++.h>
#define MAX_TOUR 100
#define MAX_VAC 100
#define S 202
#define T 203
#define MAX 205
using namespace std;
typedef pair<int, int> ii;
inline int tourist(int i){
	return i;
}
inline int vacation(int i){
	return i + MAX_TOUR;
}
map<string, int> m;
int head[MAX], nxt[MAX*MAX], to[MAX*MAX], cost[MAX*MAX], en;
inline void addEdge(const int x, const int y, const int z){
	nxt[en] = head[x]; head[x] = en; to[en] = y; cost[en] = z; ++en;
}
int f;
int res[MAX][MAX];
int p[MAX];
inline void aug(){
	for (int i = T, j; i != S; i = j)
		j = p[i], res[j][i] -= f, res[i][j] += f;
}
inline int max_flow(void){
	int mf = 0;
	while(1){
		queue<ii>q;
		f = 0;
		q.push(ii(S, INT_MAX));
		memset(p, 0xFF, sizeof p);
		p[S] = S;
		while(!q.empty() && !f){
			int i = q.front().first, F = q.front().second;
			q.pop();
			for (int j = 0; j < MAX; ++j)
			{
				int z = res[i][j];
				if (!z || p[j] != -1) continue;
				p[j] = i, q.push(ii(j, min(z, F)));
				if (j == T){
					f = q.back().second;
					break;
				}
			}
		}
		if (!f) break;
		mf += f;
		aug();
	}
	return mf;
}
inline void init(void){
	memset(head, 0xFF, sizeof head);
	en = 0;
	memset(res, 0, sizeof res);
	m.clear();
}
bool empty(char * s){
	for (;*s;++s)
		if (!isspace(*s)) return false;
	return true;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;scanf("%d", &TC);
	int num_tour;
	for(int tc = 1;tc <= TC; ++tc){
		if (tc != 1) printf("\n");
		init();
		printf("Week #%d:  ", tc);
		char line[10000];
		int x; scanf("%d", &x);
		*line = 0; while(empty(line)) fgets(line, INT_MAX, stdin);
		// printf("%s", line);
		for (char counter = 0, *v = strtok(line, " \n"); v; v = strtok(0, " \n")){
			char * u = strtok(0, " \n");
			sscanf(u, "%d", &x);
			if (x) {
				m[v] = counter;
				addEdge(vacation(counter),T, x);
				++counter;
			}
		}
		scanf("%d", &num_tour);	// number of tourists
		for (int i = 0; i < num_tour; ++i){
			addEdge(S, tourist(i), 1);
			scanf("%d", &x);
			while(x--){
				scanf("%s", line);
				map<string, int>::iterator iter = m.find(line);
				if (iter != m.end())
				// YOU FORGOT TO WRITE 'vacation()'!!!!!!!!!!!!!!
				addEdge(tourist(i), vacation(iter->second), 1);
			}
		}
		for (int i = 0; i < MAX; ++i)
			for (int j = head[i]; j != -1; j = nxt[j])
				res[i][to[j]] = cost[j];
		// for (map<string, int>::iterator iter = m.begin(); iter != m.end(); ++iter) printf("%-10s %d\n", (iter->first).c_str(), iter->second);
		// for (int i = 0; i < MAX; ++i) for (int j = 0; j < MAX; ++j) if (res[i][j]) printf("%-4d %-4d %d\n", i, j, res[i][j]);
		printf("%s\n", max_flow() == num_tour ? "All is well." : "Warning!  ");
		// printf("num_tour = %d; max_flow() = %d\n", num_tour, max_flow());
	}
	return 0;
}

