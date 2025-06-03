#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];        
    }
    
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
        int sz = 1;
        int curr = v[i];
        int j = i + 1;
        while(j < n && v[j] == curr){
            j++;
            sz++;
        } 

        cnt[curr] = max(cnt[curr], sz);
        j--;
        i = j;
    }
    
    int ans = n*n;
    for (int i = 0; i < n + 1; i++)
    {
        if(cnt[i] > 0){            
            ans = min(ans, (n - cnt[i]) * i);
        }
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}