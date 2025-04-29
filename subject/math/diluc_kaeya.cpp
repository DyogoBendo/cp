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

    map<pair<int, int>, int> m;

    int d = 0, k = 0;

    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'D')d++;
        else k++;

        int g = gcd(d, k);
        
        cout << ++m[{d/g, k/g}] << " ";
    }
    cout << endl;
}   


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}