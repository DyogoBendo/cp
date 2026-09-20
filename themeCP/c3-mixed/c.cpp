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

    vector<int> diff(n+1);

    for(int i = 0; i < n; i++){
        int l = v[i] * (i+1);
        int r = l + (i+1);         
        if(l <= n) diff[l]++;
        if(r <= n) diff[r]--;
    }

    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(i) diff[i] += diff[i-1];        
        if(!diff[i]) ans.push_back(i);
    }
    cout << sz(ans) << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}