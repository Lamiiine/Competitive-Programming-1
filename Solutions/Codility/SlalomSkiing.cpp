#include <bits/stdc++.h>
#define MAX 100100
#define left(s) ((s) << 1)
#define right(s) (left(s) + 1)
#define avg(a, b) (((a) + (b)) >> 1)
using namespace std;
class segment_tree
{
public:
	segment_tree(int _n)
	{
		n = _n;
		st.assign(n * 4, 0);
	}
	inline int query(const int _i, const int _j)
	{
		i = _i; j = _j;
		return _query(1, 0, n - 1);
	}
	inline void update(const int _i, const int _val)
	{
		i = j = _i;
		val = _val;
		_update(1, 0, n - 1);
	}
private:
	int n;
	vector<int> st;
	int i, j, val;
	inline int _query(const int p, const int l, const int r)
	{
		if (l > j || r < i) return 0;
		if (l >= i && r <= j) return st[p];
		return max(_query(left(p), l, avg(l, r)), _query(right(p), avg(l, r) + 1, r));
	}
	inline void _update(const int p, const int l, const int r)
	{
		if (l > i || r < i) return;
		if (l == r)
		{
			// it must be that l == r == i
			st[p] = val;
		}
		else
		{
			_update(left(p), l, avg(l, r));
			_update(right(p), avg(l, r) + 1, r);
			st[p] = max(st[left(p)], st[right(p)]);
		}
	}
};
int solution(vector<int> & A)
{
	const int N = A.size();
	map<int, int> m;
	/* Do Grid Compression such that
	 * m[i] = index of value i in A[]
	 */
	vector<int> B = A;
	sort(B.begin(), B.end());
	for (int i = 0; i < N; ++i)
	{
		m[B[i]] = i;
	}

	vector<segment_tree> trees;	/* trees[j][i] = maximum score starting at i,
	knowing that you have changed direction j times before. */
	for (int i = 0; i < 3; ++i)
	{
		trees.push_back(segment_tree(N));
	}
	for (int i = N - 1; i >= 0; --i)
	{
		const int idx = m[A[i]];
		trees[2].update(idx, 1 + trees[2].query(idx + 1, N - 1));
		trees[1].update(idx, 1 + max(trees[1].query(0, idx - 1), trees[2].query(idx + 1, N - 1)));
		trees[0].update(idx, 1 + max(trees[1].query(0, idx - 1), trees[0].query(idx + 1, N - 1)));
	}
	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		ans = max(ans, trees[0].query(m[A[i]], m[A[i]]));
	}
	return ans;
}

