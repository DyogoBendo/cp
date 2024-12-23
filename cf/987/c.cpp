#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    if(n % 2 && n < 27){
        cout << -1 << endl;
        return;
    }

    if(n % 2 == 0){
        for (int i = 0; i < n; i++)
        {
            cout << (i / 2) + 1 << " ";
        }
        cout << endl;
        
    } else{
        string s = "1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 13 12 12 1 13 ";        
        cout << s;

        for (int i = 27; i < n; i++)
        {   
            cout << ((i - 1)/2) + 1 << " ";
        }
        cout << endl;
        
    }
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}