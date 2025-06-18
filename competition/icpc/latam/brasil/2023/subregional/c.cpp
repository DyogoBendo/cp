#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int INF = 2e9;

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    vector<int> values(n);

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;

        x--;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    

    vector<int> ans(n);
    vector<int> lis;

    function<void(int, int)> dfs = [&](int curr, int p){
        int pos = lower_bound(lis.begin(), lis.end(), values[curr]) - lis.begin();
        
        bool added = false;
        int prev;

        if(pos == lis.size()){
            lis.push_back(values[curr]);
            added = true;
        } else{
            prev = lis[pos];
            lis[pos] = values[curr];
        }
        ans[curr] = lis.size();

        for (auto e : tree[curr])
        {
            if(e == p) continue;

            dfs(e, curr);
        }

        if(added) lis.pop_back();
        else lis[pos] = prev;
    };

    dfs(0, 0);

    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}