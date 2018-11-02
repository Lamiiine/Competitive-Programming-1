#include <stdio.h>
#include <iostream>
using namespace std;
int numTwos(int n)
{
    int num = 0;
    int x = n;
    while (x){
        num++;
        x >>= 1;
    }
    return num;
}
typedef long long LL;
int main(){
    int t, n;
    scanf("%d\n", &t);
    LL sum;
    LL sum2;
    int power2;
    while (t--){
        scanf("%d\n", &n);
        sum = LL(LL(n)*LL(n + 1))/2LL;
        power2 = numTwos(n);
        sum2 = 1;
        while (power2--){ sum2 *= 2; }
        sum2--;
        sum -= sum2;
        sum -= sum2;
        cout << sum << '\n';
    }
    return 0;
}