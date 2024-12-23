#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    long long bigger = max(a, b);
    long long smaller = min(a, b);

    int possible = 1;
    if(c > bigger + 1){
        possible = 0;
    }
    if(c < bigger) possible = 0;

    if(!possible){
        cout << -1 << endl;
        return;
    }
    if(c == bigger + 1){
        long long total = (smaller )
    }
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}