#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

void solve(){
    ll n, a, b;
    ll t[7];
    cin >> n >> a >> b;
    for (ll i=1; i<=6; i++) cin >> t[i];
    a--, b--;
    ll d_ccw = (a-b + n) % n;
    ll d_cw = (b-a + n) % n;
    ll m_ccw = min(t[2], t[3]);
    ll m_cw = min(t[1], t[4]);
    ll ans_ccw = min(m_ccw*d_ccw, (d_ccw&1)*m_ccw + d_ccw/2 * t[6]);
    ll ans_cw = min(m_cw*d_cw, (d_cw&1)*m_cw + d_cw/2 * t[5]);
    ll ans = min(ans_ccw, ans_cw);

    ans_ccw = ((d_ccw+1)&1)*m_ccw + (d_ccw+1)/2 * t[6] + m_cw;
    ans_cw = ((d_cw+1)&1)*m_cw + (d_cw+1)/2 * t[5] + m_ccw;

    ans = min({ans, ans_ccw, ans_cw});

    cout << ans << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++) solve();
}