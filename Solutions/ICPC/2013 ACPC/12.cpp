#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, x, y;
	cin >> t;
	while(t--) {
		cin >> n >> x >> y;
		if(x <= n) {
			if(y == 1) {
				for(int i=1; i<=n+1; i++) {
					if(i != x) cout << i;
					if(i != n+1 && i != x) cout << " ";
				}
			} else {
				for(int i=1; i<=n; i++) {
					cout << i;
					if(i != n) cout << " ";
				}
			}
		} else {
			if(y == 1) {
				for(int i=1; i<=n; i++) {
					cout << i;
					if(i != n) cout << " ";
				}
			} else {
				for(int i=1; i<n; i++)
					cout << i << " ";
				cout << x;
			}
		}
		cout << endl;
	}
	return 0;
}

