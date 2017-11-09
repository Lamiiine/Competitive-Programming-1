#include <bits/stdc++.h>
#define MAX 100100
using namespace std;
int n;
int head[MAX], to[MAX * 2], nxt[MAX * 2], en = 0;
bool problem[MAX * 2];
vector<int> elected;
inline void init()
{
	memset(head, -1, sizeof head); en = 0;
	memset(problem, 0, sizeof problem);
}
inline bool dfs(const int v, const int p, const bool son_of_a_problem)
{
	bool flag = false;
	for (int j = head[v]; ~j; j = nxt[j])
	{
		const int u = to[j];
		if (u != p)	// child
		{
			flag |= dfs(u, v, problem[j]);
		}
	}
	if (son_of_a_problem && !flag)
	{
		elected.push_back(v);
		return 1;
	}
	else
	{
		return flag;
	}
}
inline void add_edge(const int i, const int j, const int t)
{
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	problem[en] = (t == 2);
	++en;
}
inline void add_bi_edge(const int i, const int j, const int t)
{
	add_edge(i, j, t);
	add_edge(j, i, t);
}
inline void read()
{
	scanf("%d", &n);
	for (int a, b, t, i = 1; i < n; ++i)
	{
		scanf("%d%d%d", &a, &b, &t);
		add_bi_edge(a, b, t);
	}
}
int main()
{
	init();
	read();
	dfs(1, -1, 0);
	printf("%d\n", (int) elected.size());
	for (int i = 0; i < elected.size(); ++i)
	{
		printf("%d%c", elected[i], i == elected.size() - 1 ? '\n' : ' ');
	}
	return 0;
}
/*

5
1 2 2
2 3 2
3 4 2
4 5 2

5
1 2 1
2 3 2
2 4 1
4 5 1

5
1 2 2
1 3 2
1 4 2
1 5 2
 */

