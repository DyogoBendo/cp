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

    vector<vector<int>> grid(11, vector<int>(11));
    
    bool can = true;
    auto placeH = [&](int l, int r, int c){    
        for(int i = 0; i < l; i++){
            if(c + i > 10){
                can = false;
                return;
            } 
            grid[r][c + i]++;
            if(grid[r][c+i] > 1) can = false;
        }
    };

    auto placeV = [&](int l, int r, int c){    
        for(int i = 0; i < l; i++){
            if(r + i > 10){
                can = false;
                return;
            } 
            grid[r+i][c]++;
            if(grid[r+i][c] > 1) can = false;
        }
    };

    for(int i = 0; i < n; i++){
        int d, l, r, c;
        cin >> d >> l >> r >> c;
        if(d == 0) placeH(l, r, c);
        else placeV(l, r, c);
    }    

    cout << (can ? "S" : "N") << endl;
}