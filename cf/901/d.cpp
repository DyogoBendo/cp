#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v;

    for(auto &values : v) cin >> values;

    sort(v.begin(), v.end());

    if(v[0] > 0){
        cout << 0 << endl;
        return;
    }

    int zero_count = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i] == 0) zero_count ++;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}