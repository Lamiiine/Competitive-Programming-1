#include<bits/stdc++.h>
#define MAX 105
#define X real()
#define Y imag()
using namespace std;
typedef complex<int> point;
int n, m;
int k, d;
vector<point>tree[MAX];
vector<point>doctor;
int p[MAX];
inline int parent(const int i)
{
	return p[i] == i ? i : p[i] = parent(p[i]);
}
inline void unite(const int i, const int j)
{
	p[parent(i)] = parent(j);
}
inline bool same(const int i, const int j)
{
	return parent(i) == parent(j);
}
inline void init(void)
{
	for (int i = 0; i < MAX; ++i)
	{
		tree[i].clear();
	}

	doctor.clear();

	for (int i = 0; i < MAX; ++i)
	{
		p[i] = i;
	}
}

inline void read(void)
{
	scanf("%d%d%d%d", &n, &m, &k, &d);
	k *= k; d *= d;
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		doctor.push_back(point(x, y));
	}

	int temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &temp);
		while(temp--)
		{
			scanf("%d%d", &x, &y);
			tree[i].push_back(point(x, y));
		}
	}
}

inline double dist(const point & a, const point & b)
{
	return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

inline void combine(void)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			const vector<point> & a = tree[i];
			const vector<point> & b = tree[j];
			for (int k = 0; k < a.size(); ++k)
			{
				for (int t = 0; t < b.size(); ++t)
				{
					if (dist(a[k], b[t]) <= ::k)
					{
						unite(i, j);
						break;
					}
				}
			}
		}
	}
}

int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		combine();
		bool flag = false;
		for (int i = 0; i < n && !flag; ++i)
		{
			if (same(i, 0))
			{
				for (int j = 0; j < tree[i].size() && !flag; ++j)
				{
					for (int k = 0; k < doctor.size() && !flag; ++k)
					{
						if (dist(doctor[k], tree[i][j]) <= d)
						{
							flag = true;
						}
					}
				}
			}
		}

		printf("%s\n", flag ? "Tree can be saved :)" : "Tree can't be saved :(");
	}
}
