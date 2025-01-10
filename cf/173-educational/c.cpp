#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);
    int k = n;
    int z = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
        if(x != -1 && x != 1){
            k = i;
            z = x;
        } 
    }

    int ssum = 0;
    int max_suf = 0;
    int min_suf = 0;
    int max_A = 0;
    int min_A = 0;

    for (int i = k - 1; i >= 0; i--)
    {
        ssum += v[i];   
        max_A = max(max_A, ssum - min_suf);
        min_A = min(min_A, ssum - max_suf);
        max_suf = max(max_suf, ssum);
        min_suf = min(min_suf, ssum);
    }

    int psum = 0;
    int max_pref = 0;
    int min_pref = 0;
    int max_B = 0;
    int min_B = 0;
    for (int i = k + 1; i < n; i++)
    {
        psum += v[i];
        max_B = max(max_B, psum - min_pref);
        min_B = min(min_B, psum - max_pref);

        max_pref = max(max_pref, psum);
        min_pref = min(min_pref, psum);
    }

    set<int> s;

    for (int i = min_B; i <= max_B; i++)
    {
        s.insert(i);
    }
    for (int i = min_A; i <= max_A; i++)
    {
        s.insert(i);
    }
    int min_value = min({min_pref, min_suf, min_pref + min_suf});
    int max_value = max({max_pref, max_suf, max_pref + max_suf});
    for (int i = min_value ; i <= max_value; i++)
    {
        s.insert(z + i);
    }
    
    cout << s.size() << endl;
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}