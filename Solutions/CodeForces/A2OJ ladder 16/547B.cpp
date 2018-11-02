#include <bits/stdc++.h>
#define MAX 200005
using namespace std;
struct bear
{
	int idx, height;
	inline bear(const int _idx, const int _height):idx(_idx), height(_height){}
	inline bool operator < (const bear & other) const
	{
		return height < other.height;
	}
};

int p[MAX], sz[MAX];
int n;
vector<bear> bears;
bool done[MAX] = { 0 };
inline void init()
{
	for (int i = 0; i < MAX; ++i)
	{
		p[i] = i;
		sz[i] = 1;
	}
}
inline int parent(const int i)
{
	return (p[i] == i) ? i : (p[i] = parent(p[i]));
}
inline int unite(const int i, const int j)
{
	const int I = parent(i), J = parent(j);
	if (I != J)
	{
		p[J] = I;
		sz[I] += sz[J];
	}
	return sz[I];
}
inline void read()
{
	scanf("%d", &n);
	bears.reserve(n);
	for (int a, i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		bears.push_back(bear(i, a));
	}
}
int main()
{
	init();
	read();
	sort(bears.begin(), bears.end());
	reverse(bears.begin(), bears.end());
	int largest = 0;
	for (const auto & cur : bears)
	{
		int new_largest = max(largest, 1);
		done[cur.idx] = true;
		if (cur.idx != 0 && done[cur.idx - 1])
		{
			new_largest = max(new_largest, unite(cur.idx, cur.idx - 1));
		}
		if (cur.idx != n - 1 && done[cur.idx + 1])
		{
			new_largest = max(new_largest, unite(cur.idx, cur.idx + 1));
		}
		while(largest < new_largest)
		{
			++largest;
			printf("%d ", cur.height);
		}
	}
	return 0;
}
/*
10
1 2 3 4 5 4 3 2 1 6
 */

