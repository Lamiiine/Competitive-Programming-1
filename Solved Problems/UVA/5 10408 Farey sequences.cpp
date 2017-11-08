#include<bits/stdc++.h>
using namespace std;
struct rational{
	int a, b;
	rational(int _a, int _b) : a(_a), b(_b){}
};
inline bool operator < (const rational & x, const rational & y){
	return x.a*y.b < y.a*x.b;
}
bool done[1001];
vector<rational>f[1001];
inline void init(void){
	memset(done, 0, sizeof done);
	done[1] = 1;
	f[1].push_back(rational(1, 1));
	for (int i = 2; i <= 1000; ++i){
		vector<rational> & v = f[i];
		v.reserve(i - 1);
		for (int j = 1; j < i; ++j)
			if (__gcd(i, j) == 1)v.push_back(rational(j, i));
	}
}
inline vector<rational> merge(const vector<rational> & a, const vector<rational> & b){
	vector<rational> ans;
	ans.reserve(a.size() + b.size());
	int i = 0, j = 0;
	while(i < a.size() && j < b.size())
		if (a[i] < b[j])
			ans.push_back(a[i++]);
		else ans.push_back(b[j++]);
	while(i < a.size()) ans.push_back(a[i++]);
	while(j < b.size()) ans.push_back(b[j++]);
	return ans;
}
inline void construct(int i){
	if (done[i]) return;
	construct(i-1);
	f[i] = merge(f[i], f[i-1]);
	done[i] = true;
}
int main(void){
	init();
	for (int n, k; ~scanf("%d%d", &n, &k);construct(n), printf("%d/%d\n", f[n][k - 1].a, f[n][k - 1].b));
	return 0;
}

