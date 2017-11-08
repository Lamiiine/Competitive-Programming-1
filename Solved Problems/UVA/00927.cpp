#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	int TC, degree, c[21], d, k;
	long sum, power;
	int i;
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &degree);
		for (i = 0; i <= degree; i++)
			scanf("%d", &c[i]);
		scanf("%d%d", &d, &k);
		i = 1;
		while ((i*(i + 1)*d) / 2 < k)
			i++;
		sum = 0;
		for (int l = 0; l <= degree; l++){
			power = 1;
			for (int j = 0; j < l; j++)
				power *= i;
			sum += long(c[l])*power;
		}
		cout << sum << '\n';
	}
	return 0;
}