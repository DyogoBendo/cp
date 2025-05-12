#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MOD = 998244353;
const int MAXK = 1e6+10;
#define int long long

int mul(int a, int b){
    return (1LL) * a * b % MOD;
}

int fast_expo(int x, int k){
    int ans = 1;
    while(k){
        if(k&1){
            ans = mul(ans, x);
        }
        x = mul(x, x);
        k >>= 1;
    }
    return ans;
}

int inv(int x){
    return fast_expo(x, MOD-2);
}

int add(int a, int b){
    return ((0LL) + a + b) % MOD; 
}

void solve(){
    ll n;
    cin >> n;

    vector<int> p(MAXK);
    vector<int> cnt(MAXK);

    for (int i = 0; i < n; i++)
    {
        ll k, tmp;
        cin >> k;

        for (int i = 0; i < k; i++)
        {
            cin >> tmp;
            tmp--;        
            p[tmp] = add(p[tmp], inv(mul(n, k)));
            cnt[tmp]++;
        }        
    }

    int ans = 0;
    for (int i = 0; i < MAXK; i++)
    {                    
        ans = add(ans, mul(p[i], mul(cnt[i], inv(n))));         
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}