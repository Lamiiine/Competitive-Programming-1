#include<string.h>
#include <iostream>
using namespace std;
int main(){
	// freopen("Input.txt", "r", stdin);
	// freopen("Output.txt", "w", stdout);
	char answer[100][4];
	int t;
	int q, m;
	char x, y;
	short falses;
	char unmarked;
	cin >> t;
	while (t--){
		memset(answer, 0, sizeof answer);
		cin >> q >> m;
		while (m--)
		for (int i = 0; i < q; i++)
		{
			cin >> x >> y;
			answer[i][x - 'A'] = y;
		}
		bool flag;
		for (int i = 0; i < q - 1; i++){
			flag = false;
			falses = 0;
			for (int j = 0; j < 4; j++){
				if (answer[i][j] == 'T') { cout << char(j + 'A') << ' '; flag = true; }
				else if (answer[i][j] == 'F') { falses++; }
				else unmarked = char(j + 'A');
			}
			if (falses == 3 && !flag) { cout << unmarked << ' '; flag = true; }
			if (!flag) cout << "? ";
		}
		flag = false;
		falses = 0;
		for (int j = 0; j < 4; j++){
			if (answer[q - 1][j] == 'T') { cout << char(j + 'A') << '\n'; flag = true; }
			else if (answer[q - 1][j] == 'F') { falses++; }
			else unmarked = char(j + 'A');
		}
		if (falses == 3 && !flag) { cout << unmarked << '\n'; flag = true; }
		if (!flag) cout << "?\n";
	}
	return 0;
}