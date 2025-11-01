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
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> bst(n, 1e9);
    vector<pair<ll, int>> curr;
    for(int i = 0; i < n; i++){
        while(!curr.empty() and curr.back().first < v[i]) curr.pop_back();
        if(!curr.empty()) bst[i] = i - curr.back().second;
        curr.push_back({v[i], i});
    }

    ll ans = 0;
    curr.clear();
    for(int i = n-1; i >= 0; i--){
        while(!curr.empty() and curr.back().first < v[i]) curr.pop_back();
        if(!curr.empty()) bst[i] = min(curr.back().second - i, bst[i]);
        curr.push_back({v[i], i});
        if(bst[i] != 1e9) ans += bst[i];        
    }
    cout << ans << endl;
}