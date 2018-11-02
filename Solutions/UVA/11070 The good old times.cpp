#include<bits/stdc++.h>
#define MAX 512
using namespace std;
char s[MAX]; int len;
int i;
inline double get_numeral()
{
	int j = i + 1;
	while(j < len && (isdigit(s[j]) || s[j] == '.')) ++j;
	char temp = s[j];
	s[j] = 0;
	double ans;
	sscanf(s + i, "%lf", &ans);
	s[i = j] = temp;
	return ans;
}
// read product
inline double get_term()
{
	double ans = get_numeral();
	while(i < len)
	{
		const char c = s[i];
		if (c == '*')
		{
			++i;
			ans *= get_numeral();
		}
		else if (c == '/')
		{
			++i;
			ans /= get_numeral();
		}
		else break;
	}
	return ans;
}
int main(void)
{
	while(~scanf("%s", s))
	{
		len = strlen(s);
		i = 0;
		double ans = get_term();
		while(i < len)
		{
			const char c = s[i++];
			if (c == '+')
				ans += get_term();
			else if (c == '-') ans -= get_term();
			else break;
		}

		printf("%.3lf\n", ans);
	}
	return 0;
}
/*
1/2/2
-3.0
3
4.0+3.0/5.0
1*2*3+1+1*2+1*2*3*4
 */

