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

const int INF = 1e9+7;

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());   

    map<int, vector<int>> mp;
    for(auto [x, y] : v){
        mp[x].push_back(y);
    }

    vector<int> dp(n + 1, INF);
    dp[0] = -1;    

    for(auto [x, vec] : mp){                                
        for(int i = sz(vec) -1; i>=0; i--){
            auto pos = (lower_bound(dp.begin(), dp.end(), vec[i]));
            *pos = vec[i];
        }        
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) if(dp[i] != INF) ans=i;
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}