#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    int size[101] = {0};

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        size[a] += 1;
    }    
    
    int ans = 0;

    for (int i = 0; i < 101; i++)
    {
        ans += size[i] / 3;
    }

    cout << ans << endl;
    
}

int main(){

    int t;
    cin >> t;
    while(t--) solve();
}