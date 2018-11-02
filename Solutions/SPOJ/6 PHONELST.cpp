#include<bits/stdc++.h>
#define MAX 10005
using namespace std;
typedef long long int ll;
typedef pair<ll, int> lli;
int n;
char s[15];
char * const c = s + 1;
ll arr[MAX];
lli pre[MAX * 11];
int main(void){
	s[0] = '1';
	// freopen("Input.txt", "r", stdin);
	int TC;
	for (scanf("%d", &TC); TC--;){
		scanf("%d", &n);
		for (int i = 0; i < n; ++i){
			scanf("%s", c);
			sscanf(s, "%lld", arr + i);
		}
		sort(arr, arr + n);
		int m = 0;
		for (int i = 0; i < n; ++i){
			ll x = arr[i]/10LL;
			while(x > 9)
				pre[m++] = lli(x, i), x /= 10LL;
		}
		sort(pre, pre + m);
		bool flag = true;
		int j = 0;
		for (int i = 0; i < n && flag; ++i){
			ll x = arr[i];
			for(;j < m && pre[j].first <= x && flag;++j)
				if (pre[j].first == x && pre[j].second != i) flag = false;
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}

