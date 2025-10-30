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
    int n;
    cin >> n;    

    vector<vector<int>> grid(n, vector<int>(n));

    int tot = 0;
    int l = -1, pos = -1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            grid[i][j] = (c == '#');     
            tot += grid[i][j];  
            
            if(grid[i][j] and l == -1){
                l = i;
                pos = j;
            }
        }
    }   
    
    
    if(tot == 0){
        cout << "YES" << endl;
        return;
    }

    if(tot == 4){        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){                    
                    if(i+1 < n and j+1 < n and grid[i+1][j] and grid[i+1][j+1] and grid[i][j+1]){
                        cout << "YES" << endl;
                        return;
                    }
                }                
            }
        }
    }

    int cnt1 = 0, cnt3 = 0, cnt5 = 0;
    int cnt2 = 0, cnt4 = 0, cnt6 = 0;
    for(int i = l, c = 0; i < n; i++, c++){
        if(pos+c < n) cnt1 += grid[i][pos+c];             
        if(pos+c+1 < n) cnt3 += grid[i][pos+c+1];
        if(pos+c-1 >= 0 and pos+c-1 < n) cnt5 += grid[i][pos+c-1];        

        if(pos - c >= 0) cnt2 += grid[i][pos-c];                  
        if(pos-c+1 >= 0 and pos-c+1 < n) cnt4 += grid[i][pos-c+1];
        if(pos-c-1 >= 0 and pos-c-1 < n) cnt6 += grid[i][pos-c-1];
    }    
    
    dbg(cnt1, cnt2, cnt3, cnt4, cnt5, cnt6, tot);
    if(cnt2 + max(cnt4, cnt6) == tot or cnt1 + max(cnt3, cnt5) == tot){
        cout << "YES" << endl;        
    } else{
        cout << "NO" << endl;
    }
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}