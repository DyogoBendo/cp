#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a)
    {
        cin >> x;
    }
    
    vector<int> b(n, 0);

    int possible = 1;
    for (int i = 0; i < n - 2; i++)
    {
        int current = b[i];        

        if(b[i] > a[i]){
            possible = 0;
            break;
        }

        int missing = a[i] - current;

        b[i] = a[i];
        b[i + 1] = b[i + 1] + (2 * missing);
        b[i + 2] = b[i + 2] + missing;
    }
    

    for (int i = 0; i < n; i++)
    {        
        if(a[i] != b[i]) possible = 0;
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}