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
    int x, y, z;
    cin >> x >> y >> z;

    vector<int> a(32), b(32), c(32);

    for(int i = 0; i < 31; i++){
        if((x >> i) & 1){
            a[i] = 1;
            b[i] = 1; 
        }
    }

    for(int i = 0; i < 31; i++){
        if((y >> i) & 1){
            b[i] = 1; 
            c[i] = 1;
        }
    }

    for(int i = 0; i < 31; i++){
        if((z >> i) & 1){
            a[i] = 1;
            c[i] = 1; 
        }
    }

    bool possible = true;
    for(int i = 0; i < 31; i++){
        //dbg(i, a[i], b[i], c[i], (x >>i), (y>>i), (z>>i));
        if(a[i] && b[i] && !(x >> i & 1)) possible = false;
        if(b[i] && c[i] && !(y >> i & 1)) possible = false;
        if(a[i] && c[i] && !(z >> i & 1)) possible = false;
    }

    cout << (possible?"YES": "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}