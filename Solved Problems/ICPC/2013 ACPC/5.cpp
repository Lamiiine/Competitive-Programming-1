#include <bits/stdc++.h>
using namespace std;

int a[105];
int n, x, y;

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> x >> y;
		for (int i = 0; i < n; i ++){
			cin >> a[i];
		}
		bool hard = a[n-1] == y;
		bool easy = a[0] == x;
		if(hard && easy){
			cout << "BOTH" << endl;
		}
		else if (hard){
			cout << "HARD" << endl;
		}
		else if(easy){
			cout << "EASY" << endl;
		}
		else{
			cout << "OKAY" << endl;
		}
	}
}

