#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '1') cnt1 ++;
    }

    if(cnt1 <= k){
        cout << "Alice" << endl;
        return;
    }

    if(k + k - 1 >= n){
        cout << "Alice" << endl;
    } else{
        cout << "Bob" << endl;
    }
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}