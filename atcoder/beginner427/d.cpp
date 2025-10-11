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
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;


    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;        
        g[u].push_back(v);
    }

    vector<vector<int>> dp(n, vector<int> (2*k+1));
    vector<vector<int>> calculated(n, vector<int> (2*k+1));

    function<int(int, int)> go = [&](int v, int moves){        
        if(calculated[v][moves]) return dp[v][moves];

        if(moves == 0){
            calculated[v][moves] = 1;
            return dp[v][moves] = s[v] == 'A';
        }

        if(moves & 1){
            int aliceWin = 1;
            for(auto e : g[v]){
                aliceWin = min(aliceWin, go(e, moves-1));
            }
            calculated[v][moves]= 1;
            return dp[v][moves] = aliceWin;
        } else{
            int aliceWin = 0;
            for(auto e : g[v]){
                aliceWin = max(aliceWin, go(e, moves-1));
            }
            calculated[v][moves]= 1;
            return dp[v][moves] = aliceWin;
        }
    };
    cout << ((go(0, 2*k)) ? "Alice" : "Bob" )<< endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}