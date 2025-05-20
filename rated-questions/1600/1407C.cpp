#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    vector<int> ans(n+1);
    int idx = 1;

    for (int i = 2; i <= n; i++)
    {
        int x, y;        
        cout << "? " << idx << " " << i << endl;
        cout.flush();
        cin >> x;
        cout << "? " << i << " " << idx << endl;
        cout.flush();
        cin >> y;

        if(x > y){
            ans[idx] = x; 
            idx = i;
        } else{
            ans[i] = y;
        }
    }
    ans[idx] = n;

    cout << "! ";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i+1] << " ";
    }
    cout << endl;
    cout.flush();
    cin >> n;    
}


signed main(){    
    int t = 1;    

    while(t--) solve();
}