#include<bits/stdc++.h>
#define MAX 1010
using namespace std;
int counter_a[128], counter_b[128];
char a[MAX], b[MAX];
inline void count_freq(char * s, int * x){
	for (;*s != '\n'; ++s)
		++x[*s];
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(1)
	{
		*a = *b = 0;
		fgets(a, INT_MAX, stdin);
		fgets(b, INT_MAX, stdin);
		if (*a == 0 || *b == 0) break;
		memset(counter_a, 0, sizeof counter_a);
		memset(counter_b, 0, sizeof counter_b);
		count_freq(a, counter_a);
		count_freq(b, counter_b);
		for (char i = 'a'; i <= 'z'; ++i)
		{
			int x = min(counter_a[i], counter_b[i]);
			while(x--) printf("%c", i);
		}
		printf("\n");
	}
	return 0;
}

