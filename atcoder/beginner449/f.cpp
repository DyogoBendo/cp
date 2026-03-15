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
    int H, W, h, w, n;

    cin >> H >> W >> h >> w >> n;

    int X = H - h + 1;
    int Y = W - w + 1;
    int good = Y;

    vector<tuple<int, int, int>> g;
    for(int i = 0; i < n; i++){
        int r, c;
        cin >> r >> c;
        r--;c--;
        g.push_back({r - h + 1, c - w + 1, true});
        g.push_back({r+1, c - w + 1, false});
    }

    sort(g.begin(), g.end());

    multiset<int> ms;
    ms.insert(-w);
    ms.insert(Y);

    auto gap = [&](int x, int y){
        return max(0, y - x - w);
    };

    auto add = [&](int x){
        auto it = ms.lower_bound(x);
        auto r = *it;
        auto l = *prev(it);

        good += gap(l, x) + gap(x, r) - gap(l, r);

        ms.insert(x);
    };

    auto remove = [&](int x){
        auto it = ms.find(x);
        auto l = *prev(it);
        auto r = *next(it);

        good += gap(l, r) - (gap(l, x) + gap(x, r));

        ms.erase(it);
    };

    int lst = 0;
    int i = 0;
    ll ans = 1LL * X * Y;
    while(i < 2*n){
        auto [x, y, _] = g[i];
        int nx = min(x, X);
        if(lst < nx){
            ans -= 1LL * (nx - lst) * (Y - good);
            lst = nx;
        }

        while(i < 2*n and get<0>(g[i]) == x){
            auto [r, c, to_add] = g[i];
            if(to_add) add(c);
            else remove(c);
            i++;
        }
    }

    ans -= 1LL * (X - lst) * (Y - good);

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}