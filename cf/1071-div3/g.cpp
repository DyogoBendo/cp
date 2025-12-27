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

int query(int a, int b){
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}

void answer(vector<vector<int>> &grid){
    cout << '!' << endl;

    int n = sz(grid);

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++) cout << grid[i][j] << " ";
        cout << endl;
    }    
}

void solve(){
    int n;
    cin >> n;

    int ma = 0, pa = 0;
    for(int i = 2; i <= n*n; i++){
        int dst = query(1, i);
        if(dst > ma) ma = dst, pa = i;
    }

    vector<int> g1(n*n + 1);
    vector<int> candidates;

    for(int i = 1; i <= n*n; i++) if(i != pa){
        g1[i] = query(i, pa);
        if(g1[i] == n-1) candidates.push_back(i);
    }

    int mb = 0, pb = 0;
    for(int i = 1; i < sz(candidates); i++){
        int dst = query(candidates[0], candidates[i]);
        if(dst > mb) mb = dst, pb = candidates[i];
    }

    vector<int> g2(n*n + 1);    

    for(int i = 1; i <= n*n; i++) if(i != pb){
        g2[i] = query(i, pb);        
    }    

    vector<vector<int>> grid(n+1, vector<int>(n+1));    
    for(int i = 1; i <= n*n; i++){ 
        int x = (g1[i] + g2[i] - n + 3) / 2;
        int y = (g1[i] - g2[i] + n + 1) / 2;
        dbg(x, y, i);
        grid[x][y] = i;
    }

    answer(grid);
}


signed main(){    
    int t = 1;
    cin >> t;

    while(t--) solve();
}