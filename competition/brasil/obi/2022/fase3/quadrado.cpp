#include <bits/stdc++.h>

using namespace std;

const int maxvalue = 1e6;

int n;
int media(int a, int tipo, vector<vector<int>> &v){        
    int s = 0;
    if(tipo == 1){
        for (int i = 0; i < n; i++)
        {
            s += v[i][a];
        }        
    } else{
        for (int i = 0; i < n; i++)
        {
            s += v[a][i];
        }  
    }
    if(s % n) cout << "erro" << endl;
    return s / n;
}

int solve(){
      vector<vector<int>> ans(n, vector<int>(n));    

    int k = 1;
    int s2 = 0;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int s = 0;        

        for (int j = 0; j < n - 1; j++)
        {
            if(j == 0 && i == n - 1){
                while((s2 + k) % n || st.find((s2 + k) / n) == st.end()){
                    k++;                                    
                    if(k > maxvalue){
                        cout << -1 << endl;
                        return 0;
                    }
                } 
            } else if(j == 0)  s2 += k, st.insert(k);
            if(k > maxvalue){
                        cout << -1 << endl;
                        return 0;
                    }
            ans[i][j] = k;
            s += k;            
            k++;
        }

        while((s + k) % n){
          if(k > maxvalue){
                        cout << -1 << endl;
                        return 0;
                    }  
            k++;        
        } 

        ans[i][n - 1] = k;
        k ++;

    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           //cout << ans[i][j] << " ";
        }
        //cout << endl;
        
    }
    
    bool right = true;    
    for (int i = 0; i < n; i++)
    {
        int m = media(i, 0, ans);   

        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if(ans[i][j] == m) found = true;
        }
        
        if(!found) right = false;
    }
    
    
    for (int i = 0; i < n; i++)
    {        
        int m = media(i, 1, ans);   

        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if(ans[j][i] == m) found = true;
        }
        
        if(!found) right = false;
    }

    if(!right) cout << "erro" << endl;
    return 0;
}

int main(){
    //cin >> n;
    for (int i = 0; i < 40; i++)
    {
        n = i + 1;
        cout << "i: " << n << endl;
        solve();
    }
    
}