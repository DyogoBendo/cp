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
    vector<vector<int>> v(3, vector<int>(6));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            cin >> v[i][j];
        }
    }

    ld tot = 0;
    ld fav = 0;
    for(int i = 0; i < 6; i++){
        int x = v[0][i];        
        for(int j = 0; j < 6; j++){
            int y = v[1][j];            
            for(int k = 0; k < 6; k++){
                int z = v[2][k];
                set<int> s;
                s.insert(x);
                s.insert(y);
                s.insert(z);

                if(s.count(4) and s.count(5) and s.count(6)) fav++;
                tot++;
            }
        }
    }

    cout << fixed << setprecision(12) << (fav/tot) << endl;
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}