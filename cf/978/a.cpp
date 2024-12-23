#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

void solve(){
    int n, r;
    cin >> n >> r;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;

    int sobras = 0;
    for (int i = 0; i < n; i++)
    {
        int m = a[i] % 2;
        sobras += m;        
        ans += a[i] - m;        
        r -= (a[i] / 2);
    }

    if(r > sobras) ans += sobras;
    else{
        int total = sobras - r;    

        ans += r - total;
    }

    cout << ans << endl;
}

int main(){
    fastio
    
    int t;
    cin >> t;
    while(t--) solve();
}