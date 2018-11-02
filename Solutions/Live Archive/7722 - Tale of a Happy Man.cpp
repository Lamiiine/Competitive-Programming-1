#include <bits/stdc++.h>
#define MAX 20005
using namespace std;
typedef long long int ll;
struct task
{
	int A, B, H;
	inline task(const int _A, const int _B, const int _H):A(_A), B(_B), H(_H){ }
	inline task():A(0), B(0), H(0){}
	inline bool operator < (const task & other) const
	{
		return make_pair(A, B) < make_pair(other.A, other.B);
	}
};

/*
 * Tasks are sorted by starting time.
 */
task tasks[MAX];
int m;	// Number of tasks!
ll memo[MAX];

inline ll dp(const int i)
{
	ll & ret = memo[i];
	if (~ret) return ret;
	if (i >= m) return ret = 0LL;
	return ret = max(
			// Either take task #i!
			tasks[i].H + dp(lower_bound(tasks + i + 1, tasks + m, task(tasks[i].B, -1, 0)) - tasks),
			// Or skip it!
			dp(i + 1));
}
inline void init()
{
	memset(memo, -1, sizeof memo);
}
inline void read()
{
	int dummy;
	scanf("%d%d", &dummy, &m);
	for (int i = 0, a, b, h; i < m; ++i)
	{
		scanf("%d%d%d%d", &dummy, &a, &b, &h);
		tasks[i] = task(a, b, h);
	}
}
int main(){
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		read();
		init();
		sort(tasks, tasks + m);
		printf("Case #%d: %lld\n", tc, dp(0));
	}
	return 0;
}
/*
4
3 5
1 10 20 1
1 20 60 1
2 30 50 2
2 60 100 1
3 20 40 3
1 5
1 0 10 1
1 10 20 2
1 20 30 3
1 30 40 4
1 40 50 5
3 6
1 0 10 1
1 10 20 6
2 0 10 2
2 10 20 5
3 0 10 3
3 10 20 4
5 5
1 10000 30000 100
2 20000 40000 250
3 30000 50000 200
4 50000 70000 300
5 80000 90000 400
 */

