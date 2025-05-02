#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<vector<int>> ap(k, vector<int>(26));

    for (int i = 0; i < n; i++)
    {
        ap[i%k][s[i]-'a']++;
    }

    int ans= 0;
    for (int i = 0; i < k/2; i++)
    {
        int bst = 0;
        for (int j = 0; j < 26; j++)
        {
            bst = max(bst, ap[i][j] + ap[k-i-1][j]);
        }        
        ans += 2*n/k - bst;
    }
    
    if(k%2){
        int bst = 0;
        for (int j = 0; j < 26; j++)
        {
            bst = max(bst, ap[k/2][j]);
        }
        ans += n/k - bst;
    }
    
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}