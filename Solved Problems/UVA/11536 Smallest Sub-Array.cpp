#include <bits/stdc++.h>
#define MAX 1000100
using namespace std;
int n, m, k;
int counter[105];
int arr[MAX];
inline void init_arr(void){
	for (int i = 0; i < 3; ++i)
		arr[i] = i + 1;
	for (int i = 3; i < n; ++i)
		arr[i] = (arr[i-1] + arr[i-2] + arr[i-3]) % m + 1;
}
#define INIT 1000000000
inline int solve(void){
	memset(counter, 0, sizeof counter);
	int ans = INIT;
	set<int>s;
	int i = 0, j = 0;
	for(;i < n; ++i)
	if (arr[i] <= k) {
		s.insert(arr[i]);
		++counter[arr[i]];
		break;
	}
	// your first inserted element is i
	if (i == n) return ans;
	for(j = i + 1; j < n;++j){
		int x = arr[j];
		if (x <= k){
			if (++counter[x] == 1) {
				s.insert(x);
				if (s.size() == k)
				{
					for(;s.size() == k;++i){
						x = arr[i];
						if (x <= k && !--counter[x])
						s.erase(x);
					}
					// element i-1 should not have been erased!
					ans = min(ans, j - i + 2);
					while(arr[i] > k) ++i;
				}
			}
		}
	}
	return ans;
}
int main() {
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		printf("Case %d: ", tc);
		scanf("%d%d%d", &n, &m, &k);
		if (k == 1) {printf("1\n"); continue;}
		init_arr();
		int ans = solve();
		if (ans == INIT) printf("sequence nai");
		else printf("%d", ans);
		printf("\n");
	}
	return 0;
}
