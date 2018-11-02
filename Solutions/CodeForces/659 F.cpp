// A PROBLEM WORTH STUDYING!!!
// THE THING IS: YOU NEED TO MAXIMIZE AREA ACCORDING TO A GIVEN CONSTRAINT
// SEE IF YOUR WORK ON CONSTRAINT a_i COULD HELP YOU WITH CONSTRAINT a_{i+1}
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<limits.h>
#include<queue>
#include<algorithm>
#include<iostream>
#define MAX 1001

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long int ll;
inline bool eq(iii v, iii x) {
	return v.first < x.first;
}

int n, m;
long long int k;
int a[MAX][MAX];
bool vis[MAX][MAX];
iii val[MAX * MAX];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
ii p[MAX][MAX];
int sz[MAX][MAX];
inline void init() {
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < n; ++i)
		// YOU HAD A TYPO HERE
		for (int j = 0; j < m; ++j)
			p[i][j] = ii(i, j), sz[i][j] = 1;
}
inline ii parent(ii i) {
	return (p[i.first][i.second] == i) ?
			i : (p[i.first][i.second] = parent(p[i.first][i.second]));
}
inline void unite(ii i, ii j) {
	ii I, J;
	if ((I = parent(i)) == (J = parent(j)))
		return;
	p[I.first][I.second] = J;
	sz[J.first][J.second] += sz[I.first][I.second];
}
// YOU CONFUSED THE NOTATION BY PASSING 'i' TO THE FUNCTION WHICH USES LOCAL VARIABLE 'i' A LOT
bool can(int ind) {
	iii temp = val[ind];
	int ans = temp.first, x = temp.second.first, y = temp.second.second;
	queue<ii> q;
	vis[x][y] = true;
	q.push(ii(x, y));
	while (!q.empty()) {
		ii v = q.front();
		q.pop();
		int s, r;
		for (int k = 0; k < 4; ++k) {
			s = v.first + dx[k];
			r = v.second + dy[k];
			if (s < 0 || r < 0 || s >= n || r >= m || a[s][r] < ans)
				continue;
			unite(ii(s, r), ii(x, y));
			if (!vis[s][r]) q.push(ii(s, r)), vis[s][r] = true;
		}
	}
	ii geddo = parent(ii(x, y));
	return ll(sz[geddo.first][geddo.second]) >= (k / ll(temp.first));
}
int main() {
	// freopen("Input.txt", "r", stdin);
	// YOU FIRST 'scanf()' YOUR VALUES, THEN YOU CALL 'init()'
	scanf("%d%d", &n, &m);
	init();
	cin >> k;
	int counter = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			int x;
			scanf("%d", &x);
			val[counter++] = iii(a[i][j] = x, ii(i, j));
		}
	sort(val, val + counter, eq);
	// YOU HAD CONSIDERED THE CORNER CASE OF 'k' BEING ZERO, EVEN THOUGH THE PROBLEM STATEMENT EXCLUDED THIS CASE!
	if (k / ll(ll(n) * ll(m)) > ll(val[counter - 1].first)) {
		printf("NO");
		return 0;
	}
	for (int i = counter - 1; i >= 0; --i) {
		iii temp = val[i];
		if (k % temp.first || vis[temp.second.first][temp.second.second])
			continue;
		if (can(i)) {
			printf("YES\n");
			int sz = k / ll(temp.first);
			memset(vis, 0, sizeof vis);
			queue<ii>q;
			q.push(ii(temp.second.first, temp.second.second));
			--sz;
			vis[temp.second.first][temp.second.second] = true;
			// YOU COMBINED THEM INTO COMPONENTS, HOWEVER, WHEN YOU 'BFS' LAST TIME TO GET THE CORRECT ONE,
			// YOU NEED TO START 'BFS' FROM THE RIGHT LOCATION, NOT JUST AT ANY COMPONENT
			while(!q.empty()){
				ii v = q.front();
				q.pop();
				int s, r;
				for (int k = 0;sz && k < 4; ++k) {
					s = v.first + dx[k];
					r = v.second + dy[k];
					if (s < 0 || r < 0 || s >= n || r >= m || a[s][r] < temp.first || vis[s][r])
						continue;
					vis[s][r] = true;
					q.push(ii(s, r));
					--sz;
				}
			}
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (vis[i][j])
						printf("%d%c", temp.first, " \n"[j == m - 1]);
					else
						printf("0%c", " \n"[j == m - 1]);
			return 0;
		}
	}
	printf("NO");
	return 0;
}