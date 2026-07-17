#include <bits/stdc++.h>
using namespace std;

signed main(){
    string s;
    cin >> s;

    vector<int> cnt(26);
    for (auto &x : s) cnt[x - 'a']++;

    int imp = 0;
    for (int i = 0; i < 26; i++)
    {
        if(cnt[i]%2 == 1) imp++;
    }
    

    cout << (imp > 1 ? "no" : "yes");
    cout << '\n';
}