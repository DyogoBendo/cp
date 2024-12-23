#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> sight(n);
    vector<int> prefix_max(n);
    vector<int> suffix_max(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sight[i] = x;
        prefix_max[i] = x + i;
        suffix_max[i] = x - i;
    }


    for (int i = 1; i < n; i++)
    {
        prefix_max[i] = max(prefix_max[i - 1], prefix_max[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffix_max[i] = max(suffix_max[i + 1], suffix_max[i]);
    }
    
    int ans = 0;

    for (int i = 1; i < n - 1; i++)
    {        
        ans = max(ans, prefix_max[i - 1] + sight[i] + suffix_max[i + 1]);
    }
    

    cout << ans << endl;
    
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
    
}