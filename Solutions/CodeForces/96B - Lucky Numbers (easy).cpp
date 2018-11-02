#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll>v;
bool valid(int j, int i){	// number j, with i digits
	int counter[2] = { 0, 0 };
	for (int k = 0; k < i; ++k)
		counter[bool(j & (1 << k))]++;
	return counter[0] == counter[1];
}
ll convert(int j, int i){	// number j, with i digits
	char s[20];
	s[i] = 0;
	for (int k = 0; k < i; ++k)
		if (j & (1 << k))
			s[k] = '4';
		else s[k] = '7';
	ll ans;
	// printf("%d %d %s\n", i, j, s);
	sscanf(s, "%lld", &ans);
	return ans;
}
void init(void){
	// you have at most 10 digits
	for (int i = 2; i <= 10; i += 2)
		// generate all lucky numbers with i digits
		for (int j = 0; j < (1 << i); ++j){
			if (valid(j, i))
				v.push_back(convert(j, i));
		}
	sort(v.begin(), v.end());
}
int main(void) {
	init();
	ll x;
	cin >> x;
	for (int i = 0;; ++i)
		if (v[i] >= x) {
			cout << v[i];
			break;
		}
	return 0;
}

