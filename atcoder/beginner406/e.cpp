#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const ll MOD = 998244353;
const ll SZ = 63;
#define int long long

ll fat[SZ];
ll inv_fat[SZ];

ll expo(ll x, ll k){
    ll ans = 1;
    while(k){
        if(k&1){
            ans = ans * x % MOD;
        }
        x = x *x % MOD;
        k>>=1;
    }
    return ans;
}

ll inv(ll x){
    return expo(x, MOD-2);
}

ll comb(ll n, ll k){
    if(n < k) return 0;
    if(k < 0) return 0;
    return fat[n] * (inv_fat[k] * inv_fat[n-k] % MOD) % MOD;
}

int add(int x, int y){
    return (x+y) % MOD;
}
int sub(int x, int y){
    return (x-y+MOD) %MOD;
}

void init(){
    fat[0] = 1;
    for (ll i = 1; i < SZ; i++)
    {
        fat[i] = fat[i-1] * i % MOD;
    }

    inv_fat[SZ-1] = inv(fat[SZ-1]);
    for (ll i = SZ-1 ; i >0 ; i--)
    {
        inv_fat[i-1] = inv_fat[i] * (i) % MOD;
    }    
}

void solve(){
    ll n, k;
    cin >> n >> k;

    stack<ll> st;

    for (int i = 0; i < SZ; i++)
    {
        if(n & (1LL<<i)){            
            st.push(i);
        } 
    }
    
    ll cnt = 0, ans = 0, sum = 0;
    while(!st.empty()){
        ll curr= st.top(); st.pop();        
        if(cnt <= k){
            ans = add(ans, sub(expo(2, curr), 1) * comb(curr-1, k - cnt-1) % MOD);                   
            ans = add(ans, (sum * comb(curr, k - cnt) % MOD));        
        }
        cnt++;
        sum = add(sum, expo(2, curr));
    }
    if(cnt == k) ans = add(ans, sum);        

    cout << ans << endl;
}


signed main(){
    darvem;
    init();
    int t = 1;
    cin >> t;

    while(t--) solve();
}