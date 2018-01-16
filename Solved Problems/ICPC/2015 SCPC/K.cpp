#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int head[MAX], to[MAX * 2], nxt[MAX * 2], en = 0;
int c, k, n;
int periph[MAX] = { 0 }, periph_id = 0;
vector<double> p;	// probability of success
inline void add_edge(const int i, const int j) {
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	++en;
}
inline void add_bi_edge(const int i, const int j) {
	add_edge(i, j);
	add_edge(j, i);
}

int vis[MAX] = { 0 }, vis_id = 0;
int dist[MAX];
int prnt[MAX];
inline int bfs(const int s) {
	int last = s;
	vis[s] = ++vis_id;
	dist[s] = 0;
	prnt[s] = -1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		const int i = q.front();
		q.pop();
		last = i;
		for (int j = head[i]; ~j; j = nxt[j]) {
			const int k = to[j];
			if (vis[k] != vis_id) {
				vis[k] = vis_id;
				dist[k] = dist[i] + 1;
				prnt[k] = i;
				q.push(k);
			}
		}
	}
	return last;
}
inline int climb(int i, int s) {
	while (s--)
		i = prnt[i];
	return i;
}
inline void read() {
	scanf("%d%d", &c, &k);
	for (int tree = 0; tree < c; ++tree) {
		scanf("%d", &n);
		for (int i = 2, x; i <= n; ++i)
			scanf("%d", &x), add_bi_edge(i, x);
		// find the number of nodes of eccentricity > k
		int v = bfs(1);	// v is on the periphery!
		int u = bfs(v);	// uv it the longest path in the tree
		int diameter = dist[u];	// diameter of the tree!
		// ++vis_id before DFS
		vector<int> vec;
		vec.push_back(climb(u, diameter / 2));
		if (diameter & 1)
			vec.push_back(climb(vec.back(), 1));

		++periph_id;
		for (int j = 0; j < vec.size(); ++j) {
			bfs(vec[j]);
			for (int i = 1; i <= n; ++i)
				if (dist[i] + (diameter / 2) > k)
					periph[i] = periph_id;
		}
		int counter = 0;
		for (int i = 1; i <= n; ++i)
			counter += (periph[i] == periph_id);
		p.push_back((double) double(n - counter) / double(n));
		memset(head, -1, (n + 3) * sizeof(int));
		en = 0;
	}
}
double mat[32][32];
inline void set_equations(void) {
	for (int i = 0; i < 32; ++i)
		for (int j = 0; j < 32; ++j)
			mat[i][j] = 0.0;
	for (int i = 0; i < c; ++i) {
		mat[i][c + 1] = 4.0 - 3.0 * p[i];
		mat[i][i] += 1.0;
		mat[i][i + 1] -= p[i];
		mat[i][0] += p[i] - 1.0;
	}
	mat[c][c] += 1.0;
}
inline int find_largest_value_row(int c)
{
	int r = c;
	for (int i = r + 1; i < n; i++)
		if (fabs(mat[i][c]) > fabs(mat[r][c]))
			r = i;
	return r;
}
inline double gauss()
{
	n = c + 1;
	vector<double> x(n + 4, 0.0);
	// forward elimination
	// loop over all columns
	for (int c = 0; c < n - 1; c++)
	{
		// to minimize overflow,
		int r = find_largest_value_row(c);
		for (int k = c; k <= n; k++)
			swap(mat[c][k], mat[r][k]);

		// actual forward elimination path
		// loop over the nonzero entries of the row
		for (int i = c + 1; i < n; i++)
		{
			const double factor = mat[i][c] / mat[c][c];
			for (int k = n; k >= c; k--)
				mat[i][k] -= mat[c][k] * factor;
		}
	}

	// back substitution
	for (int j = n - 1; j >= 0; j--)
	{
		double t;
		for (t = 0.0, k = j + 1; k < n; k++)
			t += mat[j][k] * x[k];
		x[j] = (mat[j][n] - t) / mat[j][j];
	}

	return x[0];
}
int main(void) {
	int TC;
	scanf("%d", &TC);
	memset(head, -1, sizeof head);
	while (TC--)
	{
		p.clear();
		read();
		set_equations();
		printf("%.4lf\n", gauss());
	}
	return 0;
}
