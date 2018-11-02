#include<bits/stdc++.h>
#define MAX 1 << 10
using namespace std;
// this part is only used for simulation; the program does not call these functions!
int grundy[MAX];
inline void simulate(const int k, const int n)
{
	grundy[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		set<int> s;
		for (int j = i - 1; j >= i - k && j >= 0; --j)
			s.insert(grundy[j]);
		for (int j = 0; ; ++j)
			if (s.find(j) == s.end())
			{
				grundy[i] = j;
				break;
			}
	}
}
inline void print(const int n)
{
	for (int i = 0; i <= n; ++i)
		printf("%4d: %d\n", i, grundy[i]);
}
inline int get_grundy(const int i, const int k)
{
	return i % (k + 1);
}
inline void test(const int k, const int n)
{
	simulate(k, n);
	for (int i = 0; i <= n; ++i)
		if (grundy[i] != get_grundy(i, k))
			printf("Error at %d\n", i);
}
int pile[10010];
int k[10010];
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	int TC; scanf("%d", &TC);
	for(int n; TC--;)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", pile + i);
		for (int i = 0; i < n; ++i)
			scanf("%d", k + i);
		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans ^= get_grundy(pile[i], k[i]);
		printf("%s\n", ans ? "Amit" : "Mishra");
	}
	return 0;
}

