#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

int calc_pairs(int x){
    return ((x * x) - x) / 2;
}


void solve(){
    int k;

    cin >> k;

    int start_x = 0;
    int start_y = 0;

    vector<pair<int, int>> ans;
    while(k){
        int x = 0;
        while(calc_pairs(x) <= k) x++;
        x--;        
        k -= calc_pairs(x);

        for (int i = 0; i < x; i++)
        {
            ans.push_back({start_x + i, start_y});
        }
        start_x += x;
        start_y++;
    }

    cout << ans.size() << endl;
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