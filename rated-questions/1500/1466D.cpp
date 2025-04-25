#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    cin >> n;

    vector<int> ws(n);
    vector<int> degrees(n, 0);
    
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ws[i];        
        curr += ws[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;v--;
        degrees[u]++;
        degrees[v]++;
    }

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({ws[i], degrees[i]});
    }
    
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for (int i = 0; i < n; i++)
    {
        while(v[i].second > 1){            
            cout << curr << " ";
            curr += v[i].first;
            v[i].second--;
        }
    }
    cout << curr;

    cout << endl;

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}