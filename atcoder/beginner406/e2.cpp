#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const ll MOD = 998244353;
const ll SZ = 63;
#define int long long

ll c[SZ][SZ];
ll s[SZ][SZ];

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

int add(int x, int y){
    return (x+y) % MOD;
}


void init(){
    for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j < SZ; j++)
        {
            c[i][j] = 0, s[i][j] = 0;
        }        
    }
    c[0][0] = 1;
    for (int i = 0; i < SZ-1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            c[i+1][j+1]=add(c[i][j], c[i+1][j+1]);
			s[i+1][j+1]=add(s[i][j], s[i+1][j+1]);
			s[i+1][j+1]=add((c[i][j]*expo(2, i) % MOD), s[i+1][j+1]);
			c[i+1][j]=add(c[i][j], c[i+1][j]);
			s[i+1][j]=add(s[i][j], s[i+1][j]);
        }
        
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
            ans = add(ans, s[curr][k-cnt]);
            ans = add(ans, sum*c[curr][k-cnt] %MOD);
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