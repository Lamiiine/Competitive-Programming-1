#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 205 , MX = 205;
const ll inf = (1ll<<62);
struct matrix{
    int n;
    ll arr[MAXN][MAXN];
    matrix(){}
    matrix(int x , ll V=0){
        n = x;
        for(int j=0;j<n;j++)
            for(int i=0;i<n;i++)
                arr[j][i] = V;
    }
    matrix operator * (matrix &mat){
        matrix res(n , inf);
        for(int j=0;j<n;j++)
            for(int i=0;i<n;i++)
                for(int k=0;k<n;k++)
                    if(arr[i][j] != inf && mat.arr[j][k] != inf)
                        res.arr[i][k] = min(res.arr[i][k] , arr[i][j] + mat.arr[j][k]);
        return res;
    }
    matrix power(long long K){
        matrix res(n , inf) , b(n , inf);
        for(int j=0;j<n;j++) res.arr[j][j] = 0;
        b = (*this);
        while(K>0){
            if( (K&1) )
                res = res * b;
            K/=2;
            b = b * b;
        }
        return res;
    }
}M;
char ccc[1<<18];
int fail[1<<20];
string S[MX];
int kmp (int xx , int yy){
    string str = S[xx] + "#" + S[yy];
    int sz = str.size();
    fail[0] = -1;
    for(int j=1;j<sz;j++){
        fail[j] = -1; int i = fail[j-1];
        while(1){
            if(str[i+1] == str[j]){
                fail[j] = i+1;
                break;
            }
            if(i == -1) break;
            i = fail[i];
        }
    }
    int oo = S[yy].size();
    if(xx == yy)
        return oo - fail[oo-1] - 1;
    else return S[yy].size() - fail[sz-1] - 1;
}
int n , K  , T;
int main(){
    freopen("kool.in", "rt", stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&K);
        for(int j=0;j<n;j++){
            scanf("%s",ccc);
            S[j] = ccc;
        }
        M = matrix(n , inf);
        for(int j=0;j<n;j++)
            for(int i=0;i<n;i++){
                M.arr[j][i] = kmp(j , i);
            }
        M = M.power(K-1);
        ll ans = inf;
        for(int j=0;j<n;j++)
            for(int i=0;i<n;i++)
                ans = min(ans ,  (int) (S[j].size()) + M.arr[j][i]);
        cout<<ans<<endl;
    }
}