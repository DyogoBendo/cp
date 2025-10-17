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

int n;
int cnt= 0;
pair<int, int> def = {1e9, -1};

ll query(int m, int l, int r){
    cnt++;
    assert(cnt <= 40);
    ll x;
    cout << m << " " << l << " " << r << endl;
    cin >> x;
    return x;
}

void answer(pair<int, int> ans){
    cout << "! " << ans.first << " " << ans.second << endl;
}

int go_l(){
    int l = 1, r = n + 1;
    while(l < r){
        int m = (r + l) / 2;
        ll original_left = query(1, 1, m);
        ll modified_left = query(2, 1, m);
        if(original_left == modified_left) l = m+1;
        else r = m;
    }
    return l;
}


void solve(){
    cnt = 0;
    cin >> n;

    ll tot = query(1, 1, n);
    ll mod = query(2, 1, n);
    ll range = mod - tot;

    int l = go_l();

    answer({l, l + range - 1});
}


signed main(){
    int t = 1;
    cin >> t;

    while(t--) solve();
}