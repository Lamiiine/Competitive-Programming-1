#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
#include<limits.h>
// T-shirt sizes are numbered 0 to 5
#define N 10	// max # of sizes (base for students)
// students are numbered 10 to 44
#define M 35	// max # of students
#define S 45	// source
#define T 46	// destination
#define MAX 47
using namespace std;
typedef pair<int, int> ii;
int res[MAX][MAX];
int p[MAX];
int mf, f;
int n, m;
void init(void) {
	memset(res, 0, sizeof res);
	mf = 0;
}
void aug(void){
	for (int i = T, j; i != S; i = j)
		j = p[i], res[j][i] -= f, res[i][j] += f;
}
// flow goes source to t-shirts to students to destination
int main(void) {
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		init();
		scanf("%d%d", &n, &m);
		{
			for (int i = N; i < N + m; ++i)
				res[i][T] = 1;
			map<string, int>mm;
			mm["XXL"] = 0, mm["XL"] = 1, mm["L"] = 2, mm["M"] = 3, mm["S"] = 4, mm["XS"] = 5;
			n /= 6;
			for (int i = 0; i < 6; ++i)
				res[S][i] = n;
			char s[5];
			for (int i = N; i < N + m; ++i) {
				scanf("%s", s);
				++res[mm[s]][i];
				scanf("%s", s);
				++res[mm[s]][i];
			}
		}
		while(1){
			f = 0;
			memset(p, 0xFF, sizeof p);
			queue<ii>q;
			p[S] = S;
			q.push(ii(S, INT_MAX));
			while(!q.empty() && !f){
				const int i = q.front().first, F = q.front().second;
				q.pop();
				for (int j = 0; j < MAX; ++j)
				{
					int z = res[i][j];
					if (!z || p[j] != -1) continue;
					p[j] = i;
					q.push(ii(j, min(z, F)));
					if (j == T){
						f = q.back().second;
						break;
					}
				}
			}
			if (!f) break;
			mf += f;
			aug();
		}
		printf("%s\n", mf == m ? "YES" : "NO");
	}
	return 0;
}

