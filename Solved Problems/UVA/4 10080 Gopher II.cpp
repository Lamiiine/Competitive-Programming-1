#include<stdio.h>
#include<queue>
#include<string.h>
#define MAX 105
#define eps 1e-9
using namespace std;
int head[MAX], to[MAX * MAX], nxt[MAX * MAX], en;
void addEdge(int i, int j) {
	nxt[en] = head[i];
	head[i] = en;
	to[en++] = j;
}
struct point {
	double x, y;
};
int n, m;	// sizes partite sets V and U respectively
int p[MAX << 1];
int match[MAX << 1];
void aug(int i) {
	for (int j; i != -1; i = p[j]) {
		j = p[i];
		match[i] = j;
		match[j] = i;
	}
}
void init(void) {
	memset(head, 0xFF, sizeof head);
	en = 0;
	memset(match, 0xFF, sizeof match);
}
double s, v;
point g[MAX];
point h[MAX];
double dist(const point & a, const point & b) {
	double dx = a.x - b.x, dy = a.y - b.y;
	return dx * dx + dy * dy;
}
void read_input(void) {
	scanf("%lf%lf", &s, &v);
	for (int i = 0; i < n; ++i)
		scanf("%lf%lf", &g[i].x, &g[i].y);
	for (int i = 0; i < m; ++i)
		scanf("%lf%lf", &h[i].x, &h[i].y);
	s *= v;
	s *= s;	// maximum square distance
	s += eps;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (dist(g[i], h[j]) < s)
				addEdge(i, MAX + j);
}
int main(void) {
	freopen("Input.txt", "r", stdin);
	while (scanf("%d%d", &n, &m) != EOF) {
		init();
		read_input();
		// loop over vertices in V
		for (int i = 0; i < n; ++i) {
			memset(p, 0xFF, sizeof p);
			queue<int> q;
			q.push(i);
			bool found = false;
			while (!q.empty() && !found) {
				// v is in V
				int v = q.front();
				q.pop();
				for (int j = head[v]; j != -1; j = nxt[j]) {
					// u is a neighbor of v in U
					int u = to[j];
					int w = match[u];
					// we need an augmenting path
					if (w == v)
						continue;
					// if u is free
					if (w == -1) {
						// augment
						p[u] = v;
						aug(u);
						found = true;
						break;
					} else if (p[w] == -1)
						q.push(w), p[u] = v, p[w] = u;
					// if w hasn't been considered already
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans += (match[i] != -1);
		printf("%d\n", n - ans);
	}
	return 0;
}

