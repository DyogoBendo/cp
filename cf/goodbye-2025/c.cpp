#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define int long long

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

    int bst = -1e17;

    vector<int> ssum(n+1);
    for(int i = n-1; i>= 0; i--){
        ssum[i] = ssum[i+1] - v[i];
    }

    ll curr = 0;    
    for(int i = 0; i < n; i++){
        // nao vou pegar o i        
        bst = max(bst, curr + ssum[i+1]);
        if(i == 0) curr += v[i];
        else curr += abs(v[i]);        
    }
    cout << bst << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}