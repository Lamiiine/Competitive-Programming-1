#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<set>
#define MAX 30
using namespace std;
typedef pair<int, int> ii;
int distY[MAX][MAX];
int distM[MAX][MAX];
int n;
set<int> s;
void addEdge(int a[][MAX], bool bi, int x, int y, int z){
	a[x][y] = min(a[x][y], z);
	if (bi) a[y][x] = min(a[y][x], z);
	s.insert(x);
	s.insert(y);
}
int main(){
	// freopen("Input.txt", "r", stdin);
	while (scanf("%d", &n), n){
		memset(distY, 0xF, sizeof distY);
		memset(distM, 0xF, sizeof distM);
		char d;
		scanf("%c", &d);
		char t1, t2;
		char x, y;
		int z;
		for (int i = 0; i < n; ++i){
			scanf("%c%c%c%c%c%c%c%c%d%c", &t1, &d, &t2, &d, &x, &d, &y, &d, &z, &d);
			addEdge((t1 == 'Y') ? distY : distM, t2 == 'B', x - 'A', y - 'A', z);
		}
		char S, D;
		scanf("%c%c%c", &S, &d, &D);
		S -= 'A';
		D -= 'A';
		for (auto iter = s.begin(); iter != s.end(); ++iter) distY[*iter][*iter] = distM[*iter][*iter] = 0;
		for (auto k = s.begin(); k != s.end(); ++k)
		for (auto i = s.begin(); i != s.end(); ++i)
		for (auto j = s.begin(); j != s.end(); ++j)
			distY[*i][*j] = min(distY[*i][*j], distY[*i][*k] + distY[*k][*j]), distM[*i][*j] = min(distM[*i][*j], distM[*i][*k] + distM[*k][*j]);
		int ans = INT_MAX;
		for (auto i = s.begin(); i != s.end(); ++i) ans = min(ans, distY[S][*i] + distM[D][*i]);
		set<char>b;
		if (ans < 1000000) {
			printf("%d", ans);
			for (auto i = s.begin(); i != s.end(); ++i) if (ans == distY[S][*i] + distM[D][*i]) b.insert(*i + 'A');
			for (auto i = b.begin(); i != b.end(); ++i) printf(" %c", *i);
			printf("\n");
		}
		else printf("You will never meet.\n");	// You forgot the dot!
		s.clear();
	}
	return 0;
}
