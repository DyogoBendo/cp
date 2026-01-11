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
    int n, w;
    cin >> n >> w;

    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    ll bst = 0;

    vector<ll> cnt(2*w);

    for(int i = 0; i < n; i++){
        cnt[i % (2*w)] += v[i];
    }

    for(int i = 0; i < w; i++){
        bst += cnt[i];
    }

    ll curr = bst;
    for(int i = 1; i < 2*w; i++){
        int remove = (w - i + 2*w) % (2*w);
        int add = 2*w - i;        
        
        curr = (curr - cnt[remove] + cnt[add]);
        bst = min(bst, curr);
    }

    cout << bst << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}