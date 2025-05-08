#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    int ans=  0;

    auto check = [&](int x){
        for (int i = 0; i < n; i++)
        {
            int curr= x;
            int needed = 0;
            bool possible = false;
            for (int j = i; j < n; j++)
            {
                if(v[j] >= curr){
                    possible = true;
                    break;
                } 
                if(j != n-1){
                    needed += curr - v[j];
                    if(needed > k) break;
                }
                curr--;
            }
            if(needed <= k && possible){
                return true;
            } 
        }
        return false;
    };

    int lo = 0, hi = 1e9;

    while(lo < hi){
        int mid = (hi - lo) / 2 + lo;

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