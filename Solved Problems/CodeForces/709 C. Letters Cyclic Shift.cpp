#include <bits/stdc++.h>
using namespace std;
int n;
char s[100100];
inline int first_non_a(int i)
{
	while(i < n && s[i] == 'a')
		++i;
	return i;
}
inline int first_a(int i)
{
	while(i < n && s[i] != 'a')
		++i;
	return i;
}
int main() {
	scanf("%s", s);
	n = strlen(s);
	int start = first_non_a(0);
	if (start == n)
	{
		s[n - 1] = 'z';
		printf("%s", s);
		return 0;
	}
	int end = first_a(start + 1);
	for (int i = start; i < end; ++i)
	{
		--s[i];
	}
	printf("%s", s);
	return 0;
}