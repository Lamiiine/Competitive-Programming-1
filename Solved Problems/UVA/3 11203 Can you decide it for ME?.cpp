#include<stdio.h>
using namespace std;
bool valid(char * s){
	int iE = -1, iM = -1;
	int i;
	for (i = 0; s[i]; ++i)
		switch(s[i]){
		case '?':break;
		case 'M':{
			if (iM != -1) return false;
			iM = i;
			break;
		}
		case 'E':{
			if (iE != -1) return false;
			iE = i;
			break;
		}
		default: return false;
		}
	if (iM == 0) return false;
	if (iE == i - 1) return false;
	int diff = iE - iM;
	if (diff <= 1) return false;
	diff -= 2;
	// y has diff extra '?' symbols
	int j = i - iE - 1 - diff - 1;
	return j == iM;
}
char s[60];
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%s", s);
		if (!valid(s)) printf("no-");
		printf("theorem\n");
	}
}

