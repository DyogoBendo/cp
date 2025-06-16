#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

signed main(){
    int n, c;
    cin >> n >> c;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    int curr= 0;
    int ans = -1, mn = 1e15;
    for (int i = 0; i < n; i++)
    {
        curr += v[i];        
        int qtd = curr / c + 1;
        if(qtd + i > n) break;        
        if(qtd < mn){            
            ans = i;
            mn = qtd;
        }
         
        curr = max(0LL, curr - c);
    }

    if(ans == -1) cout << "impossible";
    else cout << ans;
    cout << endl;    
}