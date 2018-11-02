#include<bits/stdc++.h>
using namespace std;
						//   0, 1, 2, 3, 4, 5, 6, 7, 8, 9
const int stick_count[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int digit_count[10];
int n;
char s[100100];
inline void init(void)
{
	memset(digit_count, 0, sizeof digit_count);
}
inline bool enough(const int n, const int m)
{
	if (!n || !m)
		return (!m && !n);
	return (n >= m * 2 && n <= m * 7);
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
#endif
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		scanf("%d%s", &n, s);
		for (int i = 0; i < n; ++i)
			++digit_count[s[i] - '0'];
		int tot_count = 0;
		for (int i = 0; i <= 9; ++i)
			tot_count += digit_count[i] * stick_count[i];
		int i = 0;
		/*
		 * while you can add 9's, add 9's
		 * while you can add 8's, add 8's
		 * and so on...
		 */
		for (int j = 9; j >= 0; --j)
		{
			while(i < n && enough(tot_count - stick_count[j], n - i - 1))
				tot_count -= stick_count[j], s[i++] = '0' + j;
		}

		printf("%s\n", s);
	}
	return 0;
}

