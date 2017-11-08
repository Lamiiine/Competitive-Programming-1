#include<bits/stdc++.h>
using namespace std;
typedef double ld;
int fact_int[10];
ld fact[10];
ld inv_fact[10];
inline void init_fact(void){
	fact_int[0] = 1;
	for (int i = 1; i < 10; ++i)
		fact_int[i] = i * fact_int[i - 1];
	for (int i = 0; i < 10; ++i)
		fact[i] = fact_int[i];
	for (int i = 0; i < 10; ++i)
		inv_fact[i] = 1.0/fact[i];
}
ld memo[10][370000];
inline void init_memo(void){
	init_fact();
	ld acc[370000];
	for (int j = 1; j < 10; ++j)
	{
		int num = fact_int[j];
		ld counter = inv_fact[j];
		ld * p = memo[j];
		p[0] = 0.0;	// if you are there already, you can't win
		acc[0] = 1.0;
		for (int i = 1; i < num; ++i)
		{
			p[i] = acc[i - 1]*counter;
			acc[i] = acc[i - 1] + p[i];
		}
	}
}
int main(void)
{
	char tmp[10];
	char arr[10];
	init_memo();
	int TC;scanf("%d", &TC);
	for (int x; TC--;){
		scanf("%d", &x);
		int i = 0;
		for (; x; x /= 10, ++i)
			tmp[i] = x % 10;
		for (int j = 0; j < i; ++j)
			arr[j] = tmp[i - 1 - j];
		int counter = 0;
		while(next_permutation(arr, arr + i)) ++counter;
		printf("%1.9lf\n", memo[i][counter]);
	}
}

