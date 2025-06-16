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

signed main(){
    fastio;
    vector<int> arr(4);
    for (int i=0; i<3; i++) {
        int x;
        cin >> x;
        arr[x] = 1;
    }

    for (int i=1; i<=3; i++) {
        if (!arr[i]) cout << i << '\n';
    }
}