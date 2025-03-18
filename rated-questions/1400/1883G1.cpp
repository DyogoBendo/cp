#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n-1; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    a[n-1] = 1;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    auto check = [&](int x){
        for (int i = 0; i < n - x; i++)
        {
            if(a[i] >= b[i+x]) return false;
        }
        return true;
    };

    int l = 0, h = 1e5+10;

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
    cin >> t;

    while(t--) solve();
}