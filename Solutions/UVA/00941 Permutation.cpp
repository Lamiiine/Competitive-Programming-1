#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll fact[21];
inline void init_fact(void){
	fact[0] = 1LL;
	for (ll i = 1; i <= 20; ++i)
		fact[i] = i * fact[i - 1];
}
// get the n^th permutation of s
inline string permute(string s, ll n){
	if (n == 1 || n == 0) return s;	// no reorderings required!
	int x = lower_bound(fact + 1, fact + 21, n) - fact;
	string ans;
	// x is the number of characters involved
	{
		int i = s.length() - x;
		ans = s.substr(0, i);	// this part of s remains untouched
		s = s.substr(i);
	}
	// fact[x] > n!
	--x;
	ll y = (ll) n / fact[x] + bool(n % fact[x]) - 1;	// ranging from 1 to (x + 1)
	// index of element that occupies s[0] is y-1
	ans = ans + string(1, s[y]);
	s = s.substr(0, y) + s.substr(y + 1);
	return ans + permute(s, n - y * fact[x]);
}
int main(void){
	init_fact();
	int TC; scanf("%d", &TC);
	ll n;
	char s[30];
	while(TC--){
		scanf("%s%lld", s, &n);
		sort(s, s + strlen(s));
		printf("%s\n", permute(s, n + 1).c_str());
	}
	return 0;
}

