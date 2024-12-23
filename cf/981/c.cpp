#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    int n;
    cin >> n;
 
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
 
    for (int i = n/2 - 2; i >= 0; i--)
    {
        //cout << "i: " << i << " p: " << n - i - 1 << endl;
        if(v[i] == v[i + 1] || v[n - i - 1] == v[n - i - 2]){
            swap(v[i], v[n - i - 1]);
        }
    }
 
    int ans = 0;
    
    //cout << v[0] << " ";
    for (int i = 1; i < n; i++)
    {        
      //  cout << v[i] << " ";
        if(v[i] == v[i - 1]) ans ++;
    }
    //cout << endl;
    
 
    cout << ans << endl;
       
}
 
signed main(){
    int t;
    cin >> t;
    while(t--)solve();
}