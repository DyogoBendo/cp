#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int lst = -1;
    for (int i = 0; i < n; i++)
    {
        if(v[i] != i) break;
        lst ++;
    }
    
    cout << lst + 1 << endl;
    cout.flush();
    

    int x;
    cin >> x;
    while(x != -1){
        cout << x << endl;
        cout.flush();

        cin >> x;
    }
}

signed main(){
    int t;
    cin >> t;

    while(t--) solve();
}