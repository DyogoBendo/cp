#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

const int MOD = 998244353;

ll mul(ll a, ll b){
    return (1LL) * (a % MOD) * (b % MOD) % MOD;
}

ll pow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = mul(ans, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inv(ll a) {
    return pow(a, MOD-2);
}

int add(int a, int b){
    return ((0LL) + (a % MOD) + (b % MOD)) % MOD; 
}
int sub(int a, int b){
    return ((0LL) + (a % MOD) - (b % MOD) + MOD) % MOD; 
}

signed main(){
    darvem;    
    int t;
    cin >> t;

    queue<pair<int, int>> q;
    int at = 1, bt = 0;
    while(t--){
        int op;
        cin >> op;

        if(op == 0){
            int a, b;
            cin >> a >> b;
            q.push({a, b});
            at = mul(at, a);
            bt = add(mul(bt, a), b);
        } else if(op == 1){
            auto f= q.front(); q.pop();            
            at = mul(at, inv(f.first));
            bt = sub(bt, mul(at, f.second));
            
        } else{
            int x;
            cin >> x;        
            cout << add(mul(x, at), bt) << endl;
        }
    }
}