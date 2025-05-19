#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> tree(n);
    
    for (int i = 0; i < n-1; i++)
    {
        int v, u;
        cin >> v >> u;
        v--;u--;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    bool possible = true;
    vector<int> ans;
    function<void(int, int)> dfs= [&](int curr, int p){        
        a[curr]--;
        ans.push_back(curr);    
                
        for (auto e : tree[curr])
        {
            if(e != p){
                dfs(e, curr);                
                a[curr]--;
                ans.push_back(curr);
            }
        }        

        if(a[curr] < 0) possible = false;
        if(a[curr] > 0){
            if(curr == p){
                possible = false;
            } else{
                while(a[curr] > 0){
                    ans.push_back(p);
                    ans.push_back(curr);
                    a[curr]--;
                    a[p]--;
                }
                if(a[p] < 0) possible =false;                
                
            }
        } else if(a[curr] < 0) possible = false;                
    };

    a[0]++;
    dfs(0, 0);

    if(!possible){
        cout << 0 << endl;
    } else{
        for (auto c : ans)
        {
            cout << c+1 << " ";
        }
        cout << endl;        
    }

}