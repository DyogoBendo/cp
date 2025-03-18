#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, x;
    cin >> n >> x;

    int first_non = 0;

    int x2 = x;

    while(x2 % 2){        
        first_non++;
        x2/=2;
    }    
    int max_mex = (1 << first_non) - 1;    
    
    int curr = 0;    

    vector<int> ans;
    for (int i = 0; i <= min(max_mex, n - 1); i++)
    {
        curr |= i;
        ans.push_back(i);
    }
    
    if(curr != x){        
        if(ans.size() == n) ans.pop_back();
        ans.push_back(x);
    }

    while(ans.size() < n){
        ans.push_back(0);
    }
    
    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}