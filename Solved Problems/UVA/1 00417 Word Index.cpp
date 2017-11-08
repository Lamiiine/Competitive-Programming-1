#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;
map<string, int> M;
void init(void){
	int counter = 0;
	char s[6] = { 0, 0, 0, 0, 0, 0 };

	for (char i = 'a'; i <= 'z'; ++i)
	{
		s[0] = i; M[s] = ++counter;
	}
	for (char i = 'a'; i <= 'z'; ++i)
	{
		s[0] = i;
		for (char j = i + 1; j <= 'z'; ++j)
			s[1] = j, M[s] = ++counter;
	}
	for (char i = 'a'; i <= 'z'; ++i)
	{
		s[0] = i;
		for (char j = i + 1; j <= 'z'; ++j){
			s[1] = j;
			for (char k = j + 1; k <= 'z'; ++k)
				s[2] = k, M[s] = ++counter;
		}
	}

	for (char i = 'a'; i <= 'z'; ++i)
	{
		s[0] = i;
		for (char j = i + 1; j <= 'z'; ++j){
			s[1] = j;
			for (char k = j + 1; k <= 'z'; ++k){
				s[2] = k;
				for (char l = k + 1; l <= 'z'; ++l)
					s[3] = l, M[s] = ++counter;
			}
		}
	}
	for (char i = 'a'; i <= 'z'; ++i){
		s[0] = i;
		for (char j = i + 1; j <= 'z'; ++j){
			s[1] = j;
			for (char k = j + 1; k <= 'z'; ++k){
				s[2] = k;
				for (char l = k + 1; l <= 'z'; ++l){
					s[3] = l;
					for (char m = l + 1; m <= 'z'; ++m)
						s[4] = m, M[s] = ++counter;
				}
			}
		}
	}
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	init();
	char s[10];
	while (scanf("%s", s) != EOF)
		printf("%d\n", M[s]);
	return 0;
}