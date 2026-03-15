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
    int n, r, l;
    string s;
    cin >> n >> l >> r >> s;

    vector<queue<int>> v(26);
    vector<queue<int>> delayed(26);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        int c = s[i] - 'a';
        dbg(s[i]);

        while(!delayed[c].empty()){
            int x = delayed[c].front();
            dbg("del", i, c, x);
            if((i - x) >= l){
                v[c].push(x);
                delayed[c].pop();
            } else break;
        }
        while(!v[c].empty()){
            int x = v[c].front();
            dbg("curr", i, c, x);
            if(i - x > r){
                v[c].pop();
            } else break;
        }
        dbg(v[c].size());
        ans += sz(v[c]);
        delayed[c].push(i);
    }

    cout << ans << endl;
}