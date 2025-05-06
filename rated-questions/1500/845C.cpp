#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> entries;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        entries.push_back({l, 1});
        entries.push_back({r+1, -1});
    }

    sort(entries.begin(), entries.end());

    int curr = 0;
    bool possible = true;
    for (auto e : entries )
    {
        if(e.second == 1){
            curr ++;
        } else{
            curr -- ;
        }
        if(curr > 2) possible = false;
    }
    
    cout << (possible ? "YES" : "NO") << endl;
    
}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}