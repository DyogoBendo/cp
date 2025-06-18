#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> v(2, vector<int>(n));

    vector<pair<int, int>> idx(2*n + 1);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            idx[v[i][j]] = {i, j};
        }        
    }

    vector<pair<int, int>> ans;
    for (int curr = 1; curr < 2*n + 1; curr++)
    {
        auto [x, y] = idx[curr];        
                
        while(true){
            int x1 = 0, x2 = 0, bst;
            pair<int, int> m2 = {x == 0 ? 1 : 2, y}, m1 = {3, y+1}, m;            

            if(x > 0){
                x1 = v[x-1][y];                
            }
            if(y > 0){
                x2 = v[x][y-1];
            }                        
            if(x1 > x2){                
                if(x1 > v[x][y]){
                    idx[v[x-1][y]] = {x, y};
                    swap(v[x][y], v[x-1][y]);
                    ans.push_back(m1);
                    x--;
                } else{
                    break;
                }
            } else if(x2 > x1){
                if(x2 > v[x][y]){
                    idx[v[x][y-1]] = {x, y};
                    swap(v[x][y], v[x][y-1]);
                    ans.push_back(m2);
                    y--;
                } else{
                    break;
                }
            } else{
                break;
            }            
        }
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