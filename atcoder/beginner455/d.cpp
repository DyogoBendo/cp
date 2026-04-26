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
    int n, q;
    cin >> n >> q;

    vector<int> prev(n+1, -1);
    vector<int> prox(n+1, -1);
    vector<int> pile(n+1);

    iota(pile.begin(), pile.end(), 0);

    while(q--){
        int c, p;
        cin >> c >> p;
        if(prev[c] != -1) prox[prev[c]] = -1;
        prev[c] = p;

        prox[p] = c;        
        pile[c] = pile[p];
    }

    vector<int> ans(n+1, 0);
    vector<int> bots;
    for(int i = 1; i <= n; i++){
        if(prev[i] == -1) bots.push_back(i);
    }

    for(int b: bots){
        int tot = 1;
        int x = b;
        while(prox[x] != -1){
            tot++;
            x = prox[x];
        }

        ans[pile[b]] = tot;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}