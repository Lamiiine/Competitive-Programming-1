#include <iostream>
#define N 45000
using namespace std;
typedef long long int ll;
int a[N];
inline void init(void){
	for (int i = 1; i < N; ++i)
		a[i] = i*i;
}
int main() {
	init();
	for (int n; scanf("%d", &n), n;){
		int i = lower_bound(a + 1, a + N, n) - a;
		int x, y;
		if (a[i] == n) {
			x = 1; y = i;
		}
		else
		{
			x = i;
			y = n - a[i - 1];
			if (y > i){
				x -= (y - i);
				y = i;
			}
		}
		if (!(i & 1)) swap(x, y);
		printf("%d %d\n", x, y);
	}
	return 0;
}