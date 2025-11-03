#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> v(n);
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        tot += v[i];
    } 

    vector<ll> dp(tot+1);
    dp[0] = 1;

    sort(v.rbegin(), v.rend());

    for(int i = 0; i < n; i++){        
        for(int j = tot - v[i]; j >= 0; j--){
            if(j <= tot/2){                
                dp[j+v[i]] += dp[j];
            } 
        }
    }
    ll ans = 0;
    for(int i = tot/2 + 1; i <= tot; i++){        
        ans += dp[i];  
    } 
    cout << ans << endl;    
}