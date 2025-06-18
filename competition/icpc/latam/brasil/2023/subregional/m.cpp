#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> edges[i][j];
        }        
    }
    
    vector<vector<int>> to_remove(n, vector<int>(n));
    bool possible = true;

    for (int i = 0; i < n; i++)
    {
        vector<int> dst(n, -1);                
        priority_queue<tuple<int, int, int>> pq;
        pq.push({0, i, 0});

        while(!pq.empty()){
            auto [c, idx, steps] = pq.top(); pq.pop();
            c = -c;            
            if(steps > 1 && c == edges[i][idx]) to_remove[i][idx] = true;
            if(steps > 1 && c < edges[i][idx]){
                possible = false;
            } 

            if(dst[idx] != -1){
                continue;
            }             
            dst[idx] = c;            
            
            for (int j = 0; j < n; j++)
            {
                if(i != j && j != idx){
                    pq.push({-(edges[idx][j] + c), j, steps+1});
                }
            }            
        }             

        if(!possible) break;
    }

    if(!possible){
        cout << -1 << endl;
    } else{
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                ans += to_remove[i][j];
            }
            
        }
        
        cout << ans << endl;
    }
    

}