#include <bits/stdc++.h>
using namespace std;


int n;
int arr[200010];
int cnt[200010];

int getres(bool flag){
	cnt[0] = 1;
	for(int i = 1; i < 2*n; i++)
		if(!flag && arr[i-1] >= arr[i] || flag && arr[i-1] <= arr[i])
			cnt[i] = cnt[i-1] + 1;
		else cnt[i] = 1;

	int ret = 100000000;
	for(int i = 0; i < 2*n; i++)
		if(cnt[i] >= n)
			ret = min(ret, (flag) ? (i % n + 1) : ((i + 1) % n + 1));
	return ret == 100000000 ? -1 : ret;
}

int main()
{
#ifdef ONLINE_JUDGE
	freopen("dealing.in", "r", stdin);
#endif

	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			arr[i+n] = arr[i];
		}

		int l = getres(true);
		int r = getres(false);

		if(r == -1 && l == -1) printf("NO\n");
		else if (l != -1 && r != -1)
		{
			// both are valid!
			if (l <= r)
				printf("%d L\n", l);
			else
				printf("%d R\n", r);
		}
		else if(r != -1) printf("%d R\n", r);
		else printf("%d L\n", l);
	}

}
