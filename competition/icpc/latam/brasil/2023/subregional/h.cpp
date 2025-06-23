#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define pb push_back

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solution(){
    ll n, val;
    cin >> n >> val;
    multiset<ll> cur;
    vector<tuple<ll, ll, ll>> arr;
    for (int i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({a, b, c});
    }
    sort(all(arr));
    ll ans=0;
    priority_queue<pair<ll, ll>> to_remove, to_add;
    for (auto [a, b, c]: arr){

        while (!to_add.empty()){
            ll x, v;
            tie(x, v) = to_add.top();
            x = -x;
            if (x > a) break;
            cur.insert(v);
            to_add.pop();
        }

        while (!to_remove.empty()){
            ll x, v;
            tie(x, v) = to_remove.top();
            x = -x;
            if (x >= a) break;
            ans = max(ans, v+(x+1)*val);
            cur.erase(cur.find(v));
            to_remove.pop();
        }
        
        ll prev=0;
        if (!cur.empty()) prev = max(prev, *cur.rbegin()+a*val);

        to_add.push({-a, max(prev, ans)-a*val-c});
        to_remove.push({-b, max(prev, ans)-a*val-c});
    }

    while (!to_add.empty()){
        ll x, v;
        tie(x, v) = to_add.top();
        x = -x;
        cur.insert(v);
        to_add.pop();
    }

    while (!to_remove.empty()){
        ll x, v;
        tie(x, v) = to_remove.top();
        x = -x;
        ans = max(ans, v+(x+1)*val);
        cur.erase(cur.find(v));
        to_remove.pop();
    }

    cout << ans << '\n';
}

signed main(){
    fastio;
    int n=1;
    //cin >> n;
    for (int i=0; i<n; i++){
        solution();
    }
}