#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
typedef pair<int, int >ii;
enum d{ n = 0, w = 1, s = 2, e = 3 };
inline d dir(const int i, const int j){
	if (!i)return (j > 0) ? n : s;
	return (i > 0) ? e : w;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int k;
	scanf("%d", &k);
	int x, y;
	ii p[1005];
	for (int i = 0; i <= k; ++i){
		scanf("%d%d", &x, &y);
		p[i] = ii(x, y);
	}
	int ans = 0;
	for (int i = 0; i < k - 1; ++i){
		int dx = p[i + 1].first - p[i].first;
		int dy = p[i + 1].second - p[i].second;
		int Dx = p[i + 2].first - p[i + 1].first;
		int Dy = p[i + 2].second - p[i + 1].second;
		d d1 = dir(dx, dy);
		d d2 = dir(Dx, Dy);
		ans += (d1 == n && d2 == w);
		ans += (d1 == s && d2 == e);
		ans += (d1 == w && d2 == s);
		ans += (d1 == e && d2 == n);
	}
	printf("%d", ans);
	return 0;
}