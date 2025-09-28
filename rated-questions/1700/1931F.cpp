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

    vector<set<int>> g(n);
    for(int i = 0; i < k; i++){        
        int prev = -1;
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            x--;

            if(j > 1){                
                g[prev].insert(x);
            }
            prev = x;
        }
    }

    vector<int> visited(n);
    bool possible = true;
    function<void(int, int)> dfs = [&](int curr, int p){                
        if(visited[curr] == 2) return;
        if(visited[curr] == 1){
            possible = false;
            return;
        }

        visited[curr] = 1;
        for(auto e : g[curr]) dfs(e, curr);
        
        visited[curr] = 2;
    };

    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i, i);
    }
    
    cout << (possible ? "YES" : "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}