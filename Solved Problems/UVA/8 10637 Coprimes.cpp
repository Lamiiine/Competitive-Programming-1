#include <bits/stdc++.h>
using namespace std;
int s, t;
int arr[35];
inline void rec(int i, int cur){
	if (i == t)
	{
		if (cur == 0)
		for (int j = 0; j < t; ++j)
			printf("%d%c", arr[j], " \n"[j == t - 1]);
	}
	else
		for (int j = i ? arr[i-1] : 1; j <= cur; ++j)
		{
			bool flag = true;
			for (int k = 0; k < i && flag; ++k)
			if (__gcd(arr[k], j) != 1) flag = false;
			if (!flag) continue;
			arr[i] = j;
			rec(i + 1, cur - j);
		}
}
int main() {
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		scanf("%d%d", &s, &t);
		printf("Case %d:\n", tc);
		rec(0, s);
	}
	return 0;
}