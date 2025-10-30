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

const int MAXN = 2100;

int grid[MAXN][MAXN];

void solve(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            grid[i][j] = (c == '#');                        
        }
    }    

    bool possible = true;
    bool first = true;
    int p1 = 0, p2 = 0, r, d;
    for(int i = 0; i < n; i++){
        int tot = 0;
        int adj = 0;
        int c1 = 0, c2 = 0;
        for(int j = 0; j < n; j++){
            if(grid[i][j]){
                c1 = c2;
                c2 = c1;
                tot++;
            } 
            if(j < n - 1 and grid[i][j] and grid[i][j+1]) adj++;
        }
        if(tot > 2) possible = false;
        if(tot == 2 and adj != 1) possible = false;        
        if(tot == 1 and !first){            

        }
        if(tot){
            first = false;
            p1 = c1;
            p2 = c2;
            r = i;            
        } 
        //dbg(i, possible);
    }

    for(int i = 0; i < n; i++){
        int tot = 0;
        int adj = 0;
        for(int j = 0; j < n; j++){
            if(grid[j][i]) tot++;
            if(j < n - 1 and grid[j][i] and grid[j+1][i]) adj++;
        }
        if(tot > 2) possible = false;
        if(tot == 2 and adj != 1) possible = false;
        //dbg(i, possible);
    }

    cout << (possible ? "YES" : "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}