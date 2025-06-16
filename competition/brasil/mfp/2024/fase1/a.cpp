#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n, p;
    cin >> n >> p;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int lo = 0, hi = INT64_MAX;

    auto check = [&](int x){
        int d = 0;
        for (int i = 0; i < n; i++)
        {
            d += x / v[i];
            if(d >= p) return false;
        }
        return d < p;        
    };

    while(lo < hi){
        int mid = (hi - lo) / 2 + lo;

        if(check(mid)){
            lo = mid + 1;
        } else{
            hi = mid;
        }
    }
    
    cout << hi << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}