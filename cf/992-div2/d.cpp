#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> used(2 * n + 1, 0);
    vector<int> ans(n, -1);
    

    set<int> av_even;
    set<int> av_odd;

    for (int i = 0; i < 2*n; i++)
    {
        if(i % 2) av_even.insert(i + 1);
        else av_odd.insert(i + 1);
    }
    

    function<void(int, int, int)> dfs = [&](int curr, int prev, int v){      
        //cout << "curr: " << curr << " prev: " << prev <<  " v: " << v << endl;
        ans[curr] = v;          
        bool vizinho1 = false;
        bool vizinho2 = false;
        
        bool changed = false;    
        for (auto u : graph[curr])
        {
            if(u == prev) continue;            

            int start = 2*n + 1;
            if(v % 2){
                for (auto s : av_odd )
                {
                    if(!used[s] && abs(v - s) != 2 && v - s != 0){
                        start = s;
                        break;
                    } 
                }
                av_odd.erase(start);
            } else{
                for (auto s : av_even )
                {
                    if(!used[s] && abs(v - s) != 2 && v - s != 0){
                        start = s;
                        break;
                    } 
                }
                av_even.erase(start);
            }   
                    
            if(start > 2 *n){
                if(!vizinho1){
                    vizinho1 = true;
                    if(v - 1 > 0 && !used[v - 1]){
                        used[v - 1] = 1;
                        dfs(u, curr, v - 1);
                    } else{
                        vizinho2 = true;
                        if(v + 1 <= 2 * n && !used[v + 1]){
                            used[v + 1] = 1;
                            dfs(u, curr,v + 1);
                        }
                    }
                } else{
                    if(!vizinho2){
                        vizinho2 = true;
                        if(v + 1 <= 2 * n && !used[v + 1]){
                            used[v + 1] = 1;
                            dfs(u, curr,v + 1);
                        }
                    }
                }
            } else{
                used[start] = 1;              
                dfs(u, curr, start);                
            }
        }
        
    };

    used[1] = 1;
    dfs(0, -1, 1);
    
    for (int i = 0; i < n; i++)
    {
        if(ans[i] == -1){
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}