#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n, 0);
    vector<int> b(n, 0);

    int x= 1;
    for (int i = 1; i < n - 1; i++)
    {
        cin >> b[i];

        if(b[i] == 1){
            if(a[i - 1] || a[i]){
                a[i] = x;
                a[i + 1] = x;
            } else{
                x ++;
                a[i - 1] = x;
                a[i] = x;
                a[i + 1] = x;
            }
        }
    }

    bool possible = true;
    for (int i = 1; i < n - 1; i++)
    {
        if(b[i] == 0){
            if(a[i - 1] == a[i] && a[i] == a[i + 1] && a[i] != 0) possible = false; 
        }
    }
    
    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;

}

signed main(){
    int t;
    cin >> t;

    while(t--) solve();
}