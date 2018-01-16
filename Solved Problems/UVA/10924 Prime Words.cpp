#include<bits/stdc++.h>
#define MAX (1 << 11)
using namespace std;
bitset<MAX + 10> bs;
inline void sieve(void)
{
	bs.set();
	bs[0] = 0;
	for (int i = 2; i <= MAX; ++i)
		if (bs[i])
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				bs[j] = 0;
			}
		}
}
char s[100];
inline int value(const char c)
{
	return (c >= 'a' && c <= 'z') ? (int) c - 'a' + 1 : (int) c - 'A' + 27;
}
int main(void)
{
	sieve();
	while(~scanf("%s", s))
	{
		int val = 0;
		for (int i = 0; s[i]; ++i)
		{
			val += value(s[i]);
		}
		printf("%s\n", bs[val] ? "It is a prime word." : "It is not a prime word.");
	}
	return 0;
}

