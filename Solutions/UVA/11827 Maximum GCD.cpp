#include<bits/stdc++.h>
using namespace std;
char line[10000];
bool line_empty(){
	for (char * s = line; *s; ++s)
		if (!isspace(*s)) return false;
	return true;
}
int arr[105];
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	for(scanf("%d", &TC); TC--;){
		*line = 0; while(line_empty()) fgets(line, INT_MAX, stdin);
		int counter = 0;
		for (char * s = strtok(line, " \n");s;s = strtok(0, " \n"))
			sscanf(s, "%d", arr + counter++);
		int ans = 1;
		for (int i = 0; i < counter; ++i)
			for (int j = i + 1; j < counter; ++j)
				ans = max(ans, __gcd(arr[i], arr[j]));
		printf("%d\n", ans);
	}
	return 0;
}

