/*
3 1
2 2 9
2 3 5
3 5 8
2 1
4 5 9
4 8 12
5 2
2 1 3
2 3 5
2 5 7
2 1 7
4 2 6
0
*/
#include<bits/stdc++.h>
#define MAX_MONKEYS (100 + 10)
#define MAX_INTERVALS (MAX_MONKEYS << 1)
#define MAX (MAX_MONKEYS + MAX_INTERVALS + 10)
#define monkey(i) (i)
#define interval(i) (i + MAX_MONKEYS)
#define S (MAX - 1)
#define T (MAX - 2)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n;	// number of monkeys
int m;	// amount of water to drink per second
int res[MAX][MAX];
int p[MAX];
vii intervals;
int rem[50010];
inline void aug(int f){
	for (int i = T, j; i != S; i = j)
		j = p[i], res[j][i] -= f, res[i][j] += f;
}
inline int max_flow(void){
	int mf = 0, f;
	while(1){
		queue<ii>q;
		f = 0;
		memset(p, 0xFF, sizeof p);
		p[S] = S;
		q.push(ii(S, INT_MAX));
		while(!q.empty() && !f){
			int i = q.front().first, F = q.front().second;
			q.pop();
			for (int j = 0; j < MAX; ++j)
			{
				int z = res[i][j];
				if (!z || p[j] != -1) continue;
				p[j] = i;
				q.push(ii(j, min(F, z)));
				if (j == T){
					f = q.back().second;
					break;
				}
			}
		}
		if (!f) break;
		mf += f;
		aug(f);
	}
	return mf;
}
inline void addEdge(const int f, const int t, const int c){
	res[f][t] += c;
}
inline void init(void){
	memset(res, 0, sizeof res);
	intervals.clear();
}
inline void read(void){
	set<int> points;
	ii monkey_interval[MAX_MONKEYS];
	scanf("%d", &m);
	for (int v, a, b, i = 0; i < n; ++i){
		scanf("%d%d%d", &v, &a, &b);
		addEdge(S, i, v);
		points.insert(a); points.insert(b);
		monkey_interval[i] = ii(a, b - 1);
	}
	// generate intervals
	for (set<int>::iterator j = points.begin();;){
		set<int>::iterator i = j++;
		if (j == points.end()) break;
		intervals.push_back(ii(*i, *j - 1));
	}
	// At this moment, we only have edges from source to monkeys
	for (int i = 0; i < intervals.size(); ++i)
	{
		const ii cur = intervals[i];
		addEdge(interval(i), T, (cur.second - cur.first + 1)*m);
	}
	// done with edges from intervals to destination
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < intervals.size(); ++j)
		{
			const ii x = monkey_interval[i];
			const ii y = intervals[j];
			if (y.first >= x.first && y.second <= x.second)
				addEdge(monkey(i), interval(j), y.second - y.first + 1);
		}
}
inline void print(void){
	for (int i = 0; i < 50000; ++i)
		rem[i] = m;
	// loop over monkeys
	for (int i = 0; i < n; ++i)
	{
		vi drink;
		vii cur;
		// loop over intervals
		for (int j = 0; j < MAX_INTERVALS; ++j)
		{
			int z = res[interval(j)][monkey(i)];
			if (!z) continue;
			// monkey i drank z from interval j!
			for (int k = intervals[j].first;z;++k)
			if (rem[k]){
				drink.push_back(k);
				--rem[k]; --z;
			}
		}
		for (int j = 0; j < drink.size();){
			int Start = drink[j];
			int End = Start + 1; ++j;
			while(j < drink.size() && drink[j] == End) ++End, ++j;
			cur.push_back(ii(Start, End));
		}
		printf("%d", cur.size());
		for (int i = 0; i < cur.size(); ++i)
			printf(" (%d,%d)", cur[i].first, cur[i].second);
		printf("\n");
	}
}
int main(void){
	for(int tc = 1; scanf("%d", &n), n; ++tc){
		printf("Case %d: ", tc);
		init();
		read();
		int need = 0;
		for (int i = 0; i < n; ++i)
			need += res[S][monkey(i)];
		int ans = max_flow();
		if (need != ans) printf("No\n");
		else {
			printf("Yes\n");
			print();
		}
	}
	return 0;
}

