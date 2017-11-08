#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<string>
// computers are number 0-9
#define S 10	// source
#define A 11	// app base
#define T 37	// destination
#define MAX 38
using namespace std;
typedef pair<int, int> ii;
int res[MAX][MAX];
int p[MAX];
int mf;
int f;
void init(void){
	memset(res, 0, sizeof res);
	for (int i = 0; i < 10; ++i)
		res[i][T] = 1;
	mf = 0;
}
bool empty(const char * s){
	for (int i = 0;s[i]; ++i)
		if (!isspace(s[i]) && s[i] != EOF) return false;
	return true;
}
void aug(void){
	int i, j;
	for (i = T; i != S; i = j)
		j = p[i], res[j][i] -= f, res[i][j] += f;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	char s[100];
	while(1){
		int total = 0;
		init();
		*s = 0;
		fgets(s, INT_MAX, stdin);
		if (empty(s)) break;
		while(!empty(s)){
			int x = s[0] - 'A' + A;	// index of my app
			total += (res[S][x]=  s[1] - '0');	// number of instances
			for (int i = 3; s[i] != ';'; ++i)
				res[x][s[i] - '0'] = 1;
			// when 'fgets' reaches 'EOF', it doesn't edit the content of 's'
			*s = 0;
			fgets(s, INT_MAX, stdin);
		}
		while(1){
			f = 0;
			memset(p, 0xFF, sizeof p);
			p[S] = S;
			queue<ii>q;
			q.push(ii(S, INT_MAX));
			while(!q.empty() && !f){
				int i = q.front().first, F = q.front().second;
				q.pop();
				for (int j = 0; j < MAX; ++j){
					int z = res[i][j];
					if (z && p[j] == -1){
						p[j] = i;
						q.push(ii(j, min(z, F)));
						if (j == T){
							f = q.back().second;
							break;
						}
					}
				}
			}
			if (!f)break;
			mf += f;
			aug();
		}
		if (total != mf)printf("!");
		else for (int i = 0; i < 10; ++i){
			bool flag = false;
			// loop over all apps
			for (int j = A; j < A + 26 && !flag; ++j)
				if (res[i][j]){
					printf("%c", j - A + 'A');
					flag = true;
				}
			if (!flag)printf("_");
		}
		printf("\n");
	}
	return 0;
}

