#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> hunger(n);

    for (int i = 0; i < n; i++)
    {
        cin >> hunger[i];
    }

    bool possible = true;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if(!possible) break;
        if(hunger[i] > hunger[i + 1]){
            if(i % 2 == 0) possible = false;
            else{
                ans += (i + 1) * (hunger[i] - hunger[i + 1]);
            }
        } else if(hunger[i] < hunger[i + 1]){
            if(i == n - 2) possible = false;
            else{
                int diff = hunger[i + 1] - hunger[i];
                hunger[i + 1] = hunger[i];
                hunger[i + 2] -= diff;
                ans += 2*diff;
                if(hunger[i + 2] < 0) possible= false;
            }
        }
    }    
    
    if(possible) cout << ans;
    else cout << -1;
    cout << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t--) solve();
}