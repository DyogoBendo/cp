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

    int n, q;
    cin >> n >> q;

    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    set<pair<int, int>> s;
    for(int i = 1; i <= n; i++) s.insert({v[i], i});

    while(q--){
        int k;
        cin >> k;

        vector<int> b(k);
        for(int i = 0; i < k; i++) cin >> b[i];

        for(int i = 0; i < k; i++) s.erase({v[b[i]], b[i]});
        cout << s.begin()->first << endl;
        for(int i = 0; i < k; i++) s.insert({v[b[i]], b[i]});
    }
}