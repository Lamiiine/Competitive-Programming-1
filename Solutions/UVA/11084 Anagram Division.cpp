#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
char s[15];
int n, d;
inline bool valid(void)
{
	long long int cur = 0LL;
	for (int i = 0; i < n; ++i)
	{
		cur = (ll)cur * 10LL + s[i];
	}
	return (cur % d) == 0;
}
int main() {
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%s%d", s, &d);
		n = strlen(s);
		sort(s, s + n);
		for (int i = 0; i < n; ++i)
		{
			s[i] -= '0';
		}
		int ans = 0;
		do {
			ans += valid();
		} while(next_permutation(s, s + n));
		printf("%d\n", ans);
	}
	return 0;
}
