// https://codeforces.com/contest/1648/problem/A
// matrices
 
#include <bits/stdc++.h>
 
using namespace std;
 
signed main(){
    int n, m;
 
    cin >> n >> m;
 
    map<int, vector<int>> cx;
    map<int, vector<int>> cy;
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int color;
            cin >> color;
            color--;
            cx[color].push_back(i);
            cy[color].push_back(j);
        }        
    }
    
 
    long long ans = 0;
    for (int i = 0; i < cx.size(); i++){        
        sort(cx[i].begin(), cx[i].end());
        sort(cy[i].begin(), cy[i].end());
 
        long long qtdx= cx[i].size();
        vector<long long> cx_sum = vector<long long>(qtdx + 1, 0);                
 
        for (int j = cx[i].size() - 1; j >= 0; j--)
        {            
            cx_sum[j] += cx_sum[j + 1] + cx[i][j];
        }
 
        for (int j = 0; j < cx[i].size(); j++)
        {            
            long long mul = ((qtdx - j - 1) * (cx[i][j]));
            ans += (cx_sum[j + 1]) - mul;
        }
        
 
        long long qtdy = cy[i].size();
        vector<long long> cy_sum = vector<long long>(qtdy + 1, 0);                
 
        for (int j = cy[i].size() - 1; j >= 0; j--)
        {            
            cy_sum[j] += cy_sum[j + 1] + cy[i][j];
        }
 
        for (int j = 0; j < cy[i].size(); j++)
        {            
            long long mul = ((qtdy - j - 1) * (cy[i][j]));
            ans += (cy_sum[j + 1]) - mul;
        }        
    }
    
    cout << ans << endl;
}