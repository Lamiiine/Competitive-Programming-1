#include<bits/stdc++.h>
#define MAX 100100
using namespace std;

int lft[MAX], rght[MAX];

int depth[MAX], count_leaves[MAX];
double fr[MAX], fh[MAX];

int p[MAX];
int root;
int n, q;
int r, v, h, u;

inline double find_width(int i);
inline double child_dist(int i)
{
	double dist_left = find_width(lft[i]) - fr[lft[i]] * r - fh[lft[i]] * h;
	double dist_right = fr[rght[i]] * r + fh[rght[i]] * h;
	return dist_left + dist_right + h;
}
inline double locate(int i)
{
	if (i == root) return 0.0;
	double p_l = locate(p[i]);
	double d = child_dist(p[i]) * 0.5;
	if (lft[p[i]] == i)
		return p_l - d;
	else return p_l + d;
}
inline void dfs(const int i, const int d)
{
	depth[i] = d;
	if (lft[i] == -1)
	{
		// leaf
		count_leaves[i] = 1;
		fr[i] = 1.0;
		fh[i] = 0.0;
	}
	else
	{
		dfs(lft[i], d + 1);
		dfs(rght[i], d + 1);
		count_leaves[i] = count_leaves[lft[i]] + count_leaves[rght[i]];
		fr[i] = (fr[lft[i]] + fr[rght[i]] + 2.0 * count_leaves[lft[i]]) * 0.5;
		fh[i] = (fh[lft[i]] + fh[rght[i]] + 1.0 * count_leaves[lft[i]]) * 0.5;
	}
}
inline void read()
{
	scanf("%d%d", &n, &q);
	for (int i = 1, k, l, r; i <= n; ++i)
	{
		scanf("%d", &k);
		if (k == 2)
			scanf("%d%d", &l, &r), lft[i] = l, rght[i] = r, p[l] = p[r] = i;
		else lft[i] = rght[i] = -1;
	}
}
bool is_root[MAX];
inline int find_root()
{
	memset(is_root, 1, sizeof is_root);
	for (int i = 1; i <= n; ++i)
		if (lft[i] != -1)
			is_root[lft[i]] = false, is_root[rght[i]] = false;
	for (int i = 1; i <= n; ++i)
		if (is_root[i]) return i;
	return 0;
}
inline double find_width(int i)
{
	return count_leaves[i] * 2 * r + (count_leaves[i] - 1) * h;
}
inline double find_y(int i)
{
	return double(-depth[i] * (r + r + v));
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		root = find_root();
		dfs(root, 0);
		while(q--)
		{
			scanf("%d%d%d%d", &r, &v, &h, &u);
			printf("%.4lf %.4lf\n", locate(u), find_y(u));
		}
	}
	return 0;
}
