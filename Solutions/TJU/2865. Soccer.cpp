#include<stdio.h>
#include<vector>
#define MAX 16
#define left(s) (s << 1)
#define right(s) ((s << 1) + 1)
using namespace std;
typedef long double ld;
typedef pair<int, ld> ii;
char s[MAX][MAX];
int p[MAX][MAX];
vector<ii> v[MAX << 1];
void cal(int i) {	// calculate probabilities node i
	int LEFT = left(i), RIGHT = right(i);
	for (int iteration = 0; iteration < 2; ++iteration) {
		const vector<ii> & l = v[LEFT];
		const vector<ii> & r = v[RIGHT];
		for (int j = 0; j < l.size(); ++j) {
			ld ans = 0;
			for (int k = 0; k < r.size(); ++k)
				ans += (ld) r[k].second * p[l[j].first][r[k].first] / 100.0;
			ans *= l[j].second;
			v[i].push_back(ii(l[j].first, ans));
		}
		swap(LEFT, RIGHT);
	}
}
void init(void){
	for (int i = 0; i < 32; ++i)
		v[i].clear();
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc) {
		init();
		printf("Scenario #%d:\n", tc);
		for (int i = 0; i < MAX; ++i)
			scanf("%s", s[i]);
		for (int i = 0; i < MAX; ++i)
			for (int j = 0; j < MAX; ++j)
				scanf("%d", &p[i][j]);
		for (int i = 16; i < 32; ++i)
			v[i].push_back(ii(i - 16, 1.0));// you will find team i at this node with probability j
		for (int i = 15; i >= 1; --i)
			cal(i);
		// printf("%d\n", v[1].size());
		for (int i = 0; i < v[1].size(); ++i)
			printf("%-10s %6.2llf\n", s[v[1][i].first], v[1][i].second * 100.0);
		printf("\n");
	}
}

