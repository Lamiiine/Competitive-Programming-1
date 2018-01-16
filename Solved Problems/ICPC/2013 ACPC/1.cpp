#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		unsigned long long ans = 1;
		int i = 0;
		while(s[i] == '?') i++;
		int j = s.size()-1;
		while(s[j] == '?') j--;
		char c = s[i];
		bool start = false;
		int count = 0;
		//cout << i << " " << j << endl;
		for(int x = i+1; x <= j; x++) {
			if(s[x] == '?') {
				start = true;
				count++;
			} else if(start) {
				//cout << c << " " << s[x] << endl;
				if(s[x] != c) ans = (ans * (count + 1)) % 1000000007;
				start = false;
				count = 0;
				c = s[x];
			} else {
				c = s[x];
			}
		}
		cout << ans << endl;
	}
	return 0;
}

