#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main () {
    ll n;

    cin >> n;
    vector<pair<string,string>> names(n);
    
    for (ll i = 0; i < n; i++){
        cin >> names[i].second;
        cin >> names[i].first;
    }

    sort(names.begin(), names.end());

    for (ll i = 0; i < n; i++){
        cout << names[i].second << " " << names[i].first << endl;
    }
}