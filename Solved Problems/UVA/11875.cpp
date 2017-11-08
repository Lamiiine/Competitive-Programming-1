#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define eps 1e-9
using namespace std;
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	int age[15];
	for (int tc = 1; tc <= TC; ++tc){
		printf("Case %d: ", tc);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &age[i]);
		sort(age, age + n);
		printf("%d\n", age[(n >> 1)]);
	}
	return 0;
}

