#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<ll> psum(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        psum[i] = psum[i-1] + v[i];        
    }

    auto check = [&](ll pos){        
        int p = pos%n;
        if(p == 0) p = n;
        ll curr = psum[n] - psum[p-1];        
        ll total = psum[n] * ((n*k - pos) / n) + curr;             
        
        return total >= x;
    };

    ll lo = 1, hi = n*k+1;
    while(lo < hi){
        ll mid = (hi - lo) / 2 + lo;        

        if(check(mid)){            
            lo = mid + 1;
        } else{            
            hi = mid;
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