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

#define int long long

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> s(n);
    vector<int> p(m);
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      s[i] = {x, i};  
    }
    for(int i = 0; i < m; i++) cin >> p[i];

    sort(s.rbegin(), s.rend());

    vector<vector<int>> ans(m);
    vector<int> curr(m);
    for(int i = 0; i < n; i++){
        int k = 0, tot = 0, pos = -1;         
        for(int j = 0; j < m; j++){
            int k2 = p[j];
            int tot2 = curr[j];
            dbg(k, tot, k2, tot2, k2*(tot + s[i].first),  k * (tot2 + s[i].first));
            if(k2*(tot + s[i].first) >=  k * (tot2 + s[i].first)){
                pos = j;
                k = k2;
                tot = tot2;
            }
        }
        dbg(pos);
        ans[pos].push_back(s[i].second+1);
        curr[pos] += s[i].first;
    }
    for(int i = 0; i < m; i++){
        cout << sz(ans[i]);
        for(auto x : ans[i]) cout << " " << x;
        cout << endl;
    }
    
}