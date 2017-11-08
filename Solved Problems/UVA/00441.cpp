#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	//freopen("Input.txt", "r", stdin);
	//freopen("Output.txt", "w", stdout);

	int k;
	int i;
	int x[12];
	bool first = true;
	int counter;
	while (true){
		scanf("%d", &k);
		if (k == 0) return 0;
		if (!first) printf("\n"); else first = false;
		int p[12] = { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
		for (i = 0; i < k; i++) scanf("%d", &x[i]);
		do{
			counter = 0;
			for (i = 0; i < k && counter < 5; i++)
			if (p[i]) printf("%d ", x[i]), counter++;
			while (!p[i]) i++;
			printf("%d\n", x[i]);
		} while (prev_permutation(p, p + k));
	}
}