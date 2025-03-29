#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    
    vector<int> psum(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        psum[i+1] = psum[i] + b[i];
    }
    
    vector<int> cnt(n+1, 0);
    vector<int> add(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(psum.begin(), psum.end(), a[i] + psum[i]) - psum.begin() - 1;
        cnt[i]++;
        cnt[j]--;
        add[j] += a[i] - psum[j] + psum[i];
    }

    for (int i = 0; i < n; i++)
    {
        cnt[i+1] += cnt[i];
        cout << cnt[i] * b[i] + add[i] << " ";
    }
    
    cout << endl;    
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}