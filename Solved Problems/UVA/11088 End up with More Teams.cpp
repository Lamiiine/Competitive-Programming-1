#include <bits/stdc++.h>
#define MAX 16
using namespace std;
int memo[1 << MAX];
int n;
int arr[MAX];
inline bool read(void){
	scanf("%d", &n);
	if (!n) return false;
	for (int i = 0; i < n; ++i)
	scanf("%d", arr + i);
	return true;
}
inline int count_zeros(const int i)
{
	int ans = 0;
	for (int j = 0; j < n; ++j)
		ans += (!(i & (1 << j)));
	return ans;
}
inline int first_free(const int mask, const int i)
{
	int ans = i;
	while(ans < n && (mask & (1 << ans)))
		++ans;
	return ans;
}
inline int dp(const int i){
	int & ret = memo[i];
	if (ret != -1) return ret;
	if (count_zeros(i) < 3) return ret = 0;
	ret = 0;
	for (int j = first_free(i, 0); j < n; j = first_free(i, j + 1))
	for (int k = first_free(i, j + 1); k < n; k = first_free(i, k + 1))
	for (int t = first_free(i, k + 1); t < n; t = first_free(i, t + 1))
	{
		if (arr[j] + arr[k] + arr[t] >= 20)
			ret = max(ret, 1 + dp(i | (1 << j) | (1 << k) | (1 << t)));
	}
	return ret;
}
inline void init_memo(void){
	memset(memo, 0xFF, sizeof memo);
}
int main() {
	for(int tc = 1; read(); ++tc)
	{
		init_memo();
		printf("Case %d: %d\n", tc, dp(0));
	}
	return 0;
}