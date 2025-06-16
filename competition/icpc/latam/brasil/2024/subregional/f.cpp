#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;
    int n;
    cin >> n;

    int x = 1, y = 2;
    for (int i = 2; i <= n; i++)
    {
        int tmp = x + y;
        x = y;
        y = tmp;
    }

    cout << x << endl;
    
}