#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, ans;
    cin >> n;
    string s;
    cin >> s;

    if(n % 2 == 0){        

        int cp[26] = {0}; 
        int ci[26] = {0}; 
        for (int i = 0; i < n; i++)
        {
            if(i % 2 == 0) cp[s[i] - 'a']++;
            else ci[s[i] - 'a']++;
        }


        int be = 0;
        int bo = 0;
        
        for (int i = 0; i < 26; i++)
        {
            be = max(be, cp[i]);
            bo = max(bo, ci[i]);
        }
        
        ans = n - be - bo;

        cout << ans << endl;
    } else{
        vector<vector<int>> pse(n + 1, vector<int>(26, 0));
        vector<vector<int>> pso(n + 1, vector<int>(26, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                pse[i + 1][j] = pse[i][j];
                pso[i + 1][j] = pso[i][j];
            }
            if(i % 2 == 0){
                pse[i+1][s[i] - 'a'] ++;                
            } 
            else{
                pso[i+1][s[i] - 'a'] ++;                
            } 
        }


        ans = 1e9;

        for (int i = 0; i < n; i++)
        {
            int be = 0, bo = 0, se = 0, so = 0;;            

            for (int j = 0; j < 26; j++)
            {
                se = pse[i][j];
                so = pso[i][j];
                
                se += pso[n][j] - pso[i + 1][j];
                so += pse[n][j] - pse[i + 1][j];
                            

                be = max(be, se);
                bo = max(bo, so);
            }            

            ans = min(ans, n - be - bo);            
        }
        
        cout << ans << endl;
    }

    
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}