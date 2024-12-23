#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<int> quantities(100, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;        
        quantities[x - 1] += 1;
    }

    vector<int> amount(k + 1, 0);

    for (int i = 0; i < 100; i++)
    {
        if(quantities[i] == 0) continue;
        if(quantities[i] > k) amount[k] ++;
        else amount[quantities[i]] ++;
    }
    
    
    int coringa = 0;     
    
    for (int i = k, j = 0; i >= 0; i--, j++)
    {
        int possible = 1;
        int total = 0;        
        for (int a = 0; a < amount[i]; a++)
        {                        
            if(coringa - j < 0){
                possible = 0;
                break;
            }
            total ++;
            coringa += (k - j - 1);
        }                
        amount[i] = amount[i] - total;
        if(possible = 0) break;        
        
    }

    int ans = 0;
    for (int i = 0; i <= k; i++)
    {                
        ans += amount[i] * i;
    }    

    ans += min(k - 1, coringa);
    

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--)solve();
}