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

    vector<int> visited(n+1);
    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        auto x = q.front(); q.pop();
        if(visited[x]) continue;        
        visited[x] = 1;

        for(auto e : g[x]){
            if(!visited[e]) q.push(e);
        }
    }

    int cnt =0;
    for(int i = 0; i <= n; i++) cnt+= visited[i];

    cout << cnt << endl;
}   


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}