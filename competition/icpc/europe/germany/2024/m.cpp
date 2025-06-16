#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long

signed main(){
    int n;
    cin >> n;
    vector<int> v(n);

    vector<int> diff;
    int total = 0;    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        diff.push_back(i - v[i]);
        total += i - v[i];
    }

    sort(diff.begin(), diff.end());

    int ans = 1e18;
    int curr= 0;
    for (int i = 0; i < n; i++)
    {        
        //cout << "curr: " << curr << " diff: " << diff[i] << " front: " << (total - (n - i) * diff[i]) << " back: " << i*curr << endl;
        ans = min(ans, abs(total - (n - i) * diff[i]) + abs(curr - i * diff[i]));
        // cout << "ans: " << ans << endl;
        curr += diff[i];     
        total -= diff[i];   
    }
    
    cout << ans << endl;
    
}