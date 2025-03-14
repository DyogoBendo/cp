#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    double total = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        int left = i + 1;
        int right = n - i;
        int dst = min({left, right, k, n - k + 1});                

        total += (ll) dst * x;
    }
    
    cout << setprecision(20) << total / (n - k + 1) << endl;
    
}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}