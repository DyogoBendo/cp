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
    string a, b;
    cin >> a >> b;        
    
    bool can = true;
    int c0 = 0, c1 = 0;
    int c02 = 0, c12 = 0;
    for(int i = 0; i < n; i+=2){
        if(a[i] == '1') c1++;
        else c0++;
        if(a[i] != b[i]) can = false;
        if(b[i] == '1') c12++;
        else c02++;
    }    
    if((!can and (!c0 or !c1)) or c12 != c1){
        cout << "NO" << endl;
        return;
    }

    can = true;
    c0 = 0, c1 = 0, c12 = 0;
    for(int i = 1; i < n; i+=2){
        if(a[i] == '1') c1++;
        else c0++;
        if(a[i] != b[i]) can = false;
        if(b[i] == '1') c12++;
    }
    if((!can and (!c0 or !c1) )or c1 != c12){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}