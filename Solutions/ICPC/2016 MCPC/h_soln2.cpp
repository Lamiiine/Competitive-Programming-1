#include<bits/stdc++.h>
#define P(x,y) make_pair(x,y)
using namespace std;
const int MX=(1<<20);
typedef long long ll;
ll squared(ll n){
    ll st = 1 , en = 1e9 , best = 0 , mid;
    while(st <= en){
        mid = (st+en)/2;
        if(mid * mid <= n){
            best = mid;
            st = mid+1;
        }
        else en = mid-1;
    }
    if(best * best == n) return best;
    return 0;
}
ll GCD(ll x , ll y){
    if( x < y ) swap(x , y);
    if( y == 0) return x;
    return GCD(y , x%y);
}
bool is[MX];
vector < ll > primes;
int lim = 1e6;
//////
ll arr[MX];
map < ll , int > cnt;
int small[MX];
int main(){
    freopen("hope.in","rt",stdin);
    for(int j = 2 ; j<=lim;j++){
        if(is[j]) continue;
        primes.push_back(j);
        for(int i = j + j ; i<=lim ; i+=j)
            is[i] = 1;
    }
    int T;
    scanf("%d",&T);
    while(T--){
        cnt.clear();
        int n;
        scanf("%d",&n);
        memset(small , 0 , sizeof(small));
        for(int j=1;j<=n;j++) {
            scanf("%lld",&arr[j]);
            for(auto P : primes){
                while(arr[j]%P==0){
                    small[P]++;
                    arr[j]/=P;
                }
            }
        }
        set < ll > S;
        for(int j=1;j<=n;j++){
            if(arr[j] == 1) continue;
            for(int i=1;i<=n;i++)
                S.insert(GCD(arr[j] , arr[i]));
            int ii = squared(arr[j]);
            if(ii) S.insert(ii);
        }
        S.erase(1);
        for(int j=1;j<=n;j++){
            for(auto D : S){
                ll X = arr[j];
                while(X % D == 0){
                    cnt[D]++;
                    X/=D;
                }
            }
        }
        int ans = *max_element(small , small + MX);
        for(auto pp : cnt)
            ans = max(ans , pp.second);
        cout<<ans<<endl;
    }
}
