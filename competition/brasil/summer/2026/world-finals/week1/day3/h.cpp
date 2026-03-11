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
    int n;
    cin >> n;
    
    vector<vector<ll>> sequences(n);           
    vector<vector<ll>> dp(n);
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        sequences[i] = vector<ll>(l);
        dp[i] = vector<ll>(l);
        for(int j = 0; j < l; j++) cin >> sequences[i][j];                
    }
    
    vector<tuple<ll, int, int, int, int>> edges;

    for(int i = 0; i < n; i++){
        int prox = (i+1) % n;

        for(int a = 0; a < sz(sequences[i]); a++){
            int tpreva = (a-1+sz(sequences[i])) % sz(sequences[i]);
            for(int b = 0; b < sz(sequences[prox]); b++){
                
                ll cost = 1LL * sequences[i][tpreva] * sequences[prox][b];
                edges.push_back({cost, i, a, prox, b});
            }
        }
    }

    sort(edges.begin(), edges.end());

    ll latest_value = -1;
        
    vector<tuple<int, int, int>> pending_updates;

    for(auto ed : edges){
        auto [cost, u_seq, u_cut, v_seq, v_cut] = ed;
        
        if(cost != latest_value){            
            for(auto [seq, cut, val] : pending_updates) dp[seq][cut] = max<ll>(dp[seq][cut], val);            
            pending_updates.clear();
            latest_value = cost;
        }
                        
        pending_updates.push_back({v_seq, v_cut, dp[u_seq][u_cut] + 1});
    }
        
    for(auto [seq, cut, val] : pending_updates) dp[seq][cut] = max<ll>(dp[seq][cut], val);    

    vector<int> ans;
    for(int i = 0; i < n; i++){
        bool found = false;
        for(auto x : dp[i]) {            
            if(x >= n - 1) found = true; 
        }

        if(found) ans.push_back(i+1);
    }
    
    cout << sz(ans) << "\n";
    for(auto a : ans) cout << a << " ";
    cout << "\n";
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}