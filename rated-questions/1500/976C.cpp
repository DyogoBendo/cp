#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<tuple<int, int, int>> entries;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        entries.push_back({l, -r, i});
    }

    sort(entries.begin(), entries.end());

    int maxr = -1;
    int curr = -1;
    for (auto [l, r, i] : entries)
    {
        r = -r;
        if(r > maxr){
            maxr = r;
            curr = i;
        } else{
            cout << i+1 << " " << curr+1 << endl;
            return;
        }
    }

    cout << -1 << " " << -1 << endl;
        
}


signed main(){
    darvem;
    int t = 1;
    while(t--) solve();
}