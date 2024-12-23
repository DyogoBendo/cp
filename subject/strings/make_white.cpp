#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int l = n + 1;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'B'){
            l = min(l, i);
            r = max(r, i);
        }
    }
    
    cout << r - l + 1 << endl;
    
}

int main(){
    int t;
    cin >> t;

    while(t--) solve();
}