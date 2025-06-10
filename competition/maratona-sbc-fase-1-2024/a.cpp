#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    k -= (n - 1);

    cout << k/n << endl;
}