#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            mx = max(mx, v[i][j]);
        }
        
    }

    vector<int> columns(m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(v[i][j] == mx){                
                columns[j] ++;
            }
        }        
    }    


    bool found = false;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;        
        for (int j = 0; j < m; j++)
        {
            if(v[i][j] == mx){                
                columns[j] --;
            }            
            if(columns[j]) cnt++;            
            if(v[i][j] == mx){                
                columns[j] ++;
            }
        }        

        if(cnt <= 1){
            cout << mx -1 << endl;
            found = true;
            break;
        }
    }

    if(!found){
        cout << mx << endl;
    }
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}