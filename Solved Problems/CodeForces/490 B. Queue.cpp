#include<bits/stdc++.h>
#define MAX (1 << 20)
using namespace std;
char counter[MAX] = { 0 };
bool showed_first[MAX] = { 0 };
int back[MAX] = { 0 };
int n;
int ans[200200];
int f, s;	// first and second
inline void read()
{
	scanf("%d", &n);
	for (int a, b, i = 0; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		++counter[a];
		++counter[b];
		showed_first[a] = 1;
		back[a] = b;
		if (a == 0)
			s = b;
	}
}
inline void find_f()
{
	for (int i = 0; i < MAX; ++i)
		if (counter[i] == 1 && showed_first[i])
			{
				f = i;
				break;
			}
}
int main(void)
{
	read();
	find_f();
	ans[0] = f;
	ans[1] = s;
	for (int i = 0; i + 2 < n; i += 2)
		ans[i + 2] = back[ans[i]];
	for (int i = 1; i + 2 < n; i += 2)
		ans[i + 2] = back[ans[i]];
	for (int i = 0; i < n - 1; ++i)
		printf("%d ", ans[i]);
	printf("%d", ans[n - 1]);
	return 0;
}

