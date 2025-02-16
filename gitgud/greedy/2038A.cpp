#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> va(n);
    vector<int> vb(n);
    vector<int> suffix(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> va[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> vb[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int w = va[i] / vb[i];
        suffix[i] = suffix[i + 1] + w;
    }
    

    int curr = k;
    for (int i = 0; i < n; i++)
    {
        int total = suffix[i];
        if(total < curr){
            cout << 0 << " ";
            continue;
        }

        int prox = suffix[i + 1];

        int min_work = max(0, curr - prox);
        cout << min_work << " ";
        curr -= min_work;
    }
    cout << endl;
    
}

signed main(){
    int t;
    t = 1;

    while(t--) solve();
}   