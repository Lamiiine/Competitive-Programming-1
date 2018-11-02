#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	char s[100005];
	scanf("%s", s);
	int i = 0, m = k;
	char x, y, c;
	while (m > 0 && (c = s[i])){
		if ((x = c - 'a') > (y = 'z' - c)){
			m -= x;
			s[i] = 'a';
		}
		else {
			m -= y;
			s[i] = 'z';
		}
		i++;
	}
	if (m > 0) { printf("-1"); return 0; }
	if (m < 0) { if (s[i - 1] + m >= 'a') s[i - 1] += m; else s[i - 1] -= m; }
	printf("%s", s);
}