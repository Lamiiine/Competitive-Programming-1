#include<bits/stdc++.h>
using namespace std;
inline int get_grundy(const int i, const int b)
{
	if (b & 1)
		return i & 1;
	const int m = i % (b + 1);
	return (m == b) ? 2 : (m & 1);
}
inline int winner(const vector<int> & v)
{
	int ans = 0;
	for (int i = 0; i < v.size(); ++i)
		ans ^= v[i];
	return ans ? 1 : 2;
}
int main(void)
{
	// freopen("powers.in", "r", stdin);
	int TC; scanf("%d", &TC);
	for(int g; TC--;)
	{
		scanf("%d", &g);
		vector<int> v;
		for(int b, n; g--;)
			scanf("%d%d", &b, &n), v.push_back(get_grundy(n, b));
		printf("%d\n", winner(v));
	}
	return 0;
}

