/* imagine the mines as the nodes of a directed graph
 * there is an edge from node i to node j if and only if exploding
 * mine #i would result in mine #j being exploded as well
 *
 * Now, how do we find the minimum number of mines that we
 * need to explode in order for us to get all the mines exploded?
 *
 * First thought (which is wrong): count the number of vertices with
 * in-degree == 0. Why is this wrong? - Because there might be cycles.
 * In a cycle, no node has in-degree == 0, so this solution would give
 * an answer of 0 mines needing to be exploded. The correct answer is 1.
 * You need to explode at least one mine, and the explosion will propagate
 * along the cycle to the other mines.
 *
 * This is true for strongly-connected components in general. In an SCC,
 * exploding any mine would result in all the other mines in the same SCC
 * being exploded (recall what the definition of an SCC is).
 *
 * Now, what is the answer? Is is the number of different SCC's? - No, think
 * of two SCC's having a directed edge in between like O -> O
 * In this case we only need to explode one mine in the first SCC, and all the graph
 * will be exploded.
 *
 * So what is the answer? - It's the number of SCCs with in-degree == 0.
 * What do we mean by the in-degree of an SCC? - The in-degree of SCC i
 * is the number of edges u -> v in the orginal graph where, where v is
 * a member of SCC i and u is a member of another SCC
 *
 * Think about it! Couting the number of NODES of in-degree == 0, gives you
 * a wrong answer. Counting the number of SCC'S of in-degree == 0 is the
 * correct answer. Can you tell why?
 */


#include<bits/stdc++.h>
#define MAX (1 << 11)	/* 2000 */
using namespace std;
typedef pair<int, int> ii;
ii arr[MAX];	// mine coordinates
int d[MAX];		// the power of each mine



int n;	// number of mines
int in_deg[MAX];	/* in_deg[i] = in-degree of SCC #i
				(after running the algorithm, of course) */



// disjoint sets stuff
int p[MAX];
inline int get_p(const int i)
{
	return p[i] == i ? i : p[i] = get_p(p[i]);
}
inline void unite(const int i, const int j)
{
	p[get_p(j)] = get_p(i);
}




// this is the DFS stuff
int dfs_num[MAX], dfs_low[MAX], dfs_count;
enum color {white = 0, gray, black} vis[MAX];




// a routine to initialize your global variables!
inline void init(void)
{
	for (int i = 0; i < MAX; ++i)
		p[i] = i;
	dfs_count = 0;
	memset(vis, 0, sizeof vis);
	memset(in_deg, 0, sizeof in_deg);
}



inline bool can(const int i, const int j)
{
	return abs(arr[i].first - arr[j].first) <= d[i] &&
					abs(arr[i].second - arr[j].second) <= d[i];
}
/* can(i, j) returns true if and only if exploding mine #i would result
 * in mine #j being exploded as well
 *
 * Equivalently, can(i, j) returns true if an only if there is a directed
 * edge from mine #i to mine #j
 */





// input routine
inline void read(void)
{
	scanf("%d", &n);
	for (int i = 0, a, b, c; i < n; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		arr[i] = ii(a, b);
		d[i] = c >> 1;
	}
}




// Tarjan's SCC algorithm (copied from library)
vector<int> dfs_v;
inline void dfs(const int i)
{
	dfs_v.push_back(i);
	dfs_num[i] = dfs_low[i] = dfs_count++;
	vis[i] = gray;
	for (int j = 0; j < n; ++j)
	{
		if (j != i && can(i, j))
		{
			if (!vis[j]) dfs(j);
			if (vis[j] == gray)
				dfs_low[i] = min(dfs_low[i], dfs_low[j]);
		}
	}
	if (dfs_low[i] == dfs_num[i])
	{
		for(int j = -1; j != i;)
		{
			j = dfs_v.back();
			dfs_v.pop_back();
			unite(i, j);
			vis[j] = black;
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
		for (int i = 0; i < n; ++i)
			if (!vis[i])
				dfs(i);

		// calculates in-degrees of SCC's
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (get_p(i) != get_p(j) && can(i, j))
					++in_deg[get_p(j)];

		int ans = 0;
		for (int i = 0; i < n; ++i)
			/*
			 * if i is the root of a component, then the previous
			 * nested loop would assign in_deg[i] to the in-degree
			 * of the whole component
			 *
			 * therefore, if p[i] == i (i is the head of a component)
			 * and in_deg[i] == 0 (component represented by node i
			 * has no incoming edges), this component needs to be initiated
			 * by an explosing!
			 */
			if (p[i] == i && !in_deg[i])
				++ans;

		printf("%d\n", ans);
	}
	return 0;
}

