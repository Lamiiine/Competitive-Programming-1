/* SPOJ: BDOI16E - Village Fair
 * You have to read the problem before reading this
 * Solution idea:
 * We will have an array of sets of integers, one set per node
 * Let's call this array st[]
 * Let's call the array in which we store the joy value of
 * kids in each village joy[]
 *
 * We will do a single DFS from the root node
 * Each time the DFS visits a node i, it should return after having
 * inserted all the values of joys that will pass by node i in st[i]
 * How can we implement this DFS?
 * Calling dfs(i), we have 2 cases:
 * 1. i is a leaf node:
 * 	- insert joy[i] (joy of child in node i) in st[i], and return
 * 2. i is an internal node
 * 	- insert joy[i] in st[i]
 * 	- for each child c,
 * 	  firstly, call dfs(c) to create the set of joy values of c
 * 	  then, for each joy value v in st[c],
 * 	  insert v + (cost of edge c -> v) in st[i]
 *
 * Now, we understand the idea, but how can we speed it up?
 * Let say you have 3 children, having set sizes of 3, 5, and 10
 * In that case, swap the set of the child that has a set size of 10
 * with his parent's set, and brute force on the elements of the sets
 * of the children having set sizes of 3 and 5 (copying their elements one by one)
 *
 * In general, let's call the child that has the largest set the special child.
 * We can swap the set of the special child with the set of the parent.
 * This should be O(1) using swap(st[parent], st[special_child]),
 * since the swap function in C++ swaps the object pointers, and does not
 * actually copy the sets.
 * For the remaining children, just brute force. Copy the elements
 * one by one from the sets of non-special children onto the parent's set.
 *
 * You should have 2 objections now:
 * 1. This does not sound like an O (n log n) solution, since
 * there is still a lot of copying involved
 * 2. st[special_child] can not be just swapped with st[parent]
 * because we need to change the values of st[special_child]
 * before copying. We need to add (cost of edge special_child -> parent)
 * to every value in st[special_child].
 *
 * For the first objection, don't worry, it is O (n log n). There is a proof
 * for that that we can discuss later. But the intuitive idea of the
 * proof is that if the tree height is log n (as is the case usually), then
 * we will do no more than n log n operations (even with brute force).
 * Problems arise when the tree height is linear or semi-linear. This can only be
 * true if many internal nodes have just one child (because if every node has
 * at least 2 children, the tree height will be <= log n). For those nodes having
 * just one child, the set of that child will be swapped and we will do no copying.
 * Thus our solution works for both cases.
 *
 * For the second objection, you are right. The copied values are not correct.
 * Therefore, we will have another array add[], such that, calling dfs(i),
 * it needs to only return after having done two things:
 * 1. insert all the values of joys that will pass by node i in st[i]
 * 2. set add[i] to an offset value that needs to be added to every
 * element in st[i], in order for us to obtain the correct value of that
 * element (see implementation details below)
 *
 * Another objection can be: if we swap st[parent] with st[special_child], we
 * won't be able to answer the problem query (st[i].size() for all i, 1 <= i <= n)
 * because the sets will be changed.
 * For this, we will create an array ans[i], in which we store st[i].size()
 * before returning from dfs(i). Thus a child node doesn't care if his parent
 * messes up with his set after the child returns his DFS. The child has
 * already collected the information he needs.
 */
#include<bits/stdc++.h>
#define MAX 100010
using namespace std;
typedef pair<int, int> ii;

/*
 * st[i] will contain the set of joy values that will pass by node #i
 */
set<int> st[MAX];
/*
 * add[i] will store an offset value that needs to be added to the
 * elements of st[i], so we can obtain their correct values
 */
int add[MAX];

/*
 * ans[i] will contain the size of the set st[i]
 */
int ans[MAX];

int n;				// number of nodes
int joy[MAX];		// joy[i] = joy of kid in node #i
vector<ii> adj[MAX];// adj[i] = children of node #i
int root;			// index of root node

// reading stuff
int parent[MAX];
int change[MAX];
inline void read(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", joy + i);
	for (int i = 1; i <= n; ++i)
		scanf("%d", parent + i);
	for (int i = 1; i <= n; ++i)
		scanf("%d", change + i);
	for (int i = 1; i <= n; ++i)
		if (parent[i] == 0)
			root = i;
		else adj[parent[i]].push_back(ii(i, change[i]));
}


inline void dfs(const int v)
{
	if (adj[v].empty())
	{
		// v is a leaf, which means:

		// 1. its set contains a single value (the joy of the kid in that node)
		st[v].insert(joy[v]);
		// 2. no value needs to be added to any member of that set
		add[v] = 0;
		// 3. a single joy value passes by this node
		ans[v] = 1;
		// 4. no more processing needed!
		return;
	}

	// recursively create the sets of each one of your children
	for (int i = 0; i < adj[v].size(); ++i)
	{
		const ii child = adj[v][i];
		dfs(child.first);
	}

	// find the special child
	int mx_size = 0, mx_idx = 0;

	for (int i = 0; i < (int)adj[v].size(); ++i)
	{
		const ii cur = adj[v][i];
		if ((int)st[cur.first].size() > mx_size)
			mx_size = st[cur.first].size(), mx_idx = i;
	}

	// this is our special child
	const ii mx_child = adj[v][mx_idx];
	// swap his set with his parent's set
	swap(st[mx_child.first], st[v]);

	// store offset value
	add[v] = add[mx_child.first] + mx_child.second;

	// now, we add the joy of the kid at v
	st[v].insert(joy[v] - add[v]);

	// now, we add the joys of the kids in non-special children
	for (int i = 0; i < (int) adj[v].size(); ++i)
	{
		if (i == mx_idx)
			// special child already processed
			continue;
		const ii cur_child = adj[v][i];
		set<int> & cur_child_set = st[cur_child.first];
		for (set<int>::iterator x = cur_child_set.begin(); x != cur_child_set.end(); ++x)
			st[v].insert(*x + add[cur_child.first] + cur_child.second - add[v]);
		/* inspect the line just above, and make sure you understand why the inserted
		 * value is computed this way.
		 */
		cur_child_set.clear();
	}

	// set ans[v] before returning
	ans[v] = st[v].size();
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	read();
	dfs(root);
	for (int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

