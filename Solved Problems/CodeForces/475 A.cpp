// TRIVIAL PROBLEM!
#include<stdio.h>
using namespace std;
int main(){
	int k;
	scanf("%d", &k);
	bool arr[3][11] = { 0 };
	bool flag = false;
	if (k >= 3) { --k; flag = true; }
	for (int i = 0; k && i < 11; ++i)
		for (int j = 0; k && j < 3; ++j)
			arr[j][i] = true, --k;
	/*
	+------------------------+
	|O.O.O.#.#.#.#.#.#.#.#.|D|)
	|O.O.O.#.#.#.#.#.#.#.#.|.|
	|O.......................|
	|O.O.#.#.#.#.#.#.#.#.#.|.|)
	+------------------------+
	*/
		char suff[3][10] = { "|D|)\n" , "|.|\n", "|.|)\n"};

	printf("+------------------------+\n");
	for (int j = 0; j < 3; ++j){
		printf("|");
		for (int i = 0; i < 11; ++i)
			printf("%c.", arr[j][i] ? 'O' : '#');
		printf("%s", suff[j]);
		if (j == 1) printf("|%c.......................|\n", flag ? 'O' : '#');
	}

	printf("+------------------------+\n");
}