#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    int pow = 0;

    int tmp = k;
    while(tmp){        
        tmp /= 2;
        pow ++;
    }

    vector<int> ans;

    int current = 1;
    int total = 0;
    
    int i;

    if(n == 1){
        cout << k << endl; return;
    } 
    
    for (i = 0; i < pow - 1; i++)
    {
        total += current;        
        current *= 2;
    }

    int count = 1;
    cout << k - total;

    if(total){
         cout << " " << total;
         count ++;
    }
    

    for (int j = 0 ;j < n - count; j++)
    {
        cout << " " << 0;
    }

    cout << endl;

    
}

signed main(){

    int t;
    cin >> t;
    while(t--) solve();
}