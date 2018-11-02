#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
ii pos[10];		// position of digit i on the board
vector<ii>v;	// positions sequence
set<ii> valid;	// valid position numbers
int n;			// size of v
bool can(ii x){
	for (int i = 0; i < n - 1; ++i)
	{
		ii from = v[i], to = v[i + 1];
		ii move = ii(to.first - from.first, to.second - from.second);
		x = ii(x.first + move.first, x.second + move.second);
		if (valid.find(x) == valid.end()) return false;
	}
	return true;
}
inline void init(void){
	pos[0] = ii(3, 1);
	for (int i = 1; i <= 9; ++i){
		int j = i -1;
		pos[i] = ii(j / 3, j %3);
	}
	for (int i = 0; i < 10; ++i)
		valid.insert(pos[i]);
}
int main(void){
	init();
	char s[15];
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; ++i)
		v.push_back(pos[s[i] - '0']);
	for (int i = 0; i < 10; ++i)
		if (pos[i] != v[0] && can(pos[i]))
		{
			printf("NO"); return 0;
		}
	printf("YES");
	return 0;
}

