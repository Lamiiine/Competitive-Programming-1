#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll d = 26;	// base
ll h;				// d^(k-1)
int len;	// length of my string
char s[10000010];	// my string
int n;		// length of my pattern
map<ll, int> freq;	// frequency of each substring
inline void normalize(void) {
	len = 0;
	for (char * c = s; *c; ++c)
		*c -= 'a', ++len;
}
inline ll raise(ll x, ll p) {
	ll ans = 1;
	for (; p; x *= x, p >>= 1)
		if (p & 1LL)
			ans *= x;
	return ans;
}
inline ll init(void) {
	freq.clear();
	h = raise(d, n - 1);
	// hash the first n characters
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans = (ll) ans * d + s[i];
	return ans;
}
inline ll update(ll code, int i) {
	return (code - h * (s[i - n])) * d + s[i];
}
inline ll get_max_freq(void) {
	ll ans = 0;
	int cur_max = 0;
	for (map<ll, int>::iterator iter = freq.begin(); iter != freq.end(); ++iter)
		if (iter->second > cur_max)
			cur_max = iter->second, ans = iter->first;
	return ans;
}
inline void decode(ll code) {
	s[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		s[i] = (code % 26) + 'a';
		code /= 26;
	}
}
int main(void) {
	while (scanf("%d%s", &n, s) != EOF) {
		normalize();
		if (len <= n) {
			for (int i = 0; i < len; ++i)
				s[i] += 'a';
			printf("%s", s);
			continue;
		}
		ll code = init();
		freq[code]++;
		for (int i = n; i < len; ++i)
			freq[code = update(code, i)]++;
		decode(get_max_freq());
		printf("%s\n", s);
	}
	return 0;
}

