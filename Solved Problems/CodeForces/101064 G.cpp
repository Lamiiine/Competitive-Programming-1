/*
 * How did I think of this solution? (My approach)
 * Let's first discuss the brute force solution. In the brute force solution,
 * you will simply traverse the quries one by one (in the same order as they are
 * given in the input), and store a deque at every index. So at index 0 you will
 * store an empty dequeu, and at every other index i you will store the deque
 * obtained at step i. This solution involves too much overhead, and will get a TLE.
 *
 * My approach was to improve the performance of this solution by answering the
 * queries in a different order. Changing the order in which I answer the queries
 * seemed like it was the only way to reduce time. It also required storing the queries
 * queries and answer them offline (after reading input).
 * We need to store, for each query i, the indeces of all the queries that reference
 * query #i to each query, which should be straight forward (just as I did in this solution).
 *
 * How about actually answering the queries? - For this, I first thought of going in
 * a strictly increasing order by the index of the referenced query. We first answer
 * all queries referencing 0, then all queries referencing 1, and so on.
 * After inspecting this idea, I found that it still involves a lot of copying.
 * This is because, if queries a, b, and c reference query i, then you will have
 * to store the queues for a, b, and c, before moving to answering query i + 1.
 * (Otherwise, how can you answer queries a, b, and c?)
 * So apparently, going in this order wouldn't have worked.
 *
 * Having to find another ordering for answering the queries that would eliminate
 * any copying of deques, I came up with this idea. Answer the queries in a
 * DFS-like fashion, which is the idea I used in this solution, thus answering
 * query i, involves first answering (recursively) all queries referncing i.
 * This will require no copying overhead at all, since after answering query #i,
 * you don't need to store deque #i anymore, since all the queries referencing i
 * will have already been answered. Got an AC in 171 ms.
 */

#include<bits/stdc++.h>
#define MAX 100100
using namespace std;
enum q_type : char {D, E};
// enumeration for query type, as explained in problem statement

typedef pair<q_type, int> query;
/* query object;
 * first item stores query type;
 * second item stores:
 * - in case of query type E, the value to be appended to the end of the queue
 * - in case of query type D, store nothing at first,
 *   then store the value that was popped from the queue front as you answer the queries
*/

int n;	// number of queries
query arr[MAX];	// my queries

vector<int> v[MAX];
/* v[i] stores the indeces of the queries that reference query #i
 * for example, if query #10 ie E 5 -13, then we push 10 on v[5]
*/


// answer query number i!
void answer(const int i, deque<int> & q)
{
	/* to answer query number #i
	 * (notice that the queue that we will be using is passed to us as a parameter)
	 * perform the operation required on the queue passed
	 * answer recursively all the queries the reference i
	 * undo the operation, and return
	 *
	 * We are saving time because we pass the queue by reference
	 * That's also why we have to undo the operation (so the function
	 * will return without any modifications made to the queue).
	 */
	query & cur = arr[i];
	if (cur.first == D)
	{
		// step #0 (only in type D): store the answer
		cur.second = q.front();
		// step #1: perform the query operation
		q.pop_front();
		// step #2: recursively answer all queries referencing this one
		for (int j = 0; j < v[i].size(); ++j)
			answer(v[i][j], q);
		// step #3: undo the operation
		q.push_front(cur.second);
	}
	else
	{
		// step #1: perform the query operation
		q.push_back(cur.second);
		// step #2: recursively answer all queries referencing this one
		for (int j = 0; j < v[i].size(); ++j)
			answer(v[i][j], q);
		// step #3: undo the operation
		q.pop_back();
	}
}

// a routine to read input
inline void read(void)
{
	scanf("%d", &n);
	char s[5];
	for (int i = 1, q_num, val; i <= n; ++i)
	{
		// read query type and the number of the referenced query!
		scanf("%s%d", s, &q_num);
		// store the query
		if (*s == 'E')
			scanf("%d", &val), arr[i] = query(E, val);
		else
			arr[i] = query(D, 0);

		// another reference has been made to query q_num; store its index
		v[q_num].push_back(i);
	}
}


int main(void)
{
	read();
	deque<int> q;
	/* loop over all queries that reference query 0, and answer them
	 * Notice that this will get all the queries answered, because
	 * all the queries either reference 0, or reference another query i
	 * that references another query j (less than i) that references
	 * ... that references 0
	 */
	for (int i = 0; i < v[0].size(); ++i)
		answer(v[0][i], q);

	// print the solutions
	for (int i = 1; i <= n; ++i)
		if (arr[i].first == D)
			printf("%d\n", arr[i].second);
}

