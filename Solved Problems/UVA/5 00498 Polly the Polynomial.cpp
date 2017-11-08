#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> v;
inline ll horner(ll x){
	ll ans = 0;
	for (int i = 0; i < v.size(); ++i)
		ans = ans*x + v[i];
	return ans;
}
int main(void){
	for(string s; getline(cin, s);){
		v.clear();
		for (char * c = strtok(const_cast<char*> (s.c_str()), " \n"); c; c = strtok(0, " \n"))
			v.push_back(atoi(c));
		getline(cin, s);
		char * c = strtok(const_cast<char*> (s.c_str()), " \n");
		printf("%lld", horner(atoi(c)));
		for (c = strtok(0, " \n"); c; c = strtok(0, " \n"))
			printf(" %lld", horner(atoi(c)));
		printf("\n");
	}
	return 0;
}

