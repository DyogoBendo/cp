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

    vector<tuple<int, int, int, int>> v;    
    vector<tuple<int, int, int>> events;

    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int l, r, o;
            cin >> l >> r >> o;
            events.push_back({l, 1, sz(v)});
            events.push_back({r, 0, sz(v)});
            v.push_back({i, l, r, o});
        }
    }
    sort(events.begin(), events.end());
    vector<vector<int>> dp(sz(v), vector<int>(1 << n, -1));


    vector<int> ndp((1 << n), -1);    
    ndp[0] = 0;
    for(auto [p, t, idx] : events){        
        if(t == 0){
            for(int mask = 0; mask < (1 << n); mask++) 
                ndp[mask] = max(ndp[mask], dp[idx][mask]);            
        } else{
            auto [i, l, r, o ] = v[idx];
            for(int mask = 0; mask < (1 << n); mask++){
                int msk = mask | (1 << i);                
                dp[idx][mask] = max(dp[idx][mask], ndp[mask]); 
                if(ndp[mask] != -1) dp[idx][msk] = max(dp[idx][msk], ndp[mask] + o);
            }                 
        }        
    }    
    cout << ndp[(1 << n) - 1] << endl;
}