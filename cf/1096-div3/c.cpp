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

    vector<int> m2, m3, m6, rst;
    for(int i = 0; i < n; i++){
        if(v[i] % 6 == 0) m6.push_back(v[i]);
        else if(v[i] % 3 == 0) m3.push_back(v[i]);
        else if(v[i] % 2 == 0) m2.push_back(v[i]);
        else rst.push_back(v[i]);
    }

    vector<int> ans(n);

    int l = 0, r = n-1;
    for(int i = 0; i < sz(m6); i++){
        ans[l] = m6[i], l++;
    }

    for(auto x : m2) ans[l++] = x;
    for(auto x : m3) ans[r--] = x;
    for(auto x : rst) ans[l++] = x;

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}