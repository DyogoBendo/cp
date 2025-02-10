#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int base = 0;

    int current = 0;
    int actions = 0;

    for (int i = 0; i < n; i++)
    {
        int tmp = min((v[i] - base) * (n - i), k - current);
        current += tmp;
        actions += tmp;
        base += (v[i] - base);
        if(current < k){
            actions ++;
        } else{
            break;
        }
    }
    cout << actions << endl;
    
}

signed main(){
    int t;
    cin >> t;
    while(t--)solve();
}