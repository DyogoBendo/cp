#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    auto check = [&](int x){
        int after = x-1;
        int before = 0;        

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if(v[i].first >= after && v[i].second >= before){
                after--;
                before++;
                cnt++;
            }
            if(cnt == x) return true;
        }
        if(cnt == x) return true;
        return false;
    };

    int lo = 0, hi = n+10;

    while(lo < hi){
        int m = (hi - lo) / 2 + lo;

        if(check(m)){
            lo = m+1;
        } else{
            hi = m;
        }
    }
    cout << hi-1 << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}