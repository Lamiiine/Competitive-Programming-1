#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> ii;
int p[105];	// parents
inline void join(int i, int j){
	int x = i, y = j;
	while (p[x] != x) x = p[x];
	while (p[y] != y) y = p[y];
	p[i] = p[j] = p[x] = y;
}
int main(){
	int n;
	scanf("%d", &n);
	int x, y;
	ii a[105];
	ii b[105];
	bool processed[105];
	for (int i = 0; i < n; i++){
		scanf("%d%d", &x, &y);
		a[i] = ii(x, i), b[i] = ii(y, i);
		processed[i] = false;
		p[i] = i;
	}
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n-1; i++) {
		if (a[i].first == a[i + 1].first) join(a[i].second, a[i + 1].second);
		if (b[i].first == b[i + 1].first) join(b[i].second, b[i + 1].second);
	}
	//
	set<int> parents;
	for (int i = 0; i < n; i++) {
		if (processed[i]) continue;
		processed[x = i] = true;
		while (p[x] != x) processed[x = p[x]] = true;
		parents.insert(x);
	}
	printf("%d\n", parents.size() -1);
	return 0;
}
