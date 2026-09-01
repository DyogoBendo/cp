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

int n, m;
const int MAX = 1e3 + 10;

vector<string> rotate90(vector<string> &g){
    vector<string> t = g;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        t[m - j - 1][i] = g[i][j];
    }
    return t;
}

vector<string> rotate180(vector<string> &g){
    vector<string> t = g;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        t[n - i - 1][m - j - 1] = g[i][j];
    }
    return t;
}

vector<string> flip1(vector<string>&g){
    vector<string> t = g;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        t[i][m - j - 1] = g[i][j];
    }
    return t;
}

vector<string> flip2(vector<string>&g){
    vector<string> t = g;

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        t[n - i - 1][j] = g[i][j];
    }
    return t;
}

bool check(vector<string> &g, vector<string> t){    
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(g[i][j] != t[i][j]) return false;
    return true;
}

signed main(){
    darvem;

    cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<string>> cand;
    cand.push_back(grid);

    vector<string> r180 = rotate180(grid);
    cand.push_back(r180);
    if(n == m){
        vector<string> r90 = rotate90(grid);
        auto r270 = rotate180(r90);
        cand.push_back(r90);
        cand.push_back(r270);
    }
        
    int ans = 0;
    for(auto x : cand){
        ans += check(grid, x);        
        if(check(grid, flip1(x))) ans++;                    
    }
    
    cout << ans << endl;
}