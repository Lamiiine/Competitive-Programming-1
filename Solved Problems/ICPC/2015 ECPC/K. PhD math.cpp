#include<bits/stdc++.h>
#define MAX 1000100
using namespace std;
typedef long long int ll;
int n;
int d[MAX];
int rem[MAX][200];
ll a, b, p;
inline void init_d(void){
	for (int i = 0; i < n; ++i){
		a *= 10LL;
		d[i] = a/b;
		a %= b;
	}
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		cin >> a >> b >> n >> p;
		init_d();
		memset(rem, 0, sizeof rem);
		rem[0][d[0] % p] = 1;
		for (int i = 1; i < n; ++i)
		{
			const int cur_d = d[i];
			int * v = rem[i];
			int * u = rem[i-1];
			v[cur_d % p] += 1;
			for (int j = 0; j < p; ++j)
				v[(j*10 + cur_d) % p] += u[j];
		}
		ll ans = 0LL;
		for (int i = 0; i < n; ++i)
			ans += rem[i][0];
		cout << ans << "\n";
	}
	return 0;
}

