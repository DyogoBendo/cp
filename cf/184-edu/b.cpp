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
    string s;
    cin >> s;
    int n = sz(s);
    vector<vector<int>> g(n+2);
    vector<int> in(n+2);
    vector<int> out(n+2);
    for(int i = 0; i < n; i++){
        if(s[i] != '<'){
            g[i+1].push_back(i+2);
            in[i+2]++;
        } 
        if(s[i] != '>'){
            if(i == 0){
                g[i+1].push_back(n+1);
                in[n+1]++;
            } 
            else{
                g[i+1].push_back(i);
                in[i]++;
            } 
        } 
    }

    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0) q.push({i, 1});
    }

    int tot = 0;
    vector<int> dist(n+2, 0);
    int ans = 0;
    while(!q.empty()){
        auto [curr, d] = q.front(); q.pop();
        tot++;
        dist[curr] = max(dist[curr], d);
        ans = max(ans, d);
        for(auto e : g[curr]){
            in[e]--;
            if(in[e] == 0) q.push({e, d+1});
        }
    }

    if(tot <= n) ans = 0;
    cout << ans-1 << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}