#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> qtd(n, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        qtd[x] ++;
    }

    int ans = 0;
    int spend = 1;
    for (int i = 0; i < n; i++)
    {        
        if(qtd[i] == 0) break;
        if(qtd[i] == 1 && spend == 0) break;
        if(qtd[i] == 1 && spend == 1){            
            spend --;
            ans ++;
        }       
        if(qtd[i] > 1){
            ans ++;
        }
    }    
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}