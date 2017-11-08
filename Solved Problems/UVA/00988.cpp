#include<stdio.h>
#include<vector>
using namespace std;
vector<int>counter;
vector<bool>dead;
int n;
int main(void){
	// freopen("Input.txt", "r", stdin);
	bool first = true;
	while(scanf("%d", &n) != EOF){
		if (!first) printf("\n");
		first = false;
		counter.assign(n, 0);
		dead.assign(n, false);
		counter[0] = 1;
		for (int i = 0; i < n; ++i){
			int cur_count = counter[i];
			int k, x; scanf("%d", &k);
			if (!k)dead[i] = true;
			else while(k--)
				scanf("%d", &x), counter[x] += cur_count;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (dead[i])
				ans += counter[i];
		printf("%d\n", ans);
	}
	return 0;
}

