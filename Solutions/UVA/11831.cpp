#include <stdio.h>
#include <string.h>
#include <cctype>
#define MAX 105
using namespace std;
int n, m, s;
int x, y, z;	// position and direction 0, 1, 2, 3 for N, E, S, W respectively
char M[MAX][MAX];
bool taken[MAX][MAX];
char inst[50005];
int count;
void move(char c){
	if (c == 'D'){
		z =(z + 1)& 3;
		return;
	}
	if (c == 'E'){
		z = (z + 3)&3;
		return;
	}
	int temp_x = x, temp_y = y;
	switch(z){
		case 0: --temp_x; break;
		case 1: ++temp_y; break;
		case 2: ++temp_x; break;
		case 3: --temp_y; break;
	}
	if (temp_x < 0 || temp_x >= n || temp_y < 0 || temp_y >= m) return;
	if (M[temp_x][temp_y] == '#') return;
	x = temp_x, y = temp_y;
	if (M[x][y] == '*' && !taken[x][y]) {taken[x][y] = true; ++count;}
	return;
}
int main() {
	while(scanf("%d%d%d", &n, &m, &s), n && m && s){
		count = 0;	// don't forget to set count to zero with every iteration
		memset(taken, 0, sizeof taken);
		char d;
		scanf("%c", &d);
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j)
			{
				scanf("%c", &M[i][j]);
				if (isalpha(d = M[i][j])){
					x = i, y = j;
					z = (d == 'N')?0:(d == 'S')?2:(d == 'L')?1:3;
				}
			}
			scanf("%c", &d);
		}
		scanf("%s", inst);
		for (int i = 0; i < s; ++i) move(inst[i]);
		printf("%d\n", count);
	}
	return 0;
}
