#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;
    string s;
    cin >> s;

    if(n < 3){
        cout << "No" << endl;
        return 0;
    } 

    if(s.substr(n-3) == "tea") cout << "Yes";
    else cout << "No";
    cout << endl;
}