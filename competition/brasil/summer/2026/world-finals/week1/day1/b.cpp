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

const ll INF = 1e18;

void solve(){
    int n;
    cin >> n;

    vector<int> vp(n), vq(n);
    vector<vector<ll>> vcost(3, vector<ll>(n+1));
    for(int i = 0; i < n; i++) cin >> vp[i];
    for(int i = 0; i < n; i++) cin >> vq[i];
    for(int i = 0; i < 3; i++) for(int j = 1; j <= n; j++) cin >> vcost[i][j]; 

    vector<int> g(n+1), gi(n+1);

    for(int i = 0; i < n; i++){
        g[vp[i]] = vq[i];
        gi[vq[i]] = vp[i];
    }        
    vector<int> visited(n+1);

    function<ll(int, int, int, vector<ll> dp)> dfs = [&] (int curr, int first, int st, vector<ll> dp){                
        visited[curr] = 1;
        int prox = g[curr];        

        // significa que estamos no último elemento do ciclo, e precisamos fechar
        if(prox == first){            
            ll ans = -INF;
            if(prox == curr) return vcost[1][curr];

            for(int i = 0; i <= 1; i++){            
                int tot = i + (st^1);                
                ans = max(ans, dp[i] + vcost[tot][curr]);                
            }
            return ans;
        }
    
        vector<ll> dp_tmp(2, -INF);
        for(int arrive = 0; arrive <= 1; arrive++){
            if(curr == first and arrive != st) continue;
            for(int leave = 0; leave <= 1; leave++){
                int tot = (leave^1) + arrive;
                dp_tmp[leave] = max(dp[arrive] + vcost[tot][curr], dp_tmp[leave]);
            }
        }
        return dfs(prox, first, st, dp_tmp);
    };

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        ll curr_ans = -INF;
        for(int st = 0; st <= 1; st++){            
            ll tmp = dfs(i, i, st, vector<ll>(2));            
            curr_ans = max(tmp, curr_ans);
        }                
        ans += curr_ans;
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}