#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, s;
    cin >> n >> s;
    
    if(s < n-2){
        cout << "NO" << endl;
        return;
    }

    int x = n-3;
    vector<pair<int, int>> ans;
    ans.push_back({s, 1});
    ans.push_back({x, 1});
    ans.push_back({x, 2});

    int curr = -1;    
    int cnt = 0;
    for (int i = 0; i < x; i++)
    {
        if(i % 2 != 0){
            ans.push_back({x-1-cnt, curr+1});
            curr *= -1;
        } else{
            ans.push_back({x-1-cnt, 1});
            cnt++;
        }        
    }

    cout << "YES" << endl;
    for (auto a : ans)
    {
        cout << a.first << " " << a.second << endl;
    }
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}