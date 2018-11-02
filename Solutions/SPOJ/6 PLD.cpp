// Add this implementation of Rabin Karp along with another one to your library
#include<bits/stdc++.h>
#define MAX 30010
using namespace std;
typedef long long int ll;
struct rk{	// Rabin-Karp
	ll x, y, z;
	inline rk(const ll a, const ll b, const ll c):x(a), y(b), z(c){}
	inline rk():x(0LL), y(0LL), z(0LL){}
};
const rk prime(15485863LL, 179424673LL, 2147483647LL);	// 3 primes
inline bool operator == (const rk & a, const rk & b){
	return a.x == b.x && a.y == b.y && a.z == b.z;
}
inline const rk operator % (const rk & a, const rk & b){
	return rk(a.x%b.x, a.y%b.y, a.z%b.z);
}
inline const rk operator + (const rk & a, const rk & b){
	return rk(a.x + b.x, a.y + b.y, a.z + b.z) % prime;
}
inline const rk operator - (const rk & a, const rk & b){
	return (rk(a.x - b.x, a.y - b.y, a.z - b.z) % prime + prime)% prime;
}
inline const rk operator + (const rk & a, const ll f){
	return rk(a.x+f, a.y+f, a.z+f) % prime;
}
inline const rk operator - (const rk & a, const ll f){
	return (rk(a.x-f, a.y-f, a.z-f)%prime +prime) % prime;
}
inline const rk operator * (const rk & a, const ll f){
	return (rk(a.x*f, a.y*f, a.z*f) % prime + prime) % prime;
}
inline const rk operator * (const rk & a, const rk & b){
	return rk(a.x*b.x, a.y*b.y, a.z*b.z) % prime;
}
const ll d = 128LL;	// my radix
int n;				// length of my string
int k;				// length of my palindrome
char s[MAX];
rk hash_for[MAX];
rk hash_back[MAX];
inline const rk raise(ll x, ll p){
	rk ans(1LL, 1LL, 1LL);
	rk base(x, x, x);
	for (;p; p >>= 1, base = base * base)
		if (p & 1) ans = ans*base;
	return ans;
}
inline void rabin_karp(rk * hash){
	const rk h = raise(d, k - 1);
	rk t(0LL, 0LL, 0LL);
	for (int i = 0; i < k; ++i)
		t = t*d + ll(s[i]);
	hash[k-1] = t;
	for (int i = k; i <= n - k - 1; ++i)
		hash[i] = t = (t - h*ll(s[i-k]))*d + ll(s[i]);
}
inline void rabin_karp_reverse(rk * hash){
	const rk h = raise(d, k - 1);
	rk t(0LL, 0LL, 0LL);
	for (int i = n-1; i >= n-k; --i)
		t = t*d + ll(s[i]);
	hash[n-k] = t;
	for (int i = n - k - 1; i >= k; --i)
		hash[i] = t = (t - h*ll(s[i + k]))*d + ll(s[i]);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	scanf("%d%s", &k, s);
	n = strlen(s);
	if (k == 1)
		{printf("%d", n); return 0;}
	bool odd = k & 1;
	k >>= 1;
	rabin_karp(hash_for);
	rabin_karp_reverse(hash_back);
	int ans = 0;
	if (odd)
		for (int i = k-1; i <= n - k - 2; ++i)
			ans += (hash_for[i] == hash_back[i + 2]);
	else
		for (int i = k - 1; i <= n - k - 1; ++i)
			ans += (hash_for[i] == hash_back[i + 1]);
	printf("%d", ans);
	return 0;
}

