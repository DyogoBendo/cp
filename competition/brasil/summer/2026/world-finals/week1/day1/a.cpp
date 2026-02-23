#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

void solve(){
    int q;
    cin >> q;

    while(q--){
        ll a, b;
        cin >> a >> b;

        cout << (a <= 5 and b >= 5) << endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}