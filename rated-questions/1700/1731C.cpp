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
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int mx = 1;
    while(mx < n) mx*=2;
    mx*=2;
    vector<int> occ(mx + 1);
    occ[0] = 1;

    ll curr = 0, tot = 0, remove = 0;
    for(int i = 0; i < n; i++){
        tot += i+1;
        curr ^= v[i];

        for(int k = 0; k*k <= mx; k++){
            int need = (k*k) ^ curr;            
            if(need > mx) continue;
            remove += occ[need];    
        }
        occ[curr]++;
    }

    cout << tot - remove << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}