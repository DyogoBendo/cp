#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()


void solve(){
    int n;
    cin >> n;
    int fst = n+1;
    for (int i=1, x; i<=n; i++){
        cin >> x;
        if ((i&1) == (x&1)) continue;
        fst = min(fst, i);
    }
    cout << n-fst+1 << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}