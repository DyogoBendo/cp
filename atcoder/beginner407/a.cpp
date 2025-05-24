#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int a, b;
    cin >> a >> b;

    int k = a/b;
    int m = a%b;
    if(m > b/2) k++;

    cout << k << endl;
}