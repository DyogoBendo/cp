#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)a.size())
#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> cycle_sz, total_add;

    int curr = k + 1, cnt = 1;
    while(curr <= n && cycle_sz.size() < k){
        cycle_sz.push_back(curr);
        total_add.push_back(cnt);

        cnt *= k;
        cnt++;

        curr *= k;
        curr ++;
    }

    int ans = 0;
    if(cycle_sz.size() == k){
        ans = total_add.back();
        ans += n - cycle_sz.back();
    } else{
        for (int i = cycle_sz.size() - 1; i >= 0; i--)
        {
            ans += n/cycle_sz[i] * total_add[i];
            n = n%cycle_sz[i];
        }
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}