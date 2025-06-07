#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;
    int n;
    cin >> n;
    string t, a;
    cin >> t >> a;

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if(t[i] == a[i] && t[i] == 'o') found = true;
    }

    cout << (found ? "Yes" : "No") << endl;
    
}