#include<bits/stdc++.h>
#define MAX 1000100
typedef long long int ll;
int n;
char s[MAX];
inline void normalize(void){
	int m = n;
	for (char * c = s; m--; ++c)
		*c -= '0';
}
ll a, b;
ll rem_a[MAX];
ll rem_b[MAX];
inline void calc_rem(void){
	rem_a[0] = s[0] % a;
	for (int i = 1; i < n; ++i)
		rem_a[i] = (ll)((ll)rem_a[i - 1] * 10LL + s[i]) % a;
	rem_b[n-1] = s[n-1] % b;
	ll ten = 10LL;
	for (int i = n-2; i >= 0; --i, ten = (ten * 10LL) % b)
		rem_b[i] = (ll)((ll)ten*s[i] + rem_b[i + 1]) % b;
}
inline void denormalize(void){
	for (int i = 0; i < n; ++i)
		s[i] += '0';
}
int main(void){
	scanf("%s", s);
	std::cin >> a >> b;
	n = strlen(s);
	normalize();
	int last_non_zero = n - 1;
	while(last_non_zero && !s[last_non_zero]) --last_non_zero;
	int first_non_zero = 0;
	while(first_non_zero < n && !s[first_non_zero]) ++first_non_zero;
	calc_rem();
	for (int i = first_non_zero; i < last_non_zero; ++i)
		if (!rem_a[i] && !rem_b[i + 1])
		{
			printf("YES\n");
			while(!s[i + 1]) ++i;
			denormalize();
			const char temp = s[i + 1];
			s[i + 1] = 0;
			printf("%s\n", s + first_non_zero);
			s[i + 1] = temp;
			printf("%s\n", s + i + 1);
			return 0;
		}
	printf("NO");
	return 0;
}

