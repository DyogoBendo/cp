#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

int calc(int a, int mod){
    return (a % mod + mod) % mod;
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    map<int, int> ans;

    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i*i <= m; i++)
    {
        if(m % i == 0){            
            ans[i] = 0;
            ans[m/i] = 0;
        }
    }
    
    for (auto [d, _] : ans)
    {
        for (int i = 1; i <= n; i++)
        {
            ans[d] += calc(v[i] - v[i-1], d);
        }        
    }

    while(q--){
        int op;
        cin >> op;

        if(op == 1){
            int i, x;
            cin >> i >> x;            

            for (auto [d, _] : ans)
            {
                ans[d] += calc(x - v[i - 1], d) - calc(v[i] - v[i-1], d);
                if(i < n) ans[d] += calc(v[i + 1] - x, d) - calc(v[i + 1] - v[i], d);
            }
            v[i] = x;
        } else{
            int k;
            cin >> k;
            cout << (ans[__gcd(k, m)] < m ? "YES" : "NO") << endl;
        }
    }
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}