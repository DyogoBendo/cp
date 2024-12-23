#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

struct P{
    ll x, y;
};

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

bool is_prime(int x){
    if (x == 1) return false;
    for (int i=2; i*i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    if (n == 3) {
        cout << -1 << '\n';
        return;
    }

    int l=n/2;
    int r=l+1;

    while (is_prime(l) || is_prime(r)){
        l--;
        r++;
    }
    cout << l << ' ' << r << '\n';
}

signed main(){
    fastio;
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        solve();
    }
}