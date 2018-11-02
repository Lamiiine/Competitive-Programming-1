#include<bits/stdc++.h>
using namespace std;
int memo[22][5005];	// memo[i][j] = value of i bills of type j
int den[5005];
int n, k;
int main(void){
	// freopen("Input.txt", "r", stdin);
	memset(memo[0], 0, sizeof memo[0]);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", den + i);
	for (int i = 1; i <= k; ++i)
		for (int j = 0; j < n; ++j)
			memo[i][j] = i*den[j];
	int q;
	scanf("%d", &q);
	while(q--){
		int val; scanf("%d", &val);
		int ans = INT_MAX;
		for (int i = 0; i <= k; ++i)
			for (int j = 0; j < n; ++j){
				int cur = val - memo[i][j];
				for (int l = k - i; l >= 0; --l)
					if (binary_search(memo[l], memo[l] + n, cur))
						ans = min(ans, i + l);
			}
		if (ans == INT_MAX)
			printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}

