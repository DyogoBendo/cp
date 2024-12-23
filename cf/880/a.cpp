#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int v[100] = {0};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[x] += 1;
    }

    int possible = 1;
    for (int i = 1; i < 100; i++)
    {
        if(v[i] > v[i - 1]){
            possible = 0;
        }
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}