#include<bits/stdc++.h>
#define MAX 100100
using namespace std;
int n, q;
int arr[MAX];
int memo[103][MAX];
map<int, int> get_idx;	// mapping a set to an idnex
map<int, int> get_set;	// mapping an index to a set!
inline void init(void)
{
	memset(memo, 0, sizeof memo);
}
inline void read(void)
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
}
inline void set_memo(void)
{
	for (int i = 0; i < 102; ++i)
	{
		int * cur = memo[i];
		const int s = get_set[i];
		vector<int> v;
		for (int i = 0 ; i < 10; ++i)
			if (s & (1 << i))
				v.push_back(i + 1);
		// v contains the elements of s!
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < v.size(); ++k)
				if (arr[j] % v[k] == 0)
				{
					cur[j] = 1;
					break;
				}
		for (int j = 1; j < n; ++j)
			cur[j] += cur[j - 1];
	}
}
inline int simplify(int s)
{
	for (int j = 1; j < 10; ++j)
		if (s & ( 1 << j))
			for (int i = 0; i < j; ++i)
				if (s & (1 << i))
					if ((j + 1) % (i + 1) == 0)
						s &= (~(1 << j));
	return s;
	vector<int> v;
	for (int i = 0 ; i < 10; ++i)
		if (s & (1 << i))
			v.push_back(i + 1);
	vector<bool> taken;
	taken.resize(v.size());
	for (int i = 0; i < taken.size(); ++i)
		taken[i] = 1;
	for (int i = 0; i < v.size(); ++i)
		for (int j = i + 1; j < v.size(); ++j)
			if (v[j] % v[i] == 0)
				taken[j] = 0;
	vector<int> u;
	for (int i = 0; i < v.size(); ++i)
		if (taken[i])
			u.push_back(v[i]);
	int ans = 0;
	for (int i = 0; i < u.size(); ++i)
		ans |= (1 << (u[i] - 1));
	return ans;
}
inline int valid(const int s)
{
	vector<int> v;
	for (int i = 0 ; i < 10; ++i)
		if (s & (1 << i))
			v.push_back(i + 1);
	for (int i = 0; i < v.size(); ++i)
		for (int j = i + 1; j < v.size(); ++j)
			if (v[j] % v[i] == 0)
				return 0;
	return 1;
}
inline int get_size(void)
{
	int ans = 0;
	for (int i = 1; i <= 1023; ++i)
		if (valid(i))
		{
			get_idx[i] = ans;
			get_set[ans] = i;
			++ans;
		}
	return ans;
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
#endif
	get_size();
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		set_memo();
		for (int l, r, s; q--;)
		{
			scanf("%d%d%d", &l, &r, &s);
			--l, --r;
			s = get_idx[simplify(s)];
			printf("%d\n", memo[s][r] - (l ? memo[s][l - 1] : 0));
		}
	}
	return 0;
}

