#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](pair<int, int> p, pair<int, int> o){
        return p.second < o.second || (p.second == o.second && p.first < o.first);
    });
    
    int l = 0, ans= 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i].first >= l){
            ans ++;
            l = v[i].second;
        }
    }
    
    cout << ans << endl;
}