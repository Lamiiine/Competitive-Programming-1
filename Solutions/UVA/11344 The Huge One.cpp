#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int rem[13];
char s[2010];
inline void compute_rem(void){
	memset(rem, 0, sizeof rem);
	for (char * c = s; *c; ++c)
	{
		for (int i = 1; i <= 12; ++i)
		{
			int & v = rem[i];
			v = ((10 * v) + (*c - '0')) % i;
		}
	}
}
inline bool wonderful(void){
	int n;
	bool flag = true;
	scanf("%d", &n);
	for(int x;n--;){
		scanf("%d", &x);
		if (rem[x]) flag = false;
	}
	return flag;
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		scanf("%s", s);
		compute_rem();
		printf("%s - %s.\n", s, wonderful()? "Wonderful" : "Simple");
	}
	return 0;
}

