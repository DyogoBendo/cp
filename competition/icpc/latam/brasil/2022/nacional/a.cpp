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

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<vector<int>> gr(n);
    vector<pair<int, int>> g(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        gr[x].push_back(i);
        gr[y].push_back(i);

        g[i] = {x, y};
    }

    
    for(int i = 0; i < n; i++){
        vector<int> visited(n);
        vector<int> cnt(n);
        bool found = false;
        function<void(int)> dfs = [&](int curr){
            if(visited[curr]) return;
            visited[curr] = 1;

            for(auto e : gr[curr]) if(e != i) dfs(e);
        };

        dfs(i);
        for(int j = 0; j < n; j++) cnt[j]+=visited[j], visited[j] = 0;
        
        dfs(g[i].first);
        for(int j = 0; j < n; j++) cnt[j]+=visited[j], visited[j] = 0;        

        dfs(g[i].second);
        for(int j = 0; j < n; j++){            
            cnt[j]+= visited[j];
            if(cnt[j] == 3) found = true;
        } 
        cout << (found?"Y" : "N");
    }
    cout << endl;
    
}