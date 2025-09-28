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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n);
    map<vector<int>, int> mp;
    for(int i = 0; i < n; i++){
        vector<int> tmp(k);
        for(int j = 0; j < k; j++) cin >> tmp[j];
        v[i] = tmp;
        mp[tmp] = i+1;
    }

    vector<int> cnt(n);
    set<pair<int, int>> st;

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            vector<int> tmp(k);
            for(int c = 0; c < k; c++){
                if(v[i][c] == v[j][c]) tmp[c] = v[i][c];
                else tmp[c] = (3 - v[i][c] - v[j][c]);
            }   

            int idx = mp[tmp] - 1;
            if(idx >= 0){                
                if(st.count({min({i, j, idx}), max({i, j, idx})})) continue;
                st.insert({min({i, j, idx}), max({i, j, idx})});
                ans += cnt[idx] + cnt[i] + cnt[j];
                cnt[idx]++;
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}