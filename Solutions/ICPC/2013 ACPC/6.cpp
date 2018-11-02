#include <bits/stdc++.h>
using namespace std;

map<char, int> dx;
map<char, int> dy;

int main(){
	dx['R'] = 1;
	dx['L'] = -1;
	dy['R'] = dy['L'] = 0;
	dy['U'] = 1;
	dy['D'] = -1;
	dx['U'] = dx['D'] = 0;
	int t; cin >> t;
	while(t--){
		int x = 0, y = 0;
		int n_qm = 0;
		string inst; cin >> inst;
		for(char c : inst){
			if(c != '?'){
				x += dx[c];
				y += dy[c];
			}
			else{
				n_qm ++;
			}
		}
		cout << x - n_qm << " " << y - n_qm << " " <<  x + n_qm << " " <<  y + n_qm << endl;
	}
}

