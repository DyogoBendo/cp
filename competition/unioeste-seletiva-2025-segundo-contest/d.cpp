#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define int long long
const int INF = 1e18 + 10;

void solve(){
    int n, t;
    cin >> n >> t;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    auto check = [&](int x){
        int curr = 0;

        for (int i = 0; i < n; i++)
        {
            curr += x / v[i];
            if(curr >= t) return true;
        }
        return curr >= t;
    };

    int l = 0, h = INF;
    
    while(l < h){
        int m = (h - l) / 2 + l;

        if(check(m)){
            h = m;
        } else{
            l = m + 1;
        }
    }
    cout << h << endl;
}

signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}