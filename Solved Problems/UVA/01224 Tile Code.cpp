#include<bits/stdc++.h>
#define MAX (1 << 5)
using namespace std;
typedef long long int ll;
int n;
ll ans;
ll sym;
int arr[MAX];
inline void rec(const int i)
{
	if (i > n)
	{
		return;
	}

	if (i == n)
	{
		++ans;
		bool flag = true;	// symmetric
		for(int l = 0, r = n - 1; l < r; ++l, --r)
		{
			if (arr[l] != arr[r])
			{
				flag = false;
				break;
			}
		}

		if (flag) ++sym;
		return;
	}

	arr[i] = 0;
	rec(i + 1);
	arr[i] = arr[i + 1] = 1;
	rec(i + 2);
	arr[i] = arr[i + 1] = 2;
	rec(i + 2);
}
int x[MAX] = {1, 1, 3, 3, 8, 12, 27, 45, 96, 176, 363, 693, 1408, 2752, 5547, 10965, 22016, 43776, 87723, 174933, 350208, 699392, 1399467, 2796885, 5595136, 11186176, 22375083, 44741973, 89489408, 178962432, 357935787 };
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d", &n);
		sym = ans = 0LL;
		printf("%d\n", x[n]);
		// rec(0);
		// printf("%lld\n", (ans - sym)/2 + (sym));
	}
	return 0;
}

