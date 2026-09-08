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

    int n, m, l;
    cin >> n >> m >> l;
    
    vector<int> light(m);
    for(int i = 0; i < l; i++){
        int x;
        cin >> x;
        x--;
        light[x] = 1;
    }

    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        g[i].resize(k);
        for(int j = 0; j < k; j++) cin >> g[i][j];
    }

    int cnt = l;
    for(int i = 0; i < 2*n; i++){
        int p = i%n;

        for(int j = 0; j < sz(g[p]); j++){            
            light[g[p][j] - 1] ^= 1;
            if(light[g[p][j] - 1]) cnt++;
            else cnt--;
        }               
        if(!cnt){
            cout << i+1 << endl;
            return 0;
        } 
    }

    cout << -1 << endl;
}