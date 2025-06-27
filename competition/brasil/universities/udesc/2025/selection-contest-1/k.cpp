#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)((a).size()))

void solve(){
    int n;
    cin >> n;
    vector<int> arr (n);
    for (int i=0; i<n; i++) cin >> arr[i];
    
    map<int, int> bst;
    map<int, int> found;
    vector<int> ans(n + 1, 0);

    for (int i = n-1; i >= 0; i--)
    {
        int curr = arr[i];
        
        if(!found[curr]){
            found[curr] = 1;
            ans[i] = ans[i+1] + 1;
            bst[curr] = ans[i + 1];
        } else{
            ans[i] = bst[curr] + 1;
            bst[curr] = min(bst[curr], ans[i+1]);
        }
    }

    cout << ans[0] << endl;

}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}