#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(abs(a[i] - b[i]));
    }
    
    
    for (int i = 0; i < k1+k2; i++)
    {
        int curr = pq.top(); pq.pop();

        if(curr > 0) curr --;
        else curr++;

        pq.push(curr);
    }
    
    ll ans=  0;
    while(!pq.empty()){
        ll curr = pq.top();pq.pop();
        ans += curr * curr;
    }

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}