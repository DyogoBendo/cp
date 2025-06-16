#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    while(n){

        vector<int> vc(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vc[i];
        }

        vector<vector<int>> ans(n, vector<int>(n));
        
        if(vc[0] == vc[n - 1]){
            for (int i = 0; i < n; i++)
            {
                ans[0][i] = vc[n-1-i];
                ans[i][0] = vc[i];
                ans[n-1][i] = vc[i];
                ans[i][n-1] = vc[n-1-i];
            }            
        } else{
            int a = -1, b = -1;
            for (int i = 0; i < n; i++)
            {
                if(a == -1 && vc[i] == vc[n-1]) a = i;
                if(vc[i] == vc[0]) b = i;
            }

            if(a > b){
                cout << "No" << endl;
                goto label;
            }

            // fill between
            for (int i = a; i <= b; i++)
            {
                ans[n-1][i] = vc[i];    
                ans[n-i-1][n-1] = vc[i];
                ans[0][n-i-1] = vc[i];
                ans[i][0] = vc[i];
            }

            // fill up A
            for (int i = 1; i < n-b -1; i++)
            {                
                ans[n-i-1][a] = vc[n-i-1];
                ans[a][i] = vc[n-i-1];
                ans[n-a-1][n-i-1] = vc[n-i-1];
                ans[i][n-a-1] = vc[n-i-1];
            }

            //fill up to B
            for (int i = 1; i < a; i++)
            {
                ans[n-i-1][b] = vc[i];
                ans[b][i] = vc[i];
                ans[n-b-1][n-i-1] = vc[i];
                ans[i][n-b-1] = vc[i];
            }                                    
        }

        cout << "Yes" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;            
        }
    
        label: cin >> n;
    }
}