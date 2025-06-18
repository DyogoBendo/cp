#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> cnt(26);

    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a'] ++;
    }
    

    bool found = false;
    for (int i = 1; i < n - 1; i++)
    {
        if(cnt[s[i] -'a'] > 1) found = true;
    }
    

    if(found){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}