#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> ii;
char name[100005][12];
vector<ii>v[10005];
int main(){
	// freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%s%d%d", name[i], &x, &y);
		v[x].push_back(ii(-y, i));
	}
	for (int i = 1; i <= m; ++i) {
		sort(v[i].begin(), v[i].end());
		if (v[i].size() < 3 || v[i][1].first != v[i][2].first) printf("%s %s\n", name[v[i][0].second], name[v[i][1].second]);
		else printf("?\n");
	}
	return 0;
}