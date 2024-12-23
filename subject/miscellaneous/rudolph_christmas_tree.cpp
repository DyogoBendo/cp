#include <bits/stdc++.h>

using namespace std;

#define lld long double

void solve(){
    lld n, d,h;
    cin >> n >> d >> h;

    vector<lld> position(n);

    for(auto &x: position) cin >> x;

    lld ans = n * ((d * h) / 2);

    for (int i = 0; i < n - 1; i++)
    {    
        lld covered_height = max(0.0l, position[i] + h - position[i + 1]);

        ans -= (covered_height * covered_height * d) / (2 * h);
    }

    printf("%.7Lf\n", ans);    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}