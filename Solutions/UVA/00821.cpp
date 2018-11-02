#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
#define MAX 105
using namespace std;
int dist[MAX][MAX];
int main(){
	// freopen("Input.txt", "r", stdin);
	int x, y;
	int TC = 0;
	bool vis[MAX];
	while (scanf("%d%d", &x, &y), x && y){
		set<int> s;
		s.insert(x);
		s.insert(y);
		printf("Case %d: average length between pages = ", ++TC);
		memset(dist, 0xF, sizeof dist);
		dist[x][y] = 1;
		while (scanf("%d%d", &x, &y), x && y) dist[x][y] = 1, s.insert(x), s.insert(y);
		if (s.size() == 1){ printf("0.000 clicks\n"); continue; }
		// You only consider a subset of websites
		for (auto iter = s.begin(); iter != s.end(); ++iter) dist[*iter][*iter] = 0;
		// 1-based indexing!!!

		for (auto k = s.begin(); k != s.end(); ++k)
		for (auto i = s.begin(); i != s.end(); ++i)
		for (auto j = s.begin(); j != s.end(); ++j)
			dist[*i][*j] = min(dist[*i][*j], dist[*i][*k] + dist[*k][*j]);
		int total = 0;
		int num = (s.size()*(s.size() - 1));
		for (auto i = s.begin(); i != s.end(); ++i)
		for (auto j = s.begin(); j != s.end(); ++j)
		{
			total += dist[*i][*j];
		}
		long double ans = (long double)total;
		ans /= (long double)num;
		printf("%1.3llf clicks\n", ans);
	}
	return 0;
}