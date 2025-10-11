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
    int n, m;
    cin >> n >> m;    

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    function<pair<unordered_map<int, ll>, unordered_map<int, ll>>(int, int, bool)> calc_half = [&](int l, int r, bool is_left){               
        unordered_map<int, ll> cnt, cnt_helper;

        vector<int> tot, prev;
        tot.push_back(0);
        prev.push_back(0);
        
        for(int i = l; i < r; i++){
            vector<int> tmp;
            for(auto x : prev) tmp.push_back((x + v[i]) % m);

            prev = tot;
            for(auto x : tmp) tot.push_back(x);
        }
        for(auto x : tot) cnt[x]++;        

        if(is_left){
            if(r){
                vector<int> tot2, prev2;            
                tot2.push_back(v[r-1]);
                for(int i = r-2; i >= l; i--){
                    vector<int> tmp;
                    for(auto x : prev2) tmp.push_back((x + v[i]) % m);
    
                    prev2 = tot2;
    
                    for(auto x : tmp) tot2.push_back(x);
                }
                for(auto x : tot2) cnt_helper[x]++;            
            }
        } else{
            vector<int> tot2, prev2;
            tot2.push_back(v[l]);
            for(int i = l + 1; i < r; i++){
                vector<int> tmp;
                for(auto x : prev2) tmp.push_back((x + v[i]) % m);

                prev2 = tot2;

                for(auto x : tmp) tot2.push_back(x);
            }
            for(auto x : tot2) cnt_helper[x]++;
        }        
        return make_pair(cnt, cnt_helper);
    };

    auto l_half = calc_half(0, n/2, true);
    auto r_half = calc_half(n/2, n, false);

    ll ans = 0;    
    for(auto [x, c] : l_half.first){        
        ans += c * r_half.first[(m - x) % m];        
    }    
    for(auto [x, c] : l_half.second){        
        ans -= c*r_half.second[(m-x) % m];
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}