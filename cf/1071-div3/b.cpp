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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int tot = 0;
    for(int i = 0; i < n - 1; i++) tot += abs(a[i] - a[i+1]);

    int bst = 0;
    for(int i = 0; i < n; i++){
        int curr = 0;
        if(i > 0){
            curr += abs(a[i-1] - a[i]);
        } 
        if(i < n - 1) curr += abs(a[i] - a[i+1]);
        if(i > 0 and i < n- 1) curr -= abs(a[i-1] - a[i+1]);
        bst = max(bst, curr);
    }
    cout << tot - bst << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}