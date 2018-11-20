#include<stdio.h>
#include<limits.h>
#include<queue>
#include<vector>
#include<string.h>
#define MAX 105
#define INF 10000000
#define eps 1e-9
#define V_MAX MAX << 1
using namespace std;
const int S = 208;	// source
int T;				// sink
inline int in(const int i) {
	return i;
}
inline int out(const int i) {
	return i + MAX;
}
int head[V_MAX], to[MAX * MAX * 2], nxt[MAX * MAX * 2], cost[MAX * MAX * 2], en;
int res[V_MAX][V_MAX];
void recover(void) {
	memset(res, 0, sizeof res);
	for (int i = 0; i < V_MAX; ++i)
		for (int j = head[i]; j != -1; j = nxt[j])
			res[i][to[j]] = cost[j];
}
void addEdge(int i, int j, int k) {
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	cost[en++] = k;
}
int n;
double d;
struct point {
	int x, y, n, m;
	point(int a, int b, int c, int d):x(a), y(b), n(c), m(d){ }
	point(){}
} a[MAX];
inline int dist(const point & a, const point & b) {
	int dx = a.x - b.x, dy = a.y - b.y;
	return dx * dx + dy * dy;
}
int p[V_MAX];
void aug(int f) {
	for (int i = T, j; i != S; i = j)
		j = p[i], res[j][i] -= f, res[i][j] += f;
}
typedef pair<int, int> ii;
int max_flow() {
	int mf = 0;
	int f;
	while (1) {
		queue<ii> q;
		q.push(ii(S, INT_MAX));
		f = 0;
		memset(p, 0xFF, sizeof p);
		p[S] = S;
		while (!q.empty() && !f) {
			int i = q.front().first, F = q.front().second;
			q.pop();
			for (int j = head[i]; j != -1; j = nxt[j]) {
				int k = to[j];
				int z = res[i][k];
				if (!z || p[k] != -1)
					continue;
				p[k] = i, q.push(ii(k, min(F, z)));
				if (k == T) {
					f = q.back().second;
					break;
				}
			}
		}
		if (!f)
			break;
		mf += f;
		aug(f);
	}
	return mf;
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		memset(head, 0xFF, sizeof head);
		en = 0;
		int total = 0;
		scanf("%d%lf", &n, &d);
		d *= d;
		d += eps;
		// DON'T USE SAME VARIABLE NAME TWICE!!!
		// IT TOOK YOU SO LONG TO FIND OUT THAT THE PROBLEM WAS ABOUT VARIABLE NAMES!!!
		for (int i = 0, x, y, z, w; i < n; ++i)
			scanf("%d%d%d%d", &x, &y, &z, &w), a[i] = point(x, y, z, w);
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			point temp = a[i];
			total += temp.n;	// add this number of penguins!
			addEdge(S, in(i), temp.n);
			addEdge(in(i), out(i), temp.m);
			for (int j = i + 1; j < n; ++j) {
				if (double(dist(temp, a[j])) < d)
					addEdge(out(i), in(j), INF), addEdge(out(j), in(i), INF);
			}
		}
		for (int i = 0; i < n; ++i) {
			recover();
			T = in(i);
			if (max_flow() == total)
				ans.push_back(i);
		}
		if (ans.empty())
			printf("-1\n");
		else
			for (int i = 0; i < ans.size(); ++i)
				printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
	}
	return 0;
}

