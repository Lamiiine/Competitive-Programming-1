#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	int price[20][21];
	int m, c;		// money, number of garments
	bool x[2][201];	// reachable
	int cur, prev;
	int money;
	while (TC--){
		cur = 1, prev = 0;
		memset(x, 0x00, sizeof x);
		scanf("%d%d", &m, &c);
		for (int i = 0; i < c; i++){
			scanf("%d", &price[i][0]);
			for (int j = 1; j <= price[i][0]; j++)
				scanf("%d", &price[i][j]);
		}
		for (int i = 1; i <= price[0][0]; i++)
			if (m >= price[0][i]) x[0][m-price[0][i]] = true;
		for (int i = 1; i < c; i++)
		{
			memset(x[cur], 0x00, sizeof x[cur]);
			for (int j = 0; j <= m; j++)
			if (x[prev][j]) for (int l = 1; l <= price[i][0]; l++) if (j >= price[i][l])x[cur][j-price[i][l]] = true;
			prev = 1 - (++cur %= 2);
		}
		money = -1;
		for (int i = 0; i <= m; i++) if (x[prev][i]) { money = i; break; }
		if (money == -1) printf("no solution\n");
		else printf("%d\n", m-money);
	}
	return 0;
}