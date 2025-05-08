#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, m, q;
    cin >> n >> m;

    vector<pair<int, int>> seg(m);

    for (int i = 0; i < m; i++)
    {
        cin >> seg[i].first >> seg[i].second;
    }

    cin >> q;
    vector<int> upd(q);

    for (int i = 0; i < q; i++)
    {
        cin >> upd[i];
    }
    
    auto check = [&](int x){
        vector<int> v(n);

        for (int i = 0; i < min(x, q); i++)
        {
            v[upd[i] - 1] = 1;
        }

        vector<int> psum(n+1);

        for (int i = 0; i < n; i++)
        {
            psum[i+1] = psum[i] + v[i];
        }

        for (auto s : seg)
        {
            int sz = s.second - s.first + 1;
            int qtd = psum[s.second] - psum[s.first-1];

            
            if(qtd > sz/2){
                return true;
            } 
        }
        
        return false;
    };

    int lo = 0, hi = q+1;

    while(lo < hi){
        int mid = (hi - lo) / 2 + lo;

        if(!check(mid)){
            lo = mid + 1;
        } else{
            hi = mid;
        }
    }

    if(hi == q+1){
        cout << -1 << endl;
    } else{
        cout << hi << endl;
    }
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}