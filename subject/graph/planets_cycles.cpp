#include <bits/stdc++.h>

using namespace std;

vector<int> f;
vector<int> ans;
vector<int> visited;

void solve(int i){    
    int x = i;
    int y = i;
    int conta = 0, conta2 = 0;    
    do
    {                
        visited[x] = 1;
        x = f[x];
        y = f[f[y]];
        conta ++;
    } while (x != y && !visited[x]);

    int c = 0;            
    if(ans[x] != 0){
        y = i;        
        while(ans[y] == 0)
        {
            ans[y] = ans[x] + conta - c;
            y = f[y];
            c ++;
        }        
        return;
    }        

    while(!visited[y]){
        visited[y] = 1;
        conta ++;
        y = f[y];
    }
    y = i;
    while(x != y){
        conta2 ++;        
        x = f[x];
        y = f[y];
    }
        
    int cycle_size = conta - conta2;

    x = i;
    while(ans[x] == 0){
        ans[x] = max(conta, cycle_size);
        conta --;
        x = f[x];
    }
    
}

int main(){
    int n;
    cin >> n;

    f.resize(n);
    ans.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
        f[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        if(ans[i] == 0) solve(i);
    }
    

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    
}