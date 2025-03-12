#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    int n;
    cin >> n;
    vector<int> a;
    vector<int> in(n);
    vector<int> time(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        in[--x] = i;
        a.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        time[--x] = i;
    }
    
    int mx_time = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = a[i];
        
        if(time[curr] < mx_time){
            ans ++;
        }
        mx_time = max(mx_time, time[curr]);

    }
    
    cout << ans << endl;
}

signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}