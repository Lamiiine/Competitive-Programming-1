#include <bits/stdc++.h>
using namespace std;

int p, e, i;
inline bool invalid(const int today)
{
	return (today - p) % 23 || (today - e) % 28 || (today - i) % 33;
}
int main()
{
	for(int TC = 1, d; scanf("%d%d%d%d", &p, &e, &i, &d), ~p || ~e || ~i || ~d; ++TC)
		for (int i = d + 1; i - d <= 21252; ++i)
			if (!invalid(i))
				{
					printf("Case %d: the next triple peak occurs in %d days.\n", TC, i - d);
					break;
				}
	return 0;
}

