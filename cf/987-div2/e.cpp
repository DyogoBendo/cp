#include <bits/stdc++.h>

using namespace std;

int n;
int dfs(vector<vector<int>> &tree, int v, int d){        
    int s = tree[v].size();
    int ans = d;
    vector<int> values;
    
    for (auto c : tree[v])
    {            

        values.push_back(dfs(tree, c, d + 1));        
    }

    sort(values.begin(), values.end());    
    if(s > 2){
        values[0] += (s - 2);
    }
    for (auto x : values)
    {
        ans = max(ans, x);        
    }
        
    return ans;

}

void solve(){
    cin >> n;
    vector<vector<int>> tree(n);

    for (int i = 1; i <= n - 1; i++)
    {
        int p;
        cin >> p;
        tree[--p].push_back(i);
    }

    cout << dfs(tree, 0, 0) << endl;
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}