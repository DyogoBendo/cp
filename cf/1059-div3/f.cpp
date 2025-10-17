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

    vector<pair<int, int>> intervals(m);
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;

        intervals[i] = {l, r};
    }

    bool no_overlap = false;
    vector<int> visited(n+1);
    for(int i = 0; i < m; i++){
        auto [l, r] = intervals[i];
        for(int a= l; a <= r; a++) visited[a]++;
    }

    set<int> used;
    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++){
        if(visited[i] == m){
            used.insert(0);
            ans[i] = 0;
            break;
        }
    }

    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}